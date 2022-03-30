#include "windowsigninuser.h"
#include "ui_windowsigninuser.h"


WindowSignInUser::WindowSignInUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowSignInUser)
{
    ui->setupUi(this);
    logIn = new WindowLogIn ();
    connect(logIn, &WindowLogIn::signUp, this, &WindowSignInUser::show);
}

WindowSignInUser::~WindowSignInUser()
{
    delete ui;
}

void WindowSignInUser::on_pushButton_clicked()
{
    bool isCorrectLogin = false;
    bool isCorrectPassword = false;
    temp.loadData();
    if (ui->login->text() == NULL || ui->password->text() == NULL)
    {
        QMessageBox::critical(this, "", "Заполните все поля");
        return;
    }
    for (int i = 0; i < temp.getData().size(); i++)
    {
        if (temp.getData()[i].getNameUser() == ui->login->text())
        {
            isCorrectLogin = true;
            if (temp.getData()[i].getPassword()== ui->password->text())
            {
                isCorrectPassword = true;
                temp.setActiveIndex(i);
                ui->login->clear();
                ui->password->clear();
                this->close();
                emit isLogIn();
                break;
            }
        }
    }
    if (isCorrectLogin == false)
    {
        QMessageBox::critical(this, "", "Такого пользователя не существует");
        return;
    }
    else
    {
        if (isCorrectPassword == false)
        {
            QMessageBox::critical(this, "", "Пароль не верный!");
            return;
        }
    }
}


void WindowSignInUser::on_pushButton_2_clicked()
{
    this->close();
    logIn->show();
}


void WindowSignInUser::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 2)
        ui->password->setEchoMode(QLineEdit::Normal);
    else
        ui->password->setEchoMode(QLineEdit::Password);
}

