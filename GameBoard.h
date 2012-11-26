/*
 * GameBoard.h
 *
 *  Created on: Nov 25, 2012
 *      Author: gray
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include "LogoForm.h"
#include "DrinkForm.h"
#include "ScoreForm.h"

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    GameBoard(QWidget *parent = 0);

private:
    LogoForm *_logo;
    DrinkForm *_p1_drink, *_p2_drink;
    ScoreForm *_p1_score, *_p2_score;
};

#endif /* GAMEBOARD_H_ */
