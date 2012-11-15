#include "DrinkForm.h"

#include <QPainter>
#include "Constants.h"

#define FULL_DRINK		5
#define EMPTY_DRINK		0

using namespace boost;

DrinkForm::DrinkForm(QWidget *parent) :
QWidget(parent),
_mutex()
{
	setupUi(this);
	_drink_score = 5;
}

void DrinkForm::SetDrinkScore(int drink_score) {
	_mutex.lock();
	_drink_score = drink_score;
	_drink_score = MIN(_drink_score, FULL_DRINK);
	_drink_score = MAX(_drink_score, EMPTY_DRINK);
	_mutex.unlock();
	QMetaObject::invokeMethod(this, "repaint", Qt::QueuedConnection);
}


void DrinkForm::paintEvent(QPaintEvent *e) {
	QPainter p(this);
	p.setPen(QPen(Qt::black, 3));

	int absTop = 30, absLeft = 10;
	int absHeight = height()-40, absWidth = width()-20;

	p.drawRect(absLeft, absTop, absWidth, absHeight);
	p.fillRect(absLeft+1, absTop+1, absWidth-1, absHeight-1, Qt::white);

	double PER_BUFF = .1;
	double PER_TILT_IN = .2;
	double PER_ELL_HALF_HEIGHT = .1;

	int glassLeft = absLeft + PER_BUFF*absWidth;
	int glassTop = absTop + PER_BUFF*absHeight;
	int glassWidth = (1-2*PER_BUFF)*absWidth;
	int glassHeight = (1-2*PER_BUFF)*absHeight;

	int ellLeft = glassLeft + PER_TILT_IN*glassWidth;
	int ellTop = (glassTop+glassHeight) - PER_ELL_HALF_HEIGHT*glassHeight;
	int ellWidth = (1-2*PER_TILT_IN)*glassWidth;

	p.setPen( Qt::NoPen );
	p.setBrush( QBrush(Qt::black) );
	p.drawEllipse( ellLeft, ellTop, ellWidth, 2*PER_ELL_HALF_HEIGHT*glassHeight );


	/*
	QFont font = p.font();
	font.setBold(true);
	font.setPixelSize(height()-51);
	p.setFont(font);
	p.drawText (11, 31, width()-21, height()-41,
			Qt::AlignHCenter | Qt::AlignVCenter,
			QString::number(_drink_score) );
			*/
}






