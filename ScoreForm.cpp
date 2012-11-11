/*
 * ScoreForm.cpp
 *
 *  Created on: Nov 11, 2012
 *      Author: gray
 */

#include "ScoreForm.h"


ScoreForm::ScoreForm(QWidget *parent) : QWidget(parent) {
	setupUi(this); // this sets up GUI
	_score = 0;
	repaint();
}


void ScoreForm::paintEvent(QPaintEvent *e) {
	cout << "ScoreForm paint()" << endl;

	QPainter p(this);
	p.setPen(QPen(Qt::black, 3));

	p.drawRect(10, 30, width()-20, height()-40);
	p.fillRect(11, 31, width()-21, height()-41, Qt::white);
	QFont font = p.font();
	font.setBold(true);
	font.setPixelSize(height()-51);
	p.setFont(font);
	p.drawText (11, 31, width()-21, height()-41,
			Qt::AlignHCenter | Qt::AlignVCenter,
			"0" );
}




