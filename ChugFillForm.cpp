/*
 * ChugFillForm.cpp
 *
 *  Created on: Dec 4, 2012
 *      Author: gray
 */

#include "ChugFillForm.h"
#include "DrinkForm.h"

#include <QPainter>

ChugFillForm::ChugFillForm(ChugFill choice, QWidget *parent) :
QWidget(parent)
{
	setupUi(this);
	_choice = choice;
}


void ChugFillForm::paintEvent(QPaintEvent *e) {
	QPainter p(this);
	p.setPen(QPen(Qt::black, 3));

	int absTop = 30, absLeft = 10;
	int absHeight = height()-40, absWidth = width()-20;
	p.drawRect(absLeft, absTop, absWidth, absHeight);
	p.fillRect(absLeft+1, absTop+1, absWidth-1, absHeight-1, Qt::white);


	double PER_BUFF = .1;
	double PER_TILT_IN = .2;
	double PER_ELL_HALF_HEIGHT = .04;
	double MAX_BEER_PER_FULL = .97;

	int glassLeft = absLeft + PER_BUFF*absWidth;
	int glassTop = absTop + PER_BUFF*absHeight;
	int glassWidth = (1 - 2*PER_BUFF)*absWidth;
	int glassHeight = (1 - 2*PER_BUFF)*absHeight;

	int ellLeft = glassLeft + PER_TILT_IN*glassWidth;
	int ellTop = (glassTop+glassHeight) - PER_ELL_HALF_HEIGHT*glassHeight;
	int ellWidth = (1-2*PER_TILT_IN)*glassWidth;
	int ellHeight = 2*PER_ELL_HALF_HEIGHT*glassHeight;

	p.drawEllipse( ellLeft, ellTop, ellWidth, ellHeight );
	p.drawLine( glassLeft, glassTop, ellLeft, glassTop+glassHeight );
	p.drawLine( glassLeft+glassWidth, glassTop, ellLeft+ellWidth, glassTop+glassHeight );

	// here comes the drink
	if (_choice == CHUG) {
		p.setPen( Qt::NoPen );
		p.setBrush( QBrush(QColor(255, 153, 51)) );

		p.drawEllipse( ellLeft, ellTop, ellWidth, ellHeight );

		QPoint beerBL(ellLeft, glassTop+glassHeight);
		QPoint beerBR(ellLeft+ellWidth, glassTop+glassHeight);

		QPoint glassTL( glassLeft, glassTop );
		QPoint glassTR( glassLeft+glassWidth, glassTop );

		double beerPer = MAX_BEER_PER_FULL;
		QPoint tl = DrinkForm::findPointAlongLine(beerBL, glassTL, beerPer);
		QPoint tr = DrinkForm::findPointAlongLine(beerBR, glassTR, beerPer);

		QPolygon beer;
		beer << beerBL << beerBR << tr << tl;
		p.drawPolygon(beer);

		p.drawEllipse( tl.x(), tl.y()-PER_ELL_HALF_HEIGHT*glassHeight,
				tr.x()-tl.x(), ellHeight );
	}

	p.setBrush( Qt::NoBrush );
	p.setPen(QPen(Qt::black, 3));
	p.drawEllipse( glassLeft, glassTop-PER_ELL_HALF_HEIGHT*glassHeight,
			glassWidth, 2*PER_ELL_HALF_HEIGHT*glassHeight );

	QFont font = p.font();
	font.setBold(true);
	font.setPixelSize(height()-51);
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





