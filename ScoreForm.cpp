#include "ScoreForm.h"

#include <QPainter>

using namespace boost;

ScoreForm::ScoreForm(QWidget *parent) :
QWidget(parent),
_mutex()
{
	setupUi(this);
	_score = 0;
}

void ScoreForm::SetScore(int score) {
	_mutex.lock();
	_score = score;
	_mutex.unlock();
	QMetaObject::invokeMethod(this, "repaint", Qt::QueuedConnection);
}


void ScoreForm::paintEvent(QPaintEvent *e) {
	_mutex.lock();
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
			QString::number(_score) );
	_mutex.unlock();
}




