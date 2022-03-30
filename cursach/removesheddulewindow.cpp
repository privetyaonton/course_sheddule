#include "removesheddulewindow.h"
#include "ui_removesheddulewindow.h"

RemoveShedduleWindow::RemoveShedduleWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveShedduleWindow)
{
    ui->setupUi(this);
}

RemoveShedduleWindow::~RemoveShedduleWindow()
{
    delete ui;
}
