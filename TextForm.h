/*
 * TextForm.h
 *
 *  Created on: Dec 4, 2012
 *      Author: gray
 */

#ifndef TEXTFORM_H_
#define TEXTFORM_H_

#include "ui_TextForm.h"

#include <string>

class TextForm : public QWidget, private Ui::TextFormWid
{
    Q_OBJECT

public:
    TextForm(const std::string &text, QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *e);

private:
    std::string _text;
};

#endif /* TEXTFORM_H_ */
