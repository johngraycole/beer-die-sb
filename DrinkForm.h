/*
 * DrinkForm.h
 *
 *  Created on: Nov 11, 2012
 *      Author: gray
 */

#ifndef DRINKFORM_H_
#define DRINKFORM_H_

#include <boost/thread/mutex.hpp>
#include "ui_DrinkForm.h"

class DrinkForm : public QWidget, private Ui::DrinkFormWid
{
    Q_OBJECT

public:
    DrinkForm(QWidget *parent = 0);

    void SetDrinkScore(int drink_score);

protected:
    virtual void paintEvent(QPaintEvent *e);

private:
	int _drink_score;
	boost::mutex _mutex;
};


#endif /* SCOREFORM_H_ */
