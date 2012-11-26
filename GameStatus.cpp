#include "GameStatus.h"
#include "Constants.h"

const GameStatus GameStatus::INVALID_STATUS(-1, -1, -1);

GameStatus::GameStatus() {
	_p1score = _p2score = 0;
	_p1drink = _p2drink = FULL_DRINK;
	_p1ondrink = _p2ondrink = MAX_ON_DRINK;
}
GameStatus::GameStatus(const GameStatus &other) {
	operator=( other );
}
GameStatus::GameStatus(int score, int drink, int ondrink) {
	_p1score = score;
	_p2score = score;
	_p1drink = drink;
	_p2drink = drink;
	_p1ondrink = ondrink;
	_p2ondrink = ondrink;
}

GameStatus GameStatus::update(GameUpdate update) const {
	GameStatus gs(*this);

	switch (update) {
	case GU_PLAYER1_SCORE:
		gs._p1score++;
		break;
	case GU_PLAYER1_DRINK:
		gs._p1drink--;
		if (gs._p1drink < EMPTY_DRINK) {
			gs._p1drink = FULL_DRINK;
			gs._p1ondrink = MAX_ON_DRINK;
		}
		break;
	case GU_PLAYER1_PRONATE:
	case GU_PLAYER1_ON_DRINK:
		if (gs._p1ondrink > MIN_ON_DRINK) {
			gs._p1ondrink--;
			if (gs._p1ondrink == MIN_ON_DRINK)
				gs = gs.update(GU_PLAYER1_DRINK);
		}
		break;
	case GU_PLAYER1_SPLASH :
		if (gs._p1drink != EMPTY_DRINK)
			gs._p1drink = FULL_DRINK;
		gs._p1ondrink = MAX_ON_DRINK;
		break;

	case GU_PLAYER2_SCORE:
		gs._p2score++;
		break;
	case GU_PLAYER2_DRINK:
		gs._p2drink--;
		if (gs._p2drink < EMPTY_DRINK) {
			gs._p2drink = FULL_DRINK;
			gs._p2ondrink = MAX_ON_DRINK;
		}
		break;
	case GU_PLAYER2_PRONATE:
	case GU_PLAYER2_ON_DRINK:
		if (gs._p2ondrink > MIN_ON_DRINK) {
			gs._p2ondrink--;
			if (gs._p2ondrink == MIN_ON_DRINK)
				gs = gs.update(GU_PLAYER2_DRINK);
		}
		break;
	case GU_PLAYER2_SPLASH :
		if (gs._p2drink != EMPTY_DRINK)
			gs._p2drink = FULL_DRINK;
		gs._p2ondrink = MAX_ON_DRINK;
		break;

	case GU_RESET :
		gs = GameStatus();
		break;

	default:
		gs = GameStatus::INVALID_STATUS;
		break;
	}

	return gs;
}

bool GameStatus::operator==(const GameStatus &other) {
	bool ans = true;

	ans = ans && (_p1score == other._p1score);
	ans = ans && (_p2score == other._p2score);
	ans = ans && (_p1drink == other._p1drink);
	ans = ans && (_p2drink == other._p2drink);
	ans = ans && (_p1ondrink == other._p1ondrink);
	ans = ans && (_p2ondrink == other._p2ondrink);
	return ans;
}

bool GameStatus::operator!=(const GameStatus &other) {
	return !operator==(other);
}

void GameStatus::operator=(const GameStatus &other) {
	_p1score = other._p1score;
	_p2score = other._p2score;
	_p1drink = other._p1drink;
	_p2drink = other._p2drink;
	_p1ondrink = other._p1ondrink;
	_p2ondrink = other._p2ondrink;
}
