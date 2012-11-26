/*
 * GameBoard.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: gray
 */

#include "GameBoard.h"

#include <QHBoxLayout>

#include <iostream>
using namespace std;

GameBoard::GameBoard(QWidget *parent) :
QWidget(parent)
{
	QHBoxLayout *hbox = new QHBoxLayout(parent);

	_p1_score = new ScoreForm(parent);
	hbox->addWidget(_p1_score);
	_p1_drink = new DrinkForm(true, parent);
	hbox->addWidget(_p1_drink);

	string image("logo.png");
	_logo = new LogoForm(image, parent);
	hbox->addWidget(_logo);

	_p2_drink = new DrinkForm(false, parent);
	hbox->addWidget(_p2_drink);
	_p2_score = new ScoreForm(parent);
	hbox->addWidget(_p2_score);

	setLayout(hbox);
}
