#include "listgroup.h"

ListGroup::ListGroup()
{
    data.clear();
    loadData();
}

void ListGroup::loadData()
{
    QSqlQuery query;
    query.exec("SELECT * FROM 'Group'");
    Group group;
    while (query.next())
    {
        group.setFaculty(query.value(2).toString());
        group.setNumberGroup(query.value(0).toString());
        group.setSpeciality(query.value(3).toString());
        group.setYearOfAdmission(query.value(1).toString());
        data.append(group);
    }
}

QList <Group> ListGroup::getData()
{
    return data;
}

void ListGroup::clearData()
{
    data.clear();
}

QStringList ListGroup::findGroup(QString fac, QString spec, QString year)
{
    QSqlQuery query;
    query.prepare("SELECT numberGroup FROM 'Group' WHERE faculty = ? AND speciality = ? AND yearOfAdmission = ?");
    query.addBindValue(fac);
    query.addBindValue(spec);
    query.addBindValue(year);
    query.exec();
    QStringList temp;
    while (query.next())
    {
        temp.append(query.value(0).toString());
    }
    return temp;
}

void ListGroup::appendData(Group group)
{
    data.append(group);
}

