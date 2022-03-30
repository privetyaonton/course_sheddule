#ifndef WINDOWLOGIN_H
#define WINDOWLOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include "adduserlist.h"

namespace Ui {
class WindowLogIn;
}

class WindowLogIn : public QDialog
{
    Q_OBJECT

public:
    explicit WindowLogIn(QWidget *parent = nullptr);
    ~WindowLogIn();

signals:
    void signUp();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::WindowLogIn *ui;
    AddUserList temp;
};

#endif // WINDOWLOGIN_H
