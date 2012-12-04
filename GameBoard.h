/*
 * GameBoard.h
 *
 *  Created on: Nov 25, 2012
 *      Author: gray
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include <boost/thread/mutex.hpp>

#include <QHBoxLayout>

#include <vector>

#include "LogoForm.h"
#include "DrinkForm.h"
#include "ScoreForm.h"
#include "GameStatus.h"
#include "GameUpdateListener.h"

class GameBoard : public QWidget, public GameUpdateListener
{
    Q_OBJECT

public:
    GameBoard(QWidget *parent = 0);

	virtual void OnGameUpdate(GameUpdate update);

protected slots:
	void gameboardtimeout();
	void setGameLayout(bool chug_fill_chug);

private:
	void removeWidgets(QLayout *lay);
	void createWidgets(QLayout *lay);
	void updateWidgets();

	GameUpdate _timeoutUpdate;

    DrinkForm *_p1_drink, *_p2_drink;
    ScoreForm *_p1_score, *_p2_score;
    boost::mutex _mutex;
    std::vector<GameStatus> _old_status;
    GameStatus _currStatus;
};

#endif /* GAMEBOARD_H_ */
