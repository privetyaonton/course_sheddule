#include "addgroupclass.h"

AddGroupClass::AddGroupClass()
{
    id = 0;
    nameUser ="";
    password = "";
}

int AddGroupClass::getId ()
{
    return id;
}

QString AddGroupClass::getNameUser()
{
    return nameUser;
}

QString AddGroupClass::getPassword()
{
    return password;
}

void AddGroupClass::setNameUser(QString user)
{
    nameUser = user;
}

void AddGroupClass::setPassword(QString pass)
{
    password = pass;
}

void AddGroupClass::setId(int ID)
{
    id = ID;
}

Group ListGroup::findGroup(QString number)
{
    QSqlQuery query;
    query.prepare("SELECT yearOfAdmission, faculty, speciality FROM 'Group' WHERE numberGroup = ?");
    query.addBindValue(number);
    if (!query.exec())
        qDebug() << query.lastError();
    Group group;
    QString fac, spec, year;
    query.next();
    fac = query.value(1).toString();
    spec = query.value(2).toString();
    year = query.value(0).toString();
    group.setFaculty(fac);
    group.setNumberGroup(number);
    group.setSpeciality(spec);
    group.setYearOfAdmission(year);
    return group;
}
