#include "addgroupwindow.h"
#include "ui_addgroupwindow.h"


AddGroupWindow::AddGroupWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGroupWindow)
{
    ui->setupUi(this);
    ui->boxYear->addItem("2018");
    ui->boxYear->addItem("2019");
    ui->boxYear->addItem("2020");
    ui->boxYear->addItem("2021");
    ui->boxFaculty->addItem("ФКП");
    ui->boxFaculty->addItem("ФИТУ");
    ui->boxFaculty->addItem("ВФ");
    ui->boxFaculty->addItem("ФРЭ");
    ui->boxFaculty->addItem("КСиС");
    ui->boxFaculty->addItem("ФИК");
    ui->boxFaculty->addItem("ИЭФ");
    ui->boxFaculty->addItem("ИКТ");
}

AddGroupWindow::~AddGroupWindow()
{
    delete ui;
}

void AddGroupWindow::on_boxFaculty_currentIndexChanged(const QString &arg1)
{
    obj.loadData();
    ui->boxSpeciality->clear();
    QStringList fkpSpeciality, fituSpeciality, vfSpeciality, freSpeciality, ksisSpeciality, ficSpeciality, iefSpeciality, iktSpeciality, stringLisst;
    int sum = 0;
    stringLisst.clear();
    int sizeVector = obj.getData().size();
    QStringList fac, spec;
    for (int i = 0; i < sizeVector; i++)
    {
        fac.append(obj.getData()[i].getFaculty());
        spec.append(obj.getData()[i].getSpeciality());
    }
    for (int i = 0; i < sizeVector; i++)
    {
        if (fac.at(i) == "ФКП")
        {
            stringLisst.append(spec.at(i));
            if (stringLisst.size() > 1)
            {
                for (int j = 0; j < stringLisst.size() - 1; j++)
                {
                    if (stringLisst.at(j) == stringLisst.back())
                        sum++;
                }
            }
            if (sum == 0)
                fkpSpeciality.append(stringLisst.back());
            sum = 0;
        }
    }
    stringLisst.clear();
    for (int i = 0; i < sizeVector; i++)
    {
        if (fac.at(i) == "ФИТУ")
        {
            stringLisst.append(spec.at(i));
            if (stringLisst.size() > 1)
            {
                for (int j = 0; j < stringLisst.size() - 1; j++)
                {
                    if (stringLisst.at(j) == stringLisst.back())
                        sum++;
                }
            }
            if (sum == 0)
                fituSpeciality.append(stringLisst.back());
            sum = 0;
        }
    }
    stringLisst.clear();
    for (int i = 0; i < sizeVector; i++)
    {
        if (fac.at(i) == "ВФ")
        {
            stringLisst.append(spec.at(i));
            if (stringLisst.size() > 1)
            {
                for (int j = 0; j < stringLisst.size() - 1; j++)
                {
                    if (stringLisst.at(j) == stringLisst.back())
                        sum++;
                }
            }
            if (sum == 0)
                vfSpeciality.append(stringLisst.back());
            sum = 0;
        }
    }
    stringLisst.clear();
    for (int i = 0; i < sizeVector; i++)
    {
        if (fac.at(i) == "ФРЭ")
        {
            stringLisst.append(spec.at(i));
            if (stringLisst.size() > 1)
            {
                for (int j = 0; j < stringLisst.size() - 1; j++)
                {
                    if (stringLisst.at(j) == stringLisst.back())
                        sum++;
                }
            }
            if (sum == 0)
                freSpeciality.append(stringLisst.back());
            sum = 0;
        }
    }
    stringLisst.clear();
    for (int i = 0; i < sizeVector; i++)
    {
        if (fac.at(i) == "КСиС")
        {
            stringLisst.append(spec.at(i));
            if (stringLisst.size() > 1)
            {
                for (int j = 0; j < stringLisst.size() - 1; j++)
                {
                    if (stringLisst.at(j) == stringLisst.back())
                        sum++;
                }
            }
            if (sum == 0)
                ksisSpeciality.append(stringLisst.back());
            sum = 0;
        }
    }
    stringLisst.clear();
    for (int i = 0; i < sizeVector; i++)
    {
        if (fac.at(i) == "ФИК")
        {
            stringLisst.append(spec[i]);
            if (stringLisst.size() > 1)
            {
                for (int j = 0; j < stringLisst.size() - 1; j++)
                {
                    if (stringLisst[j] == stringLisst.back())
                        sum++;
                }
            }
            if (sum == 0)
                ficSpeciality.append(stringLisst.back());
            sum = 0;
        }
    }
    stringLisst.clear();
    for (int i = 0; i < sizeVector; i++)
    {
        if (fac.at(i) == "ИЭФ")
        {
            stringLisst.append(spec[i]);
            if (stringLisst.size() > 1)
            {
                for (int j = 0; j < stringLisst.size() - 1; j++)
                {
                    if (stringLisst.at(j) == stringLisst.back())
                        sum++;
                }
            }
            if (sum == 0)
                iefSpeciality.append(stringLisst.back());
            sum = 0;
        }
    }
    stringLisst.clear();
    for (int i = 0; i < sizeVector; i++)
    {
        if (fac.at(i) == "ИКТ")
        {
            stringLisst.append(spec[i]);
            if (stringLisst.size() > 1)
            {
                for (int j = 0; j < stringLisst.size() - 1; j++)
                {
                    if (stringLisst.at(j) == stringLisst.back())
                        sum++;
                }
            }
            if (sum == 0)
                iktSpeciality.append(stringLisst.back());
            sum = 0;
        }
    }
    QVector <QString> vectorString;
    QVector <QStringList> vectorStringList;
    vectorString.append("ФКП");
    vectorString.append("ФИТУ");
    vectorString.append("ВФ");
    vectorString.append("ФРЭ");
    vectorString.append("КСиС");
    vectorString.append("ФИК");
    vectorString.append("ИЭФ");
    vectorString.append("ИКТ");
    vectorStringList.append(fkpSpeciality);
    vectorStringList.append(fituSpeciality);
    vectorStringList.append(vfSpeciality);
    vectorStringList.append(freSpeciality);
    vectorStringList.append(ksisSpeciality);
    vectorStringList.append(ficSpeciality);
    vectorStringList.append(iefSpeciality);
    vectorStringList.append(iktSpeciality);
    QStringList thisList;
    for (int i = 0; i < vectorString.size(); i++)
        if (vectorString.at(i) == arg1)
            for (int j = 0; j < vectorStringList.at(i).size(); j++)
                ui->boxSpeciality->addItem(vectorStringList.at(i).at(j));
}

void AddGroupWindow::on_boxSpeciality_currentIndexChanged(const QString &arg1)
{
    ui->boxGroup->clear();
    ui->boxGroup->addItems(obj.findGroup(ui->boxFaculty->currentText(), ui->boxSpeciality->currentText(), ui->boxYear->currentText()));
}


void AddGroupWindow::on_buttonSearch_2_clicked()
{
    temp.loadData();
    obj.loadData();
    Group group;
    temp.addGroup(obj.findGroup(ui->boxGroup->currentText()), temp.getNameActiveUser());
    this->close();
    emit addGroupSignal();
}


void AddGroupWindow::on_buttonSearch_clicked()
{
    temp.loadData();
    obj.loadData();
    Group findGroup = obj.findGroup(ui->searchGroupText->text());
    if (findGroup.getNumberGroup() == "")
    {
        QMessageBox::critical(this, "", "Такой группы не существует");
        return;
    }
    else
    {
        temp.addGroup(findGroup, temp.getNameActiveUser());
        this->close();
    }
    emit addGroupSignal();
}

