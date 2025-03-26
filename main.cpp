#include "mainwindow.h"
#include <QApplication>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSql>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include"user.h"
#include"car.h"
#include"dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    User user;
    user.open_database();
    user.create_table();

    Car car;
    car.open_database();
    car.create_table();

    QSqlDatabase db = QSqlDatabase::database("conexiune_user");
    QSqlQuery query(db);

    query.prepare("SELECT email, password FROM user WHERE status = 0");

    if (!query.exec()) {
        qDebug() << "Eroare la executie";
    } else {
        if (query.next()) {
            Dialog d;
            d.exec();
        } else
        {
            MainWindow w;
            w.show();
            return a.exec();
        }
    }
}
