/*
 * ChugFillForm.cpp
 *
 *  Created on: Dec 4, 2012
 *      Author: gray
 */

#include "ChugFillForm.h"
#include "Constants.h"

#include <QPainter>

ChugFillForm::ChugFillForm(ChugFill choice, QWidget *parent) :
QWidget(parent),
CupDrawer()
{
	setupUi(this);
	_choice = choice;
}


void ChugFillForm::paintEvent(QPaintEvent *e) {
	QPainter p(this);

	int absTop = 10, absLeft = 10;
	int absHeight = height()-20, absWidth = width()-20;
	p.drawRect(absLeft, absTop, absWidth, absHeight);
	p.fillRect(absLeft+1, absTop+1, absWidth-1, absHeight-1, Qt::white);

	double PER_BUFF = .1;
	int glassLeft = absLeft + PER_BUFF*absWidth;
	int glassTop = absTop + PER_BUFF*absHeight;
	int glassWidth = (1 - 2*PER_BUFF)*absWidth;
	int glassHeight = (1 - 2*PER_BUFF)*absHeight;

	drawCup(p, glassTop, glassLeft, glassWidth, glassHeight,
			(_choice==CHUG ? 0.0 : 1.0));

	QFont font = p.font();
	font.setBold(true);
	font.setPixelSize(width()*.25);
	p.setFont(font);

	QString text;
	switch (_choice) {
	case CHUG:
		text = "CHUG";
		break;
	case FILL:
		text = "FILL";
		break;
	default:
		text = "????";
		break;
	}
	p.drawText (absLeft+1, absTop+1, absWidth-1, absHeight-1,
			Qt::AlignHCenter | Qt::AlignVCenter, text );

}





