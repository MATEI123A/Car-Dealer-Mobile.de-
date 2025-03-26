#include "dialogposts.h"
#include "ui_dialogposts.h"
#include"dialog.h"
#include"car.h"
#include"globals.h"
#include"newdialog.h"
#include"ui_newdialog.h"
#include<QVector>

QVector<QString> powers;
QVector<QString> prices;
QVector<QString> fuels;
QVector<QString> transmissions;


DialogPosts::DialogPosts(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPosts)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::database("conexiune_car");
    QSqlQuery query(db);
    QString email,brand,model,power,price,fuel,transmission;
    int nr=0;

    if (!query.exec("SELECT email, brand, model, power, price, fuel, transmission FROM car")) {
        qDebug() << "Error retrieving data:" << query.lastError().text();
    } else {

        while (query.next()) {

            ++nr;
            email = query.value(0).toString();
            brand = query.value(1).toString();
            model = query.value(2).toString();
            power = query.value(3).toString();
            price = query.value(4).toString();
            fuel = query.value(5).toString();
            transmission = query.value(6).toString();

            transmissions.push_back(transmission);
            fuels.push_back(fuel);
            prices.push_back(price);
            powers.push_back(power);

            qDebug() << "Email:" << email
                     << "| Brand:" << brand
                     << "| Model:" << model
                     << "| Power:" << power
                     << "| Price:" << price
                     << "| Fuel:" << fuel
                     << "| Transmission:" << transmission;

        QString text="";
        text=brand+" "+model+"\n";
        text+=email;

        if(nr==1)
            ui->pushButton->setText(text);
        else if(nr==2)
            ui->pushButton_2->setText(text);
        else ui->pushButton_3->setText(text);
        }
    }
}

DialogPosts::~DialogPosts()
{
    delete ui;
}

void DialogPosts::on_pushButton_8_clicked()
{
    this->hide();
    Dialog d;
    d.exec();
}


void DialogPosts::on_pushButton_2_clicked()
{
    QString data=ui->pushButton_2->text(),brand="",model_name="",email_user="";
    int ok=0,j=0;

    for(int i=0;i<data.size();i++)
    {
        if(data[i]!=" " && ok==0)
            brand+=data[i];
        else
        {
            ok=1;
            j=i;

            if(data[i]!=" " && ok==1 && data[i].isLetter())
                model_name+=data[i];

            if(data[i]=='\n')
                break;
        }
    }

    for(int i=j+1;i<data.size();i++)
        email_user+=data[i];

    qDebug()<<data<<" "<<brand<<" "<<model_name<<" "<<email_user;

    transmisie=transmissions[1];
    pret=prices[1];
    combustibil=fuels[1];
    power=powers[1];
    model=model_name;
    firma=brand;
    email=email_user;
    this->hide();
    newdialog d;
    d.exec();
}


void DialogPosts::on_pushButton_clicked()
{
    QString data=ui->pushButton->text(),brand="",model_name="",email_user="";
    int ok=0,j=0;

    for(int i=0;i<data.size();i++)
    {
        if(data[i]!=" " && ok==0)
            brand+=data[i];
        else
        {
            ok=1;
            j=i;

            if(data[i]!=" " && ok==1 && data[i].isLetter())
                model_name+=data[i];

            if(data[i]=='\n')
                break;
        }
    }

    for(int i=j+1;i<data.size();i++)
        email_user+=data[i];

    qDebug()<<data<<" "<<brand<<" "<<model_name<<" "<<email_user;

    transmisie=transmissions[0];
    pret=prices[0];
    combustibil=fuels[0];
    power=powers[0];
    model=model_name;
    firma=brand;
    email=email_user;
    this->hide();
    newdialog d;
    d.exec();
}


void DialogPosts::on_pushButton_3_clicked()
{
    QString data=ui->pushButton_2->text(),brand="",model_name="",email_user="";
    int ok=0,j=0;

    for(int i=0;i<data.size();i++)
    {
        if(data[i]!=" " && ok==0)
            brand+=data[i];
        else
        {
            ok=1;
            j=i;

            if(data[i]!=" " && ok==1 && data[i].isLetter())
                model_name+=data[i];

            if(data[i]=='\n')
                break;
        }
    }

    for(int i=j+1;i<data.size();i++)
        email_user+=data[i];

    qDebug()<<data<<" "<<brand<<" "<<model_name<<" "<<email_user;

    transmisie=transmissions[2];
    pret=prices[2];
    combustibil=fuels[2];
    power=powers[2];
    model=model_name;
    firma=brand;
    email=email_user;
    this->hide();
    newdialog d;
    d.exec();
}

