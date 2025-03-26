#include "dialog.h"
#include "ui_dialog.h"
#include"user.h"
#include<QtSql/QSqlDatabase>
#include<QtSql/QSql>
#include<QtSql/QSqlQuery>
#include"mainwindow.h"
#include <QApplication>
#include"newdialog.h"
#include"dialogpost.h"
#include"dialogposts.h"

int nr=0;
User user;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->pushButton_4->hide();

    QSqlDatabase db = QSqlDatabase::database("conexiune_user");
    QSqlQuery query(db);

    query.prepare("SELECT email, password FROM user WHERE status = 1");

    if (!query.exec()) {
        qDebug()<<"Error";
    } else {
        while (query.next()) {
            QString email = query.value(0).toString();
            QString password = query.value(1).toString();

            for(int i=0;i<password.size();i++)
                password[i]='*';

            ui->lineEdit_2->setText(email);
            ui->lineEdit_3->setText(password);
        }
    }
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_3_clicked()
{
    if(nr%2==0)
    {
        ++nr;
        ui->lineEdit_2->show();
        ui->lineEdit_3->show();
        ui->lineEdit_4->show();
        ui->lineEdit_5->show();
        ui->pushButton_4->show();
    } else{
        ++nr;
        ui->lineEdit_2->hide();
        ui->lineEdit_3->hide();
        ui->lineEdit_4->hide();
        ui->lineEdit_5->hide();
        ui->pushButton_4->hide();
    }
}


void Dialog::on_pushButton_4_clicked()
{
    //User user;

    QString email=ui->lineEdit_2->text(),password=ui->lineEdit_3->text();
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");

    user.print_base();
    user.set_status_null(email,password);
    user.print_base();
    user.set_status_null(email,password);
    this->hide();
    user.set_status_null(email,password);
    user.print_base();

    MainWindow m=new MainWindow();
    m.show();
}


void Dialog::on_pushButton_clicked()
{
    this->hide();
    DialogPosts d;
    d.exec();
}


void Dialog::on_pushButton_2_clicked()
{
    this->hide();
    DialogPost p;
    p.exec();
}

