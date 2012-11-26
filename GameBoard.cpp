/*
 * GameBoard.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: gray
 */

#include "GameBoard.h"

#include <QHBoxLayout>

#include "Constants.h"

GameBoard::GameBoard(QWidget *parent) :
QWidget(parent),
_mutex(),
_old_status(),
_currStatus()
{
	QHBoxLayout *hbox = new QHBoxLayout(parent);

	_p1_score = new ScoreForm(parent);
	hbox->addWidget(_p1_score);
	_p1_drink = new DrinkForm(true, parent);
	hbox->addWidget(_p1_drink);

	std::string image("logo.png");
	_logo = new LogoForm(image, parent);
	hbox->addWidget(_logo);

	_p2_drink = new DrinkForm(false, parent);
	hbox->addWidget(_p2_drink);
	_p2_score = new ScoreForm(parent);
	hbox->addWidget(_p2_score);

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

void GameBoard::updateWidgets() {
	_p1_score->SetScore( _currStatus.P1Score() );
	_p1_drink->SetDrinkScore( _currStatus.P1Drink() );
	_p1_drink->SetOnDrink( _currStatus.P1OnDrink() );
	_p2_score->SetScore( _currStatus.P2Score() );
	_p2_drink->SetDrinkScore( _currStatus.P2Drink() );
	_p2_drink->SetOnDrink( _currStatus.P2OnDrink() );
}
