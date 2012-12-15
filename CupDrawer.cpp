/*
 * CupDrawer.cpp
 *
 *  Created on: Dec 15, 2012
 *      Author: gray
 */
#include "CupDrawer.h"
#include "Constants.h"

CupDrawer::CupDrawer()
{
}


void CupDrawer::drawCup(QPainter &p, int top, int left, int width, int height, double perFill) {
	double PER_TILT_IN = .2;
	double PER_ELL_HALF_HEIGHT = .04;
	double MAX_BEER_PER_FULL = .97;

	p.setPen(QPen(Qt::black, PEN_WIDTH));

	int ellLeft = left + PER_TILT_IN*width;
	int ellTop = (top+height) - PER_ELL_HALF_HEIGHT*height;
	int ellWidth = (1-2*PER_TILT_IN)*width;
	int ellHeight = 2*PER_ELL_HALF_HEIGHT*height;

	p.drawEllipse( ellLeft, ellTop, ellWidth, ellHeight );
	p.drawLine( left, top, ellLeft, top+height );
	p.drawLine( left+width, top, ellLeft+ellWidth, top+height );

	// here comes the drink
	if (perFill > 0.0) {
		p.setPen( Qt::NoPen );
		p.setBrush( QBrush(QColor(255, 153, 51)) );

		p.drawEllipse( ellLeft, ellTop, ellWidth, ellHeight );

		QPoint beerBL(ellLeft, top+height);
		QPoint beerBR(ellLeft+ellWidth, top+height);

		QPoint glassTL( left, top );
		QPoint glassTR( left+width, top );

		double beerPer = perFill * MAX_BEER_PER_FULL;
		QPoint tl = findPointAlongLine(beerBL, glassTL, beerPer);
		QPoint tr = findPointAlongLine(beerBR, glassTR, beerPer);

		QPolygon beer;
		beer << beerBL << beerBR << tr << tl;
		p.drawPolygon(beer);

		p.drawEllipse( tl.x(), tl.y()-PER_ELL_HALF_HEIGHT*height,
				tr.x()-tl.x(), ellHeight );
	}

	p.setBrush( Qt::NoBrush );
	p.setPen(QPen(Qt::black, PEN_WIDTH));
	p.drawEllipse( left, top-PER_ELL_HALF_HEIGHT*height,
			width, 2*PER_ELL_HALF_HEIGHT*height );

}

QPoint CupDrawer::findPointAlongLine( QPoint &start, QPoint &end, double per ) {
	QPoint pt;

	int diffx = end.x()-start.x();
	int diffy = end.y()-start.y();

	pt.setX( start.x() + diffx*per );
	pt.setY( start.y() + diffy*per );

	return pt;
}





