#include "addsheddule.h"
#include "ui_addsheddule.h"

AddSheddule::AddSheddule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSheddule)
{
    ui->setupUi(this);
    ui->timeClass->addItem("9:00 - 10:20");
    ui->timeClass->addItem("10:35 - 11:55");
    ui->timeClass->addItem("12:25 - 13:45");
    ui->timeClass->addItem("14:00 - 15:20");
    ui->timeClass->addItem("15:50 - 17:10");
    ui->timeClass->addItem("17:25 - 18:45");
    ui->timeClass->addItem("19:00 - 20:20");
    ui->timeClass->addItem("20:40 - 22:00");
    ui->typeClass->addItem("ЛК");
    ui->typeClass->addItem("ПЗ");
    ui->typeClass->addItem("ЛР");
    ui->nameItem->clear();
    ui->nameTeacher->clear();
    ui->numberAuditory->clear();
    ui->numberGroup->clear();
}

AddSheddule::~AddSheddule()
{
    delete ui;
}

void AddSheddule::on_enter_clicked()
{
    Class count;
    QSqlQuery query;
    bool is = false;
    if (ui->nameItem->text() == NULL || ui->nameTeacher->text() == NULL || ui->numberAuditory->text() == NULL || ui->numberGroup->text() == NULL ||
            (!ui->secondGroup1->isChecked() && !ui->secondGroup2->isChecked()) || (!ui->week1->isChecked() && !ui->week2->isChecked() &&
                                                                                   !ui->week3->isChecked() && !ui->week4->isChecked()) ||
            (!ui->monday->isChecked() && !ui->tuesday->isChecked() && !ui->wednesday->isChecked() && !ui->thursday->isChecked() &&
             !ui->friday->isChecked() && !ui->saturday->isChecked()))
    {
        QMessageBox::critical(this, "", "Заполните все поля");
        return;
    }
    obj.loadData();
    for (int i = 0; i < obj.getData().size(); i++)
    {
        if (ui->numberGroup->text() == obj.getData()[i].getNumberGroup())
        {
            count.setNumberGroup(obj.getData()[i].getNumberGroup());
            is = true;
            break;
        }
    }
    if (!is)
    {
        QMessageBox::critical(this, "", "Такой группы не существует");
        return;
    }
    count.setNumberClass(ui->timeClass->currentIndex() + 1);
    count.setTypeClass(ui->typeClass->currentText());
    count.setNameItem(ui->nameItem->text());
    count.setNameTeacher(ui->nameTeacher->text());
    count.setNumberAuditory(ui->numberAuditory->text());
    if (ui->secondGroup1->isChecked())
        count.setSubGroupFirst(1);
    if (ui->secondGroup2->isChecked())
        count.setSubGroupSecond(1);
    if (ui->week1->isChecked())
        count.setWeekOne(1);
    if (ui->week2->isChecked())
        count.setWeekTwo(1);
    if (ui->week3->isChecked())
        count.setWeekThree(1);
    if (ui->week4->isChecked())
        count.setWeekFour(1);
    if (ui->monday->isChecked())
        count.setMonday(1);
    if (ui->tuesday->isChecked())
        count.setTuesday(1);
    if (ui->wednesday->isChecked())
        count.setWednesday(1);
    if (ui->thursday->isChecked())
        count.setThursday(1);
    if (ui->friday->isChecked())
        count.setFriday(1);
    if (ui->saturday->isChecked())
        count.setSaturday(1);
    is = false;
    for (int i = 0; i < temp.getData().size(); i++)
    {
        if (count == temp.getData()[i])
        {
            is = true;
            break;
        }
    }
    if (is)
    {
        QMessageBox::critical(this, "", "Расписания с такими же параметрами уже было добавлено");
        return;
    }
    temp.addSheddule(count);
    ui->nameItem->clear();
    ui->nameTeacher->clear();
    ui->numberAuditory->clear();
    ui->numberGroup->clear();
    this->close();
}


