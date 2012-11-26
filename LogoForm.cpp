/*
 * LogoForm.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: gray
 */

#include "LogoForm.h"

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include <iostream>

using namespace std;

LogoForm::LogoForm(string &image, QWidget *parent) :
QWidget(parent)
{
	setupUi(this);

	_curr_y = height();
	_curr_x = width();

	QPixmap pix(QString::fromStdString(image));
	QGraphicsPixmapItem *gpitem = new QGraphicsPixmapItem(pix);
	QGraphicsScene *scene = new QGraphicsScene(parent);
	scene->addItem(gpitem);
	gvLogo->setScene(scene);
}

void LogoForm::paintEvent(QPaintEvent *e) {
	int h = height(), w = width();
	double scale_y = (double)h / (double)_curr_y;
	double scale_x = (double)w / (double)_curr_x;

	gvLogo->scale(scale_x, scale_y);
	_curr_x = w;
	_curr_y = h;
}

