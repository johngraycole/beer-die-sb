/*
 * GameStatus.h
 *
 *  Created on: Nov 25, 2012
 *      Author: gray
 */

#ifndef GAMESTATUS_H_
#define GAMESTATUS_H_

#include "GameUpdateListener.h"

class GameStatus {

public:
	GameStatus();
	GameStatus(const GameStatus &other);

	static GameStatus const INVALID_STATUS;

	GameStatus update(GameUpdate update) const;
	bool operator==(const GameStatus &other);
	bool operator!=(const GameStatus &other);
	void operator=(const GameStatus &other);

	int P1Score() { return _p1score; }
	int P2Score() { return _p2score; }
	int P1Drink() { return _p1drink; }
	int P2Drink() { return _p2drink; }
	int P1OnDrink() { return _p1ondrink; }
	int P2OnDrink() { return _p2ondrink; }

private:
	GameStatus(int score, int drink, int ondrink);

	int _p1score, _p2score;
	int _p1drink, _p2drink;
	int _p1ondrink, _p2ondrink;
};



#endif /* GAMESTATUS_H_ */
