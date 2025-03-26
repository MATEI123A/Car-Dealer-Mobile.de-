#ifndef USER_H
#define USER_H
#include<QString>
#include<QChar>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSql>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlError>

class User
{
public:

    QString email,password,sec_code;

    User(){
        this->email="";
        this->password="";
        this->sec_code="";
    }

    void set_email(QString email)
    {
        this->email=email;
    }

    void set_password(QString password)
    {
        this->password=password;
    }

    bool is_valid_mail(QString mail){
        if (mail.size() < 11)
            return false;

        QString temp = "@yahoo.com", s = "";
        int ok = 0;

        for (int i = mail.size() - 10;i < mail.size();i++)
            s += mail[i];

        if (s != temp)
            return false;


        if (mail[mail.size()-10] == '@' && (mail[mail.size() - 11].isLetterOrNumber()==0))
            return false;

        for (int i = 0;i < mail.size()-10;i++)
            if ((mail[i] >= 'a' && mail[i] <= 'z') || (mail[i] >= 'A' && mail[i] <= 'Z'))
                ok = 1;

        if (ok == 0)
            return false;

        return true;
    }

    bool is_valid_password(QString password){
        if(password.size()<4)
            return false;

        int lit_mica=0,lit_mare=0,cif=0;

        for(int i=0;i<password.size();i++)
            if(password[i]>='a' && password[i]<='z')
                lit_mica++;
            else if(password[i]>='A' && password[i]<='Z')
                lit_mare++;
            else if(password[i].isDigit())
                cif++;

        if(cif && lit_mica && lit_mare)
            return true;

        return false;
    }

    void create_table()
    {
        // Obține conexiunea specifică
        QSqlDatabase db = QSqlDatabase::database("conexiune_user");

        // Verifică dacă baza de date este deschisă
        if (!db.isOpen()) {
            qDebug() << "Eroare: Baza de date nu este deschisă!";
            return;
        }

        QSqlQuery query(db);  // Folosim conexiunea corectă

        // Execută interogarea
        if (!query.exec("CREATE TABLE IF NOT EXISTS user(email TEXT, password TEXT, status INTEGER)")) {
            qDebug() << "Eroare la crearea tabelului 'user':" << query.lastError().text();
        } else {
            qDebug() << "Table 'user' created with success";
        }
    }


    void add(QString email, QString password)
    {
        QSqlDatabase db = QSqlDatabase::database("conexiune_user");
        QSqlQuery query(db);

        query.prepare("INSERT INTO user (email, password, status) VALUES (:email, :password, :status)");
        query.bindValue(":email", email);
        query.bindValue(":password", password);
        query.bindValue(":status", 0);

        qDebug() << "Bound values: email=" << email << ", password=" << password << ", status=0";

        if (!query.exec()) {
            qDebug() << "Error inserting data IN USER: " << query.lastError().text();
        } else {
            qDebug() << "Data inserted successfully.";
        }
    }


    bool is_email_taken(QString email){
        QSqlDatabase db = QSqlDatabase::database("conexiune_user");
        QSqlQuery query(db);

        query.prepare("SELECT COUNT(*) FROM user WHERE email = :name");
        query.bindValue(":name", email);

        if (!query.exec()) {
            qDebug() << "Error executing query:";
            return false;
        }

        if (query.next()) {
            int count = query.value(0).toInt();
            if (count > 0) {
                qDebug() << "User found!";
                return true;
            }
        }

        qDebug() << "User not found!";
        return false;
    }

    void open_database()
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","conexiune_user");
        db.setDatabaseName("mydatabase.db");
        //qDebug() << "Baza de date  cara fost deschisă cu succes.";

        if (!db.open()) {
            qDebug() << "Eroare la deschiderea car bazei de date:";
        } else {
            qDebug() << "Baza de date user a fost deschisă cu succes.";
        }
    }


    bool check_user(QString email, QString password)
    {
        QSqlDatabase db = QSqlDatabase::database("conexiune_user");
        QSqlQuery query(db);

        query.prepare("SELECT password FROM user WHERE email = :name");
        query.bindValue(":name", email);

        if (!query.exec()) {
            qDebug() << "Error executing query:";
            return false;
        }

        if (query.next()) {
            QString dbPassword = query.value(0).toString();

            if (dbPassword == password) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    void set_status(QString email,QString password)
    {
        QSqlDatabase db = QSqlDatabase::database("conexiune_user");
        QSqlQuery query(db);

        query.prepare("UPDATE user SET status = 1 WHERE email = :email AND password = :password");
        query.bindValue(":email", email);
        query.bindValue(":password", password);

        if (query.exec()) {
            qDebug() << "Status updated successfully.";
        } else {
            qDebug() << "Error updating status:";
        }
    }

    void set_status_null(QString email,QString password)
    {
        QSqlDatabase db = QSqlDatabase::database("conexiune_user");
        QSqlQuery query(db);

        query.prepare("UPDATE user SET status = 0 WHERE email = :email AND password = :password");

        query.bindValue(":email", email);
        query.bindValue(":password", password);
        qDebug()<<"Urmeaza sa execut";

        if (query.exec()) {
            qDebug() << "Status updated successfully to 0.";
        } else {
            qDebug() << "Error updating status:";
        }
    }

    void print_base()
    {
        QSqlDatabase db = QSqlDatabase::database("conexiune_user");
        QSqlQuery query(db);

        if (!query.exec("SELECT email, password, status from user")) {
            qDebug() << "Error retrieving data:" << query.lastError().text();
        } else {
            while (query.next()) {
                QString email = query.value(0).toString();
                QString password = query.value(1).toString();
                QString status = query.value(2).toString();

                qDebug() << "Email:" << email
                         << "| password:" << password
                         << "| status:" << status;
            }
        }
    }

};

#endif // USER_H
