#include "windowlogin.h"
#include "ui_windowlogin.h"
WindowLogIn::WindowLogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowLogIn)
{
    ui->setupUi(this);
}

WindowLogIn::~WindowLogIn()
{
    delete ui;
}

void WindowLogIn::on_pushButton_clicked()
{
    if (ui->login->text() == NULL || ui->password1->text() == NULL || ui->password2->text() == NULL)
    {
        QMessageBox::critical(this, "", "Заполните все поля");
        return;
    }
    else
    {
        QSqlQuery queryLogin;
        for (int i = 0; i < temp.getData().size(); i++)
        {
            if (temp.getData()[i].getNameUser() == ui->login->text())
            {
                QMessageBox::critical(this, "", "Пользователь с таким логином уже существует");
                return;
            }
        }
        if (ui->password1->text() != ui->password2->text())
        {
            QMessageBox::critical(this, "", "Пароли не совпадают");
            return;
        }
        temp.addLogin(ui->login->text(), ui->password1->text());
        this->close();
        emit signUp();
        return;
    }
}


void WindowLogIn::on_pushButton_2_clicked()
{
    this->close();
    emit signUp();
}

