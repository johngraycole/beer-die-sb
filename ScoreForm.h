/*
 * ScoreForm.h
 *
 *  Created on: Nov 11, 2012
 *      Author: gray
 */

#ifndef SCOREFORM_H_
#define SCOREFORM_H_

#include <boost/thread/mutex.hpp>
#include "ui_ScoreForm.h"


class ScoreForm : public QWidget, private Ui::ScoreFormWid
{
    Q_OBJECT

public:
    ScoreForm(QWidget *parent = 0);

    void SetScore(int score);

protected:
    virtual void paintEvent(QPaintEvent *e);

private:
	int _score;
	boost::mutex _mutex;
};


#endif /* SCOREFORM_H_ */
