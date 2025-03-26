#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"user.h"
#include"dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->lineEdit_5->hide();
    ui->pushButton_5->hide();
    ui->label->setPixmap(QPixmap("C:/Users/Matei/Pictures/Screenshot 2025-02-11 142304"));
    ui->label_2->setPixmap(QPixmap("C:/Users/Matei/Pictures/Screenshot 2025-02-11 164630"));
    ui->lineEdit_6->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->lineEdit_6->hide();
}


void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->pushButton_3->show();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    ui->pushButton_3->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->lineEdit_6->hide();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit_5->hide();
    User user;
    QString email=ui->lineEdit_3->text(),password=ui->lineEdit->text();

    if(user.check_user(email,password))
    {
        user.set_status(email,password);
        user.set_email(email);
        user.set_password(password);
        user.add(email,password);
        this->hide();
        Dialog d;
        d.exec();
    } else ui->lineEdit_5->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->lineEdit_5->hide();
    ui->pushButton_5->hide();
    ui->pushButton_2->show();
    ui->pushButton->show();
    ui->lineEdit_3->setText("");
    ui->lineEdit->setText("");
    ui->label->show();
    ui->label_2->show();
    ui->lineEdit_6->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    User user;
    QString email=ui->lineEdit_3->text(),password=ui->lineEdit->text();

    qDebug()<<email<<" "<<password;

    if(user.is_valid_mail(email) && user.is_valid_password(password))
    {
        user.set_email(email);
        user.set_password(password);
        user.add(email,password);
        user.print_base();
        user.set_status(email,password);
        user.print_base();

        this->hide();
        Dialog d;
        d.exec();
    } else ui->lineEdit_5->show();
}

