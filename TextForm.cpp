/*
 * TextForm.cpp
 *
 *  Created on: Dec 4, 2012
 *      Author: gray
 */

#include "TextForm.h"

#include <QPainter>

using namespace std;

TextForm::TextForm(const string &text, QWidget *parent) :
QWidget(parent),
_text(text)
{
	setupUi(this);
}


void TextForm::paintEvent(QPaintEvent *e) {
	QPainter p(this);

	int absTop = 10, absLeft = 10;
	int absHeight = height()-20, absWidth = width()-20;
	p.fillRect(absLeft+1, absTop+1, absWidth-1, absHeight-1, Qt::white);

	QFont font = p.font();
	font.setBold(true);
	font.setPixelSize(width()*.25);
	p.setFont(font);

	p.drawText (absLeft+1, absTop+1, absWidth-1, absHeight-1,
			Qt::AlignHCenter | Qt::AlignVCenter, QString::fromStdString(_text) );

}





