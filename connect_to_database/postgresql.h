#ifndef POSTGRESQL_H
#define POSTGRESQL_H

#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QString>
#include <string>
#include <QTextStream>
#include <iostream>
#include <QSharedPointer>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "person.h"

class PostgreSQL : public QObject
{
    Q_OBJECT
public:
    explicit PostgreSQL(QObject *parent = nullptr);

signals:



public slots:
    bool connect(QString plugin, QString database_name, QString hostname, int port, QString username, QString password);
    void get_data(QString table_name);
    void print(QString table_name);
    void close();

private:
    void set_gender(qint8 g_int);

private:
    QSqlDatabase db;
    Person person;


};

#endif // POSTGRESQL_H
