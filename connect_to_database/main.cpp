

#include <QCoreApplication>
#include <QDebug>
#include <QVariant>
#include <QTextStream>

#include "postgresql.h"

QTextStream out(stdout);
QTextStream in(stdin);

void try_connect(PostgreSQL &sql, QString &plugin, QString &database_name, QString &host, int &port, QString &username, QString &password) {
    bool connected = sql.connect(plugin, database_name, host, port, username, password);
    if(connected)
        qInfo() << "\n\n Connection to the database is open!\n";
    else{
        qWarning() << "\nNo Connection Available\n\n";
        exit(0);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    PostgreSQL sql;

    QString plugin;
    QString database_name;
    QString host;
    int port;
    QString username;
    QString password;

    out << "\nEnter Plugin (Example(QPSQL, MYSQL, SQLITE)): ";
    out.flush();
    in >> plugin;
    system("cls");

    out << "\nEnter database name: ";
    out.flush();
    in >> database_name;
    system("cls");

    out << "\nEnter hostname (Example(localhost)): ";
    out.flush();
    in >> host;
    system("cls");

    out << "\nEnter port (Example for PostgreSql(5432)): ";
    out.flush();
    in >> port;
    system("cls");

    out << "\nEnter username: ";
    out.flush();
    in >> username;
    system("cls");

    out << "\nEnter password: ";
    out.flush();
    in >> password;
    system("cls");

    try_connect(sql, plugin, database_name, host, port, username, password);

    QString table_name;
    out << "\n\nEnter Table Name: ";
    out.flush();
    in >> table_name;
    system("cls");

    char selection;

    do {
        out << "\nSelect From Menu....\n\n\n";
        out << "a* print data that match the class\n\n";
        out << "b* print all the data inside the table\n\n";
        out << "c* Close The Connection To The Database\n\n";
        out << "Select: ";
        out.flush();
        in >> selection;

        switch (selection) {
        case 'a':
            // it uses the class person(class members data type should match the database column types )
            system("cls");
            sql.get_data(table_name);
            break;

        case 'b':
            // it just print all the data
            system("cls");
            sql.print(table_name);
            break;

        case 'c':
            system("cls");
            sql.close();
            exit(0);

        default:
            system("cls");
            qWarning() << "Select from a, b, c";
            break;
        }

    }while(1);



    return a.exec();
}
