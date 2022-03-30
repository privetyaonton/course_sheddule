#include "windowvoicelogout.h"
#include "ui_windowvoicelogout.h"

WindowVoiceLogOut::WindowVoiceLogOut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowVoiceLogOut)
{
    ui->setupUi(this);
}

WindowVoiceLogOut::~WindowVoiceLogOut()
{
    delete ui;
}

void WindowVoiceLogOut::on_pushyes_clicked()
{
    this->close();
    emit logOut();
}


void WindowVoiceLogOut::on_pushButton_2_clicked()
{
    this->close();
}

