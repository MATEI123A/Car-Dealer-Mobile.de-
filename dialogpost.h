#ifndef DIALOGPOST_H
#define DIALOGPOST_H

#include <QDialog>

namespace Ui {
class DialogPost;
}

class DialogPost : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPost(QWidget *parent = nullptr);
    ~DialogPost();

private slots:
    void on_vwbutton_clicked();

    void on_audibutton_clicked();

    void on_opelbutton_clicked();

    void on_fordbutton_clicked();

    void on_bmwbutton_clicked();

    void on_mercedesbutton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DialogPost *ui;
};

#endif // DIALOGPOST_H
