#include "infogroupwindow.h"
#include "ui_infogroupwindow.h"

InfoGroupWindow::InfoGroupWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoGroupWindow)
{
    ui->setupUi(this);
}

InfoGroupWindow::~InfoGroupWindow()
{
    delete ui;
}

void InfoGroupWindow::on_pushButton_clicked()
{
    this->close();
}

void InfoGroupWindow::viewInfo(Group group)
{
    ui->yearLabel->setText(group.getYearOfAdmission());
    ui->facultyLabel->setText(group.getFaculty());
    ui->specialityLabel->setText(group.getSpeciality());
    ui->groupLabel->setText(group.getNumberGroup());
}

