#ifndef CAR_H
#define CAR_H

#include<QString>
#include<QVector>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSql>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>

class Car
{
public:
    QString price,model,power,fuel,transmission,brand,email;
    QVector<QString> cars;

    Car(){
        this->power="";
        this->price="";
        this->fuel="";
        this->brand="";
        this->model="";
        this->transmission="";
        this->email="";
    }

    void setbrand(QString name){
        this->brand=name;
    }

    void setprice(QString price){
        this->price=price;
    }

    void setpower(QString power){
        this->power=power;
    }

    void setmodel(QString model){
        this->model=model;
    }

    void setfuel(QString fuel){
        this->fuel=fuel;
    }

    void settransmission(QString transmission){
        this->transmission=transmission;
    }
    
    void setemail(QString email) {
        this->email=email;
    }
    
    void open_database()
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","conexiune_car");
        db.setDatabaseName("cardatabase.db");

        if (!db.open()) {
            qDebug() << "Eroare la deschiderea car bazei de date:";
        } else {
            qDebug() << "Baza de date car a fost deschisă cu succes.";
        }
    }
    
    void create_table()
    {
        QSqlDatabase db = QSqlDatabase::database("conexiune_car");

        if (!db.isOpen()) {
            qDebug() << "Eroare: Baza de date nu este deschisă!";
            return;
        }

        QSqlQuery query(db);

        if (!query.exec("CREATE TABLE IF NOT EXISTS car (email TEXT, brand TEXT, model TEXT, power TEXT, price TEXT, fuel TEXT, transmission TEXT)")) {
            qDebug() << "Error creating table:" << query.lastError().text();
        } else {
            qDebug() << "Table 'car' created or already exists.";
        }
    }


    void print_base()
    {
        QSqlDatabase db = QSqlDatabase::database("conexiune_car");
        QSqlQuery query(db);

        if (!query.exec("SELECT email, brand, model, power, price, fuel, transmission FROM car")) {
            qDebug() << "Error retrieving data:" << query.lastError().text();
        } else {
            while (query.next()) {
                QString email = query.value(0).toString();
                QString brand = query.value(1).toString();
                QString model = query.value(2).toString();
                QString power = query.value(3).toString();
                QString price = query.value(4).toString();
                QString fuel = query.value(5).toString();
                QString transmission = query.value(6).toString();

                qDebug() << "Email:" << email
                         << "| Brand:" << brand
                         << "| Model:" << model
                         << "| Power:" << power
                         << "| Price:" << price
                         << "| Fuel:" << fuel
                         << "| Transmission:" << transmission;
            }
        }
    }

    
    void add(QString email, QString brand, QString model, QString power, QString price, QString fuel, QString transmission) {

        QSqlDatabase db = QSqlDatabase::database("conexiune_car");
        QSqlQuery query(db);

        query.prepare("INSERT INTO car (email, brand, model, power, price, fuel, transmission) VALUES (:email, :brand, :model, :power, :price, :fuel, :transmission)");

        query.bindValue(":email", email);
        query.bindValue(":brand", brand);
        query.bindValue(":model", model);
        query.bindValue(":power", power);
        query.bindValue(":price", price);
        query.bindValue(":fuel", fuel);
        query.bindValue(":transmission", transmission);

        if (!query.exec()) {
            qDebug() << "Error inserting data:" << query.lastError().text();
        } else {
            qDebug() << "Data inserted successfully in car.";
        }
    }

};

#endif // CAR_H
