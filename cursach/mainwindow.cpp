#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    signIn = new WindowSignInUser();
    addGroup = new AddGroupWindow();
    logOut = new WindowVoiceLogOut();
    logIn = new WindowLogIn();
    addSheddule = new AddSheddule();
    infoWindow = new InfoGroupWindow ();
    connect(addGroup, &AddGroupWindow::addGroupSignal, this, &MainWindow::addGroupWidgetTable);
    connect (signIn, &WindowSignInUser::isLogIn, this, &MainWindow::changeNameButton);
    connect (logOut, &WindowVoiceLogOut::logOut, this, &MainWindow::logOutMain);
    connect (ui->changeUser, &QPushButton::clicked, this, &MainWindow::on_logIn_clicked);
    connect (ui->throwFilterButton, &QPushButton::clicked, this, &MainWindow::addGroupWidgetTable);
    connect (this, &MainWindow::dayConverting, this, &MainWindow::viewShedduleTable);
    connect (this, &MainWindow::goToViewInfo, infoWindow, &InfoGroupWindow::viewInfo);
    QSqlQuery query;
    bool is = false;
    query.exec("SELECT correct FROM userTable");
    while (query.next())
    {
        if (query.value(0).toString() == "1")
        {
            is = true;
            ui->logIn->hide();
            break;
        }
    }
    if (!is)
    {
        this->hide();
        signIn->show();
    }
    else
        this->show();
    ui->tableGroup->setColumnCount(1);
    ui->tableGroup->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableGroup->setShowGrid(true);
    ui->tableSheddule->setColumnCount(7);
    ui->tableSheddule->setSelectionMode(QAbstractItemView::NoSelection);
    QStringList headersSheddule = {"+","Время", "Название", "Тип", "Преподаватель", "ауд.", "ID"};
    ui->tableGroup->setHorizontalHeaderLabels({"Номер"});
    ui->tableSheddule->setHorizontalHeaderLabels(headersSheddule);
    addGroupWidgetTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logIn_clicked()
{
    signIn->show();
}

void MainWindow::on_addGroup_clicked()
{
    addGroup->show();
}

void MainWindow::on_removeGroup_clicked()
{
    bool is = false;
    QString number;
    QRadioButton *button = new QRadioButton();
    for (int i = 0; i < ui->tableGroup->rowCount(); i++)
    {
        button = (QRadioButton*)ui->tableGroup->cellWidget(i, 0);
        if (button->isChecked())
        {
            is = true;
            number = button->text();
            break;
        }
    }
    if (!is)
    {
        QMessageBox::critical(this, "", "Выберите группу для удаления");
        return;
    }
    temp.removeGroup(number, temp.getNameActiveUser());
    addGroupWidgetTable();
    return;
}

void MainWindow::addGroupWidgetTable()
{
    QRadioButton *buttonGroup;
    QString argdata;
    QSqlQuery query;
    temp.loadData();
    QString userThis = temp.getNameActiveUser();
    int indexThis = temp.getActiveUser();
    ui->tableGroup->setRowCount(0);
    for (int i = 0; i < temp.getData()[indexThis].getData().size(); i++)
    {
        buttonGroup = new QRadioButton();
        ui->tableGroup->insertRow(i);
        argdata = temp.getData()[indexThis].getData()[i].getNumberGroup();
        buttonGroup->setText(argdata);
        ui->tableGroup->setCellWidget(i, 0, buttonGroup);
    }
    ui->tableGroup->resizeColumnsToContents();
    return;
}

void MainWindow::changeNameButton()
{
    temp.loadData();
    this->show();
    if (temp.getActiveUser() >= 0)
    {
        ui->label->show();
        ui->box2018->show();
        ui->box2019->show();
        ui->box2020->show();
        ui->box2021->show();
        ui->label->show();
        ui->label_2->show();
        ui->boxFIC->show();
        ui->boxFKP->show();
        ui->boxFITU->show();
        ui->boxVF->show();
        ui->boxFRE->show();
        ui->boxKSIS->show();
        ui->boxIEF->show();
        ui->boxIKT->show();
        ui->label_4->show();
        ui->inputGroup->show();
        ui->searchGroup->show();
        ui->tableGroup->show();
        ui->tableSheddule->show();
        ui->buttonFriday->show();
        ui->buttonMonday->show();
        ui->buttonTuesday->show();
        ui->buttonWednesday->show();
        ui->buttonThursday->show();
        ui->buttonSaturday->show();
        ui->addGroup->show();
        ui->removeGroup->show();
        if (temp.getNameActiveUser() == "admin")
        {
            ui->addItem->show();
            ui->deleteItem->show();
        }
        else
        {
            ui->addItem->hide();
            ui->deleteItem->hide();
        }
        ui->logIn->hide();
        ui->logOut->show();
        ui->changeUser->show();
    }
    addGroupWidgetTable();
}

void MainWindow::logOutMain()
{
    ui->logIn->show();
    ui->changeUser->hide();
    ui->logOut->hide();
    ui->addGroup->hide();
    ui->removeGroup->hide();
    ui->addItem->hide();
    ui->deleteItem->hide();
    ui->label->hide();
    ui->label->hide();
    ui->box2018->hide();
    ui->box2019->hide();
    ui->box2020->hide();
    ui->box2021->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->boxFIC->hide();
    ui->boxFKP->hide();
    ui->boxFITU->hide();
    ui->boxVF->hide();
    ui->boxFRE->hide();
    ui->boxKSIS->hide();
    ui->boxIEF->hide();
    ui->boxIKT->hide();
    ui->label_4->hide();
    ui->inputGroup->hide();
    ui->searchGroup->hide();
    ui->tableGroup->hide();
    ui->tableSheddule->hide();
    ui->buttonFriday->hide();
    ui->buttonMonday->hide();
    ui->buttonTuesday->hide();
    ui->buttonWednesday->hide();
    ui->buttonThursday->hide();
    ui->buttonSaturday->hide();
}

void MainWindow::on_logOut_clicked()
{
    logOut->show();
}

void MainWindow::editListOfGroup (QString number, QString faculty, QString speciality, QString year, int id)
{
    Group group;
    group.setNumberGroup(number);
    group.setFaculty(faculty);
    group.setSpeciality(speciality);
    group.setYearOfAdmission(year);
    temp.addGroup(group, temp.getNameActiveUser(id));
}


void MainWindow::on_acceptFilterButton_clicked()
{
    addGroupWidgetTable();
    std::vector <QString> vectorYear;
    std::vector <QString> vectorFaculty;
    if (ui->box2018->isChecked())
        vectorYear.push_back("2018");
    if (ui->box2019->isChecked())
        vectorYear.push_back("2019");
    if (ui->box2020->isChecked())
        vectorYear.push_back("2020");
    if (ui->box2021->isChecked())
        vectorYear.push_back("2021");
    if (ui->boxFKP->isChecked())
        vectorFaculty.push_back("ФКП");
    if (ui->boxFITU->isChecked())
        vectorFaculty.push_back("ФИТУ");
    if (ui->boxVF->isChecked())
        vectorFaculty.push_back("ВФ");
    if (ui->boxFRE->isChecked())
        vectorFaculty.push_back("ФРЭ");
    if (ui->boxKSIS->isChecked())
        vectorFaculty.push_back("КСиС");
    if (ui->boxFIC->isChecked())
        vectorFaculty.push_back("ФИК");
    if (ui->boxIEF->isChecked())
        vectorFaculty.push_back("ИЭФ");
    if (ui->boxIKT->isChecked())
        vectorFaculty.push_back("ИКТ");
    int isCorrect;
    std::vector<int>idRemoved;
    int length = temp.getActiveUser();
    int numberRemoved = 0;
    for (int i = 0; i < temp.getData()[length].getData().size(); i++)
    {
        if (vectorYear.size() != 0)
        {
            isCorrect = 0;
            for (int j = 0; j < vectorYear.size(); j++)
                if (temp.getData()[length].getData()[i].getYearOfAdmission() != vectorYear[j])
                    isCorrect++;
            if (isCorrect == vectorYear.size())
            {
                ui->tableGroup->removeRow(i - numberRemoved);
                idRemoved.push_back(1);
                numberRemoved++;
            }
            else
                idRemoved.push_back(0);
        }
     }
    int k = 0;
    numberRemoved = 0;
    for (int i = 0; i < temp.getData()[length].getData().size(); i++)
    {
        if (vectorFaculty.size() != 0 && idRemoved[i] != 1)
        {
            isCorrect = 0;
            for (int j = 0; j < vectorFaculty.size(); j++)
                if (temp.getData()[length].getData()[i].getFaculty() != vectorFaculty[j])
                    isCorrect++;
            if (isCorrect == vectorFaculty.size())
            {
                ui->tableGroup->removeRow(k - numberRemoved);
                numberRemoved++;
            }
            k++;
        }
    }
}



void MainWindow::on_searchGroup_clicked()
{
    bool is = false;
    int index = 0;
    temp.loadData();
    for (int i = 0; i < temp.getData()[temp.getActiveUser()].getData().size(); i++)
    {
        if (ui->inputGroup->text() == temp.getData()[temp.getActiveUser()].getData()[i].getNumberGroup())
        {
            is = true;
            index = i;
            break;
        }
    }
    if (!is)
    {
        QMessageBox::critical(this, "", "Такой группы не добавлено");
        return;
    }
    ui->tableGroup->setRowCount(0);
    QRadioButton *button = new QRadioButton();
    button->setText(temp.getData()[temp.getActiveUser()].getData()[index].getNumberGroup());
    ui->tableGroup->insertRow(0);
    ui->tableGroup->setCellWidget(0,0,button);
}

void MainWindow::on_addItem_clicked()
{
    addSheddule->show();
}

void MainWindow::viewShedduleTable (int day)
{
    std::vector<Class> correctSheddule;
    std::vector<Class> ideal;
    std::vector<int> dayClass;
    ui->tableSheddule->setRowCount(0);
    QString numberGroup;
    QRadioButton *button = new QRadioButton();
    for (int i = 0; i < ui->tableGroup->rowCount(); i++)
    {
        button = (QRadioButton*)ui->tableGroup->cellWidget(i, 0);
        if (button->isChecked())
        {
            numberGroup = button->text();
        }
    }
    obj.loadData();
    for (int i = 0; i < obj.getData().size(); i++)
    {
        if (numberGroup == obj.getData()[i].getNumberGroup())
        {
            if (day == 1)
                if (obj.getData()[i].getMonday() == 1)
                    correctSheddule.push_back(obj.getData()[i]);
            if (day == 2)
                if (obj.getData()[i].getTuesday() == 1)
                    correctSheddule.push_back(obj.getData()[i]);
            if (day == 3)
                if (obj.getData()[i].getWednesday() == 1)
                    correctSheddule.push_back(obj.getData()[i]);
            if (day == 4)
                if (obj.getData()[i].getThursday() == 1)
                    correctSheddule.push_back(obj.getData()[i]);
            if (day == 5)
                if (obj.getData()[i].getFriday() == 1)
                    correctSheddule.push_back(obj.getData()[i]);
            if (day == 6)
                if (obj.getData()[i].getSaturday() == 1)
                    correctSheddule.push_back(obj.getData()[i]);
        }
    }
    for (int i = 0; i < correctSheddule.size(); i++)
    {
        if ((ui->week1->isChecked() && correctSheddule[i].getWeekOne() == 1) || (ui->week2->isChecked() && correctSheddule[i].getWeekTwo() == 1) ||
                (ui->week3->isChecked() && correctSheddule[i].getWeekThree() == 1) ||
                (ui->week4->isChecked() && correctSheddule[i].getWeekFour() == 1))
            if ((ui->sub1->isChecked() && correctSheddule[i].getSubGroupFirst() == 1) ||
                    (ui->sub2->isChecked() && correctSheddule[i].getSubGroupSecond() == 1))
                ideal.push_back(correctSheddule[i]);
    }
    Class obj;
    for (int i = 0; i < ideal.size(); i++)
        for (int j = i; j < ideal.size(); j++)
            if (ideal[i].getNumberClass() > ideal[j].getNumberClass())
            {
                obj = ideal[i];
                ideal[i] = ideal[j];
                ideal[j] = obj;
            }
    QString time;
    for (int i = 0; i < ideal.size(); i++)
    {
        ui->tableSheddule->insertRow(i);
        if (ideal[i].getNumberClass() == 1)
            time = "9:00 - 10:20";
        if (ideal[i].getNumberClass() == 2)
            time = "10:35 - 11:55";
        if (ideal[i].getNumberClass() == 3)
            time = "12:25 - 13:45";
        if (ideal[i].getNumberClass() == 4)
            time = "14:00 - 15:20";
        if (ideal[i].getNumberClass() == 5)
            time = "15:50 - 17:10";
        if (ideal[i].getNumberClass() == 6)
            time = "17:25 - 18:45";
        if (ideal[i].getNumberClass() == 7)
            time = "19:00 - 20:20";
        if (ideal[i].getNumberClass() == 8)
            time = "20:40 - 22:00";
        ui->tableSheddule->setCellWidget(i, 0, new QRadioButton());
        ui->tableSheddule->setItem(i, 1, new QTableWidgetItem(time));
        ui->tableSheddule->setItem(i, 2, new QTableWidgetItem(ideal[i].getNameItem()));
        ui->tableSheddule->setItem(i, 3, new QTableWidgetItem(ideal[i].getTypeClass()));
        ui->tableSheddule->setItem(i, 4, new QTableWidgetItem(ideal[i].getNameTeacher()));
        ui->tableSheddule->setItem(i, 5, new QTableWidgetItem(ideal[i].getNumberAuditory()));
        ui->tableSheddule->setItem(i, 6, new QTableWidgetItem(ideal[i].getId()));
    }
    ui->tableSheddule->resizeColumnsToContents();
}

void MainWindow::on_buttonMonday_clicked()
{
    emit dayConverting(1);
}


void MainWindow::on_buttonTuesday_clicked()
{
    emit dayConverting(2);
}


void MainWindow::on_buttonWednesday_clicked()
{
    emit dayConverting(3);
}



void MainWindow::on_buttonThursday_clicked()
{
    emit dayConverting(4);
}


void MainWindow::on_buttonFriday_clicked()
{
    emit dayConverting(5);
}


void MainWindow::on_buttonSaturday_clicked()
{
    emit dayConverting(6);
}

void MainWindow::on_deleteItem_clicked()
{
    QRadioButton *button = new QRadioButton ();
    for (int i = 0; i < ui->tableSheddule->rowCount(); i++)
    {
        button = (QRadioButton*)ui->tableSheddule->cellWidget(i, 0);
        if (button->isChecked())
        {
            obj.removeSheddule(ui->tableSheddule->item(i, 6)->text().toInt());
        }
    }
    ui->tableSheddule->setRowCount(0);
}

void MainWindow::on_pushButton_clicked()
{
    QRadioButton *button = new QRadioButton();
    for (int i = 0; i < ui->tableGroup->rowCount(); i++)
    {
        button = (QRadioButton*)ui->tableGroup->cellWidget(i, 0);
        if (button->isChecked())
            goToViewInfo(listGroup.findGroup(button->text()));
    }
    infoWindow->show();
}

