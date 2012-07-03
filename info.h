/*
 * info.h
 *
 * Copyright (c) 2012, Dennis Rassmann <showp1984@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */

#ifndef INFO_H
#define INFO_H

#include <QDialog>

namespace Ui {
    class Info;
}

class Info : public QDialog {
    Q_OBJECT
public:
    Info(QWidget *parent = 0);
    ~Info();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Info *ui;

private slots:
    void on_btn_back_clicked();
};

#endif // INFO_H
