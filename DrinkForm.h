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
#include "CupDrawer.h"

class DrinkForm : public QWidget, public CupDrawer, private Ui::DrinkFormWid
{
    Q_OBJECT

public:
    DrinkForm(bool glassOnLeft, QWidget *parent = 0);

    void SetDrinkScore(int drink_score);
    void SetOnDrink(int on_drink);

protected:
    virtual void paintEvent(QPaintEvent *e);

private:
    bool _glass_on_left;
	int _drink_score, _on_drink;
	boost::mutex _mutex;
};


#endif /* SCOREFORM_H_ */
