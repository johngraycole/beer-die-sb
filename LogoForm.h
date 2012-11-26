/*
 * LogoForm.h
 *
 *  Created on: Nov 25, 2012
 *      Author: gray
 */

#ifndef LOGOFORM_H_
#define LOGOFORM_H_

#include "ui_LogoForm.h"
#include <string>

class LogoForm : public QWidget, private Ui::LogoFormWid
{
    Q_OBJECT

public:
    LogoForm(std::string &image, QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *e);

private:
    int _curr_x, _curr_y;
};


#endif /* LOGOFORM_H_ */
