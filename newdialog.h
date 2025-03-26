#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>

namespace Ui {
class newdialog;
}

class newdialog : public QDialog
{
    Q_OBJECT

public:
    explicit newdialog(QWidget *parent = nullptr);
    ~newdialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::newdialog *ui;
};

#endif // NEWDIALOG_H
