#include "newdialog.h"
#include "ui_newdialog.h"
#include"car.h"
#include"dialog.h"
#include"globals.h"
#include"dialogposts.h"

newdialog::newdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::newdialog)
{
    ui->setupUi(this);
    QPixmap pixmap("C:/Users/Matei/Pictures/Screenshot 2025-02-04 124426");
    ui->label_2->setPixmap(pixmap);

    QPixmap pixmap2("C:/Users/Matei/Pictures/Screenshot 2025-02-04 125139");
    ui->label_3->setPixmap(pixmap2);

    QPixmap pixmap3("C:/Users/Matei/Pictures/Screenshot 2025-02-04 125208");
    ui->label_7->setPixmap(pixmap3);

    QPixmap pixmap4("C:/Users/Matei/Pictures/Screenshot 2025-02-04 125058");
    ui->label_4->setPixmap(pixmap4);

    ui->lineEdit_2->setText(pret);
    ui->lineEdit_8->setText(combustibil);
    ui->lineEdit_4->setText(power);
    ui->lineEdit_6->setText(transmisie);
    ui->lineEdit_18->setText(firma+" "+model);
    ui->lineEdit_19->setText(email);
}

newdialog::~newdialog()
{
    delete ui;
}

void newdialog::on_pushButton_clicked()
{
    Car car;
    QString mileage=ui->lineEdit_2->text(),power=ui->lineEdit_4->text(),fuel=ui->lineEdit_8->text(),transmission=ui->lineEdit_6->text();
    QString name=ui->lineEdit_18->text(),price=ui->lineEdit_19->text();

    car.setfuel(fuel);
    car.setpower(power);
    car.settransmission(transmission);
    car.setprice(price);
}


void newdialog::on_pushButton_2_clicked()
{
    ui->lineEdit_2->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_18->setText("");
    ui->lineEdit_19->setText("");
    ui->lineEdit_19->setText("");

    this->hide();
    DialogPosts d;
    d.exec();
}

