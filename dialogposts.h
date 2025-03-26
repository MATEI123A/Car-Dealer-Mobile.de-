#ifndef DIALOGPOSTS_H
#define DIALOGPOSTS_H

#include <QDialog>

namespace Ui {
class DialogPosts;
}

class DialogPosts : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPosts(QWidget *parent = nullptr);
    ~DialogPosts();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::DialogPosts *ui;
};

#endif // DIALOGPOSTS_H
