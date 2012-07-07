/*
 * database.cpp
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

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

QSqlDatabase connectDB(void) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    /* I won't give you my login data here :p */
    db.setHostName("111.222.33.44");
    db.setDatabaseName("dbstuffz");
    db.setUserName("supersecretlogin");
    db.setPassword("supersecretpw");

    if (!db.open()) qDebug() << "Failed to connect to database";
    return db;
}
