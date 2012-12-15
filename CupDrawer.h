/*
 * CupDrawer.h
 *
 *  Created on: Dec 15, 2012
 *      Author: gray
 */

#ifndef CUPDRAWER_H_
#define CUPDRAWER_H_

#include <QPainter>
#include <QPoint>

class CupDrawer
{

public:
    CupDrawer();

protected:
    void drawCup(QPainter &p,
				 int top, int left,
				 int width, int height,
				 double perFill);
private:
    QPoint findPointAlongLine( QPoint &start, QPoint &end, double per );
};

#endif /* CUPDRAWER_H_ */
