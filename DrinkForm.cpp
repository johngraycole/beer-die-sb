#include "DrinkForm.h"

#include <QPainter>
#include "Constants.h"

#define FULL_DRINK			5
#define EMPTY_DRINK			0

#define MAX_ON_DRINK		5
#define MIN_ON_DRINK		0

#define PEN_WIDTH			3

using namespace boost;

DrinkForm::DrinkForm(bool glassOnLeft, QWidget *parent) :
QWidget(parent),
_mutex()
{
	setupUi(this);
	_glass_on_left = glassOnLeft;
	_drink_score = FULL_DRINK;
	_on_drink = MAX_ON_DRINK;
}

void DrinkForm::SetDrinkScore(int drink_score) {
	_mutex.lock();
	_drink_score = drink_score;
	_drink_score = MIN(_drink_score, FULL_DRINK);
	_drink_score = MAX(_drink_score, EMPTY_DRINK);
	_mutex.unlock();
	QMetaObject::invokeMethod(this, "repaint", Qt::QueuedConnection);
}

void DrinkForm::SetOnDrink(int on_drink) {
	_mutex.lock();
	_on_drink = on_drink;
	_on_drink = MIN(_on_drink, MAX_ON_DRINK);
	_on_drink = MAX(_on_drink, MIN_ON_DRINK);
	_mutex.unlock();
	QMetaObject::invokeMethod(this, "repaint", Qt::QueuedConnection);
}


void DrinkForm::paintEvent(QPaintEvent *e) {
	QPainter p(this);
	p.setPen(QPen(Qt::black, PEN_WIDTH));

	int absTop = 30, absLeft = 10;
	int absHeight = height()-40, absWidth = width()-20;

	p.drawRect(absLeft, absTop, absWidth, absHeight);
	p.fillRect(absLeft+1, absTop+1, absWidth-1, absHeight-1, Qt::white);

	double PER_BUFF = .1;
	double ON_DRINK_PER_WIDTH = .1;
	double PER_TILT_IN = .2;
	double PER_ELL_HALF_HEIGHT = .04;
	double MAX_BEER_PER_FULL = .97;

	int glassLeft = absLeft + PER_BUFF*absWidth;
	if (!_glass_on_left)
		glassLeft += ON_DRINK_PER_WIDTH*absWidth;
	int glassTop = absTop + PER_BUFF*absHeight;
	int glassWidth = (1 - 2*PER_BUFF - ON_DRINK_PER_WIDTH)*absWidth;
	int glassHeight = (1 - 2*PER_BUFF)*absHeight;

	int ellLeft = glassLeft + PER_TILT_IN*glassWidth;
	int ellTop = (glassTop+glassHeight) - PER_ELL_HALF_HEIGHT*glassHeight;
	int ellWidth = (1-2*PER_TILT_IN)*glassWidth;
	int ellHeight = 2*PER_ELL_HALF_HEIGHT*glassHeight;

	p.drawEllipse( ellLeft, ellTop, ellWidth, ellHeight );
	p.drawLine( glassLeft, glassTop, ellLeft, glassTop+glassHeight );
	p.drawLine( glassLeft+glassWidth, glassTop, ellLeft+ellWidth, glassTop+glassHeight );

	// on drink
	int odLeft = absLeft + PER_BUFF*absWidth;
	if (_glass_on_left)
		odLeft += glassWidth + .5*PER_BUFF*absWidth;
	else
		odLeft -= .5*PER_BUFF*absWidth;
	int odWidth = absWidth*ON_DRINK_PER_WIDTH;
	double odPer = (_on_drink-MIN_ON_DRINK) / (double)(MAX_ON_DRINK-MIN_ON_DRINK);
	int odTop = glassTop + (1.0-odPer)*glassHeight;

	p.fillRect(odLeft, odTop, odWidth, glassTop+glassHeight-odTop, Qt::black);
	QFont font = p.font();
	font.setBold(true);
	font.setPixelSize(PER_BUFF*absHeight);
	p.setFont(font);
	p.drawText (odLeft, glassTop+glassHeight, odWidth, PER_BUFF*absHeight,
			Qt::AlignHCenter | Qt::AlignVCenter,
			QString::number(_on_drink) );

	// here comes the drink
	if (_drink_score > EMPTY_DRINK) {
		p.setPen( Qt::NoPen );
		p.setBrush( QBrush(QColor(255, 153, 51)) );

		p.drawEllipse( ellLeft, ellTop, ellWidth, ellHeight );

		QPoint beerBL(ellLeft, glassTop+glassHeight);
		QPoint beerBR(ellLeft+ellWidth, glassTop+glassHeight);

		QPoint glassTL( glassLeft, glassTop );
		QPoint glassTR( glassLeft+glassWidth, glassTop );

		double beerPer = (_drink_score-EMPTY_DRINK) / (double)(FULL_DRINK-EMPTY_DRINK);
		beerPer *= MAX_BEER_PER_FULL;

		QPoint tl = findPointAlongLine(beerBL, glassTL, beerPer);
		QPoint tr = findPointAlongLine(beerBR, glassTR, beerPer);

		QPolygon beer;
		beer << beerBL << beerBR << tr << tl;
		p.drawPolygon(beer);

		p.drawEllipse( tl.x(), tl.y()-PER_ELL_HALF_HEIGHT*glassHeight,
				tr.x()-tl.x(), ellHeight );
	}

	p.setBrush( Qt::NoBrush );
	p.setPen(QPen(Qt::black, PEN_WIDTH));
	p.drawEllipse( glassLeft, glassTop-PER_ELL_HALF_HEIGHT*glassHeight,
			glassWidth, 2*PER_ELL_HALF_HEIGHT*glassHeight );

}


QPoint DrinkForm::findPointAlongLine( QPoint &start, QPoint &end, double per ) {
	QPoint pt;

	int diffx = end.x()-start.x();
	int diffy = end.y()-start.y();

	pt.setX( start.x() + diffx*per );
	pt.setY( start.y() + diffy*per );

	return pt;
}






