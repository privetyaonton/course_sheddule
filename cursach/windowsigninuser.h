#ifndef WINDOWSIGNINUSER_H
#define WINDOWSIGNINUSER_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "windowlogin.h"
#include "adduserlist.h"
namespace Ui {
class WindowSignInUser;
}

class WindowSignInUser : public QDialog
{
    Q_OBJECT

public:
    explicit WindowSignInUser(QWidget *parent = nullptr);
    ~WindowSignInUser();

signals:
    void isLogIn ();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::WindowSignInUser *ui;
    WindowLogIn *logIn;
    AddUserList temp;
};

#endif // WINDOWSIGNINUSER_H
