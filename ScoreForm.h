/*
 * ScoreForm.h
 *
 *  Created on: Nov 11, 2012
 *      Author: gray
 */

#ifndef SCOREFORM_H_
#define SCOREFORM_H_

#include "ui_ScoreForm.h"

#include <QPainter>

#include <iostream>

using namespace std;


class ScoreForm : public QWidget, private Ui::ScoreFormWid
{
    Q_OBJECT

public:
    ScoreForm(QWidget *parent = 0);


protected:
    virtual void paintEvent(QPaintEvent *e);

private:
	int _score;
};


#endif /* SCOREFORM_H_ */
