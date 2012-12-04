/*
 * ChugFillForm.h
 *
 *  Created on: Dec 4, 2012
 *      Author: gray
 */

#ifndef CHUGFILLFORM_H_
#define CHUGFILLFORM_H_

#include "ui_ChugFillForm.h"

typedef enum chug_fill_e {
	CHUG,
	FILL,
	UNKNOWN
} ChugFill;

class ChugFillForm : public QWidget, private Ui::ChugFillFormWid
{
    Q_OBJECT

public:
    ChugFillForm(ChugFill choice, QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *e);

private:
    ChugFill _choice;
};

#endif /* CHUGFILLFORM_H_ */
