#include "dialogpost.h"
#include "ui_dialogpost.h"
#include<QIcon>
#include"car.h"
#include"user.h"
#include<QtSql/QSqlDatabase>
#include<QtSql/QSql>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include"dialog.h"

DialogPost::DialogPost(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPost)
{
    ui->setupUi(this);
    ui->fordbutton->setIcon(QIcon("C:/Users/Matei/Pictures/ford"));
    ui->bmwbutton->setIcon(QIcon("C:/Users/Matei/Pictures/bmw"));
    ui->audibutton->setIcon(QIcon("C:/Users/Matei/Pictures/audi"));
    ui->opelbutton->setIcon(QIcon("C:/Users/Matei/Pictures/opel"));
    ui->mercedesbutton->setIcon(QIcon("C:/Users/Matei/Pictures/mercedes"));
    ui->vwbutton->setIcon(QIcon("C:/Users/Matei/Pictures/vw"));
    ui->vwbutton->setIconSize(QSize(50, 50));
    ui->audibutton->setIconSize(QSize(50, 50));
    ui->bmwbutton->setIconSize(QSize(50, 50));
    ui->mercedesbutton->setIconSize(QSize(50, 50));
    ui->fordbutton->setIconSize(QSize(50, 50));
    ui->opelbutton->setIconSize(QSize(50, 50));
    ui->lineEdit_14->hide();
    ui->pushButton_2->hide();

}

DialogPost::~DialogPost()
{
    delete ui;
}

void DialogPost::on_vwbutton_clicked()
{
    ui->lineEdit->setText("Volkswagen");
}


void DialogPost::on_audibutton_clicked()
{
    ui->lineEdit->setText("Audi");
}


void DialogPost::on_opelbutton_clicked()
{
    ui->lineEdit->setText("Opel");
}


void DialogPost::on_fordbutton_clicked()
{
    ui->lineEdit->setText("Ford");
}


void DialogPost::on_bmwbutton_clicked()
{
    ui->lineEdit->setText("Bmw");
}


void DialogPost::on_mercedesbutton_clicked()
{
    ui->lineEdit->setText("Mercedes");
}


void DialogPost::on_pushButton_clicked()
{
    int nr=0;
    Car car;

    if (ui->lineEdit->text().isEmpty() || ui->lineEdit->text()=="Must complete!")
        ui->lineEdit->setText("Must complete!");
    else ++nr;

    if (ui->lineEdit_11->text().isEmpty() || ui->lineEdit_11->text()=="Must complete!")
        ui->lineEdit_11->setText("Must complete!");
    else ++nr;

    if (ui->lineEdit_12->text().isEmpty() || ui->lineEdit_12->text()=="Must complete!")
        ui->lineEdit_12->setText("Must complete!");
    else ++nr;

    if (ui->lineEdit_13->text().isEmpty() || ui->lineEdit_13->text()=="Must complete!")
        ui->lineEdit_13->setText("Must complete!");
    else ++nr;

    if (ui->lineEdit_10->text().isEmpty() || ui->lineEdit_10->text()=="Must complete!")
        ui->lineEdit_10->setText("Must complete!");
    else ++nr;

    if (ui->lineEdit_3->text().isEmpty() || ui->lineEdit_3->text()=="Must complete!")
        ui->lineEdit_3->setText("Must complete!");
    else ++nr;

    if(nr==6)
    {
        Car car;
        QString fuel=ui->lineEdit_3->text(),model=ui->lineEdit_11->text(),brand=ui->lineEdit->text(),transmission=ui->lineEdit_10->text();
        QString price=ui->lineEdit_13->text(),power=ui->lineEdit_12->text(),email="";

        User user;

        QSqlDatabase db = QSqlDatabase::database("conexiune_user");
        QSqlQuery query(db);

        query.prepare("SELECT email FROM user WHERE status = 1");

        if (!query.exec()) {
            qDebug()<<"eror"<< query.lastError().text();
        } else {
            while (query.next()) {
                email=query.value(0).toString();
            }
        }

        car.setfuel(fuel);
        car.setmodel(model);
        car.setbrand(brand);
        car.settransmission(transmission);
        car.setprice(price);
        car.setpower(power);
        car.setemail(email);
        car.print_base();
        car.add(email,brand,model,power,price,fuel,transmission);

        ui->vwbutton->hide();
        ui->audibutton->hide();
        ui->bmwbutton->hide();
        ui->mercedesbutton->hide();
        ui->fordbutton->hide();
        ui->opelbutton->hide();

        ui->lineEdit->hide();
        ui->lineEdit_2->hide();
        ui->lineEdit_4->hide();
        ui->lineEdit_5->hide();
        ui->lineEdit_6->hide();
        ui->lineEdit_7->hide();
        ui->lineEdit_8->hide();
        ui->lineEdit_9->hide();
        ui->lineEdit_3->hide();
        ui->lineEdit_10->hide();
        ui->lineEdit_11->hide();
        ui->lineEdit_12->hide();
        ui->lineEdit_13->hide();
        ui->pushButton->hide();
        ui->pushButton_3->hide();

        ui->lineEdit_14->show();
        ui->pushButton_2->show();
    }
}


void DialogPost::on_pushButton_3_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_11->setText("");
    ui->lineEdit_12->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_10->setText("");
    ui->lineEdit_13->setText("");

    this->hide();

    Dialog d;
    d.exec();
}


void DialogPost::on_pushButton_2_clicked()
{
    this->hide();
    Dialog d;
    d.exec();
}

