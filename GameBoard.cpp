/*
 * GameBoard.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: gray
 */

#include <QTimer>

#include "GameBoard.h"
#include "Constants.h"
#include "ChugFillForm.h"

GameBoard::GameBoard(QWidget *parent) :
QWidget(parent),
_mutex(),
_old_status(),
_currStatus()
{
	QHBoxLayout *hbox = new QHBoxLayout(parent);
	createWidgets(hbox);
	setLayout(hbox);
	updateWidgets();
}

void GameBoard::OnGameUpdate(GameUpdate update) {
	_mutex.lock();
	switch (update) {

	case GU_UNDO_LAST:
		if (!_old_status.empty()) {
			_currStatus = _old_status[_old_status.size()-1];
			_old_status.pop_back();
		}
		break;
	case GU_PLAYER1_SPLASH:
		_timeoutUpdate = update;
		QMetaObject::invokeMethod(this,
								  "setGameLayout",
								  Qt::QueuedConnection,
								  Q_ARG(bool, (_currStatus.P1Drink() != EMPTY_DRINK)));
		return;
	default:
		GameStatus gs( _currStatus.update(update) );
		if (gs != GameStatus::INVALID_STATUS) {
			_old_status.push_back(_currStatus);
			_currStatus = gs;
		}
		break;
	}

	if (_old_status.size() > MAX_UNDOS)
		_old_status.erase(_old_status.begin());
	updateWidgets();
	_mutex.unlock();
}

void GameBoard::createWidgets(QLayout *layout) {
	_p1_score = new ScoreForm(this);
	layout->addWidget(_p1_score);
	_p1_drink = new DrinkForm(true, this);
	layout->addWidget(_p1_drink);

	std::string image("logo.png");
	LogoForm *logo = new LogoForm(image, this);
	layout->addWidget(logo);

	_p2_drink = new DrinkForm(false, this);
	layout->addWidget(_p2_drink);
	_p2_score = new ScoreForm(this);
	layout->addWidget(_p2_score);
}

void GameBoard::removeWidgets(QLayout *lay) {
	QLayoutItem* item;
	while ((item = lay->takeAt(0)) != NULL) {
		QWidget *wid;
		if ((wid = item->widget()) != NULL)
			delete wid;
		delete item;
	}
}

void GameBoard::updateWidgets() {
	_p1_score->SetScore( _currStatus.P1Score() );
	_p1_drink->SetDrinkScore( _currStatus.P1Drink() );
	_p1_drink->SetOnDrink( _currStatus.P1OnDrink() );
	_p2_score->SetScore( _currStatus.P2Score() );
	_p2_drink->SetDrinkScore( _currStatus.P2Drink() );
	_p2_drink->SetOnDrink( _currStatus.P2OnDrink() );
}

void GameBoard::setGameLayout(bool chug_fill_chug) {
	removeWidgets(layout());

	if (chug_fill_chug) {
		layout()->addWidget(new ChugFillForm(CHUG, this));
		layout()->addWidget(new ChugFillForm(FILL, this));
		layout()->addWidget(new ChugFillForm(CHUG, this));
	} else {
		layout()->addWidget(new ChugFillForm(FILL, this));
		layout()->addWidget(new ChugFillForm(CHUG, this));
		layout()->addWidget(new ChugFillForm(FILL, this));
	}

	QTimer::singleShot(SPLASH_SCREEN_TIMEOUT_MS, this, SLOT(gameboardtimeout()));
}

void GameBoard::gameboardtimeout() {
	removeWidgets(layout());
	createWidgets(layout());

	GameStatus gs( _currStatus.update(_timeoutUpdate) );
	if (gs != GameStatus::INVALID_STATUS) {
		_old_status.push_back(_currStatus);
		_currStatus = gs;
		if (_old_status.size() > MAX_UNDOS)
			_old_status.erase(_old_status.begin());
	}
	updateWidgets();
	_mutex.unlock();
}
