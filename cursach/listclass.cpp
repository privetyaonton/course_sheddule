#include "listclass.h"

ListClass::ListClass()
{
    data.clear();
    sizeData = 0;
}

QList <Class> ListClass::getData()
{
    return data;
}

void ListClass::loadData()
{
    Class temp;
    QSqlQuery query;
    query.exec("SELECT * FROM Class");
    data.clear();
    int i = 0;
    while (query.next())
    {
        temp.setNumberClass(query.value(0).toInt());
        temp.setWeekOne(query.value(1).toInt());
        temp.setWeekTwo(query.value(2).toInt());
        temp.setWeekThree(query.value(3).toInt());
        temp.setWeekFour(query.value(4).toInt());
        temp.setTypeClass(query.value(5).toString());
        temp.setSubGroupFirst(query.value(6).toInt());
        temp.setSubGroupSecond(query.value(7).toInt());
        temp.setNameTeacher(query.value(8).toString());
        temp.setNumberAuditory(query.value(9).toString());
        temp.setNameItem(query.value(10).toString());
        temp.setNumberGroup(query.value(11).toString());
        temp.setMonday(query.value(12).toInt());
        temp.setTuesday(query.value(13).toInt());
        temp.setWednesday(query.value(14).toInt());
        temp.setThursday(query.value(15).toInt());
        temp.setFriday(query.value(16).toInt());
        temp.setSaturday(query.value(17).toInt());
        temp.setId(i);
        i++;
        data.append(temp);
    }
    sizeData = i;
}

void ListClass::addSheddule(Class count)
{
    QSqlQuery query, querySecond;
    data.clear();
    query.prepare("INSERT INTO Class VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(count.getNumberClass());
    query.addBindValue(count.getWeekOne());
    query.addBindValue(count.getWeekTwo());
    query.addBindValue(count.getWeekThree());
    query.addBindValue(count.getWeekFour());
    query.addBindValue(count.getTypeClass());
    query.addBindValue(count.getSubGroupFirst());
    query.addBindValue(count.getSubGroupSecond());
    query.addBindValue(count.getNameTeacher());
    query.addBindValue(count.getNumberAuditory());
    query.addBindValue(count.getNameItem());
    query.addBindValue(count.getNumberGroup());
    query.addBindValue(count.getMonday());
    query.addBindValue(count.getTuesday());
    query.addBindValue(count.getWednesday());
    query.addBindValue(count.getThursday());
    query.addBindValue(count.getFriday());
    query.addBindValue(count.getSaturday());
    query.addBindValue(sizeData);
    sizeData++;
    query.exec();
    data.append(count);
    querySecond.exec("SELECT id FROM Class");
    int i = 0;
    while (querySecond.next())
    {
        query.prepare("UPDATE Class SET id = ? WHERE id = ?");
        query.addBindValue(i);
        query.addBindValue(querySecond.value(0).toInt());
        query.exec();
        i++;
    }
}

void ListClass::removeSheddule(int id)
{
    QSqlQuery query, querySecond;
    int i = 0;
    query.prepare("DELETE FROM Class WHERE id = ?");
    querySecond.exec("SELECT id FROM Class");
    while (querySecond.next())
    {
        if (id == i)
        {
            query.addBindValue(querySecond.value(0).toInt());
            query.exec();
            break;
        }
        i++;
    }
    query.exec();
    loadData();
}
