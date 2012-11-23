/*
 * GameUpdateListener.h
 *
 *  Created on: Nov 23, 2012
 *      Author: gray
 */

#ifndef GAMEUPDATELISTENER_H_
#define GAMEUPDATELISTENER_H_

typedef enum game_update_e {
	GU_PLAYER1_SCORE,
	GU_PLAYER1_DRINK,
	GU_PLAYER1_ON_DRINK,
	GU_PLAYER1_SPLASH,
	GU_PLAYER1_PRONATE,

	GU_PLAYER2_SCORE,
	GU_PLAYER2_DRINK,
	GU_PLAYER2_ON_DRINK,
	GU_PLAYER2_SPLASH,
	GU_PLAYER2_PRONATE,

	GU_UNDO_LAST,
	GU_RESET,
	GU_UNKNOWN
} GameUpdate;

class GameUpdateListener {
public:
	virtual void OnGameUpdate(GameUpdate update) = 0;
};

#endif /* GAMEUPDATELISTENER_H_ */
