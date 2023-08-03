#include "postgresql.h"

PostgreSQL::PostgreSQL(QObject *parent) : QObject{parent}{}


void PostgreSQL::set_gender(qint8 g_int)
{
    switch (g_int) {
    case 0:
        person.setGender(Gender::Male);
        break;
    case 1:
        person.setGender(Gender::Female);
        break;
    case 2:
        person.setGender(Gender::Unknown);
        break;

    default:
        person.setGender(Gender::Unknown);
        break;
    }
}

bool PostgreSQL::connect(QString plugin, QString database_name, QString hostname, int port, QString username, QString password)
{
    db = QSqlDatabase::addDatabase(plugin);

    if(database_name != "")
        db.setDatabaseName(database_name);

    if(hostname == "") db.setHostName("localhost");
    else
        db.setHostName(hostname);

    if(port != NULL)
        db.setPort(port);

    if(username != "")
        db.setUserName(username);

    if(password != "")
        db.setPassword(password);

    bool ok = db.open();
    if(!ok){
        qInfo() << "Database Error: >> " << db.lastError().text();
        return false;
    }

    qInfo() << "Connected To The Database!";
    return true;
}

void PostgreSQL::get_data(QString table_name)
{
    QString cmd("SELECT * FROM " + table_name);

    QSqlQuery q;

    if(!q.exec(cmd)){
        qInfo() << "Database Error: >> " << db.lastError().text();
        qInfo() << "Query Error: >> " << q.lastError();
        return;
    }

    qInfo() << "------------------------------\nGot Query Result: " << q.size() << "\n";
    while(q.next()) {
        person.setFirst_name(q.value(1).toString());
        person.setLast_name(q.value(2).toString());
        person.setAge(q.value(3).toInt());
        set_gender(q.value(4).toInt());
        person.setPhone_numer(q.value(5).toString());
        person.setAddress(q.value(6).toString());
        person.setCity(q.value(7).toString());
        person.setCountry(q.value(8).toString());
        std::cout << person;
    }
}

void PostgreSQL::print(QString table_name)
{
    QString cmd("SELECT * FROM " + table_name);

    QSqlQuery q;

    if(!q.exec(cmd)){
        qInfo() << "Database Error: >> " << db.lastError().text();
        qInfo() << "Query Error: >> " << q.lastError();
        return;
    }

    QSqlRecord columns = q.record();

    QDebug dbg(QtDebugMsg);  // needed to prevent new line when the object destroyed

    qInfo() << "------------------------------\nNumber Of Rows: " << q.size();
    qInfo() << "------------------------------\nNumber Of Columns: " << columns.count() << "\n\n";

    while(q.next()) {

        for(int x{0}; x < columns.count(); x++)
        {
            dbg << q.value(x).toString();
        }
        dbg << "\n------------------------------------------------------------\n";
    }
}


void PostgreSQL::close()
{
    qWarning() << "\n\nClosing The Connection To Database...";
    db.close();
    if(!db.isOpen())
        qInfo() << "Connection To Database Closed!!!\n\n";
    else
        qCritical() << "Couldn't Close The Connection To The Database !\n\n";
}
