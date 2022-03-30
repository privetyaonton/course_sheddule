#include "adduserlist.h"

AddUserList::AddUserList()
{
    activeUser = -1;
}

int AddUserList::getActiveUser()
{
    return activeUser;
}

QString AddUserList::getNameActiveUser()
{
    loadData();
    int index = getActiveUser();
    return data[index].getNameUser();
}

QString AddUserList::getNameActiveUser(int index)
{
    return data[index].getNameUser();
}

void AddUserList::loadData()
{
    QSqlQuery queryGroup;
    QSqlQuery query;
    AddGroupClass temp;
    Group group;
    query.exec("SELECT * FROM userTable");
    int i = 0;
    data.clear();
    while (query.next())
    {
        queryGroup.prepare("SELECT * FROM addGroup WHERE user = ?");
        queryGroup.addBindValue(query.value(0).toString());
        queryGroup.exec();
        if (query.value(2).toString() == "1")
            activeUser = i;
        temp.clearData();
        while (queryGroup.next())
        {
            group.setFaculty(queryGroup.value(2).toString());
            group.setNumberGroup(queryGroup.value(0).toString());
            group.setSpeciality(queryGroup.value(3).toString());
            group.setYearOfAdmission(queryGroup.value(4).toString());
            temp.appendData(group);
        }
        temp.setNameUser(query.value(0).toString());
        temp.setPassword(query.value(1).toString());
        i++;
        data.append(temp);
    }
}

QList <AddGroupClass> AddUserList::getData()
{
    return data;
}

void AddUserList::addGroup(Group group, QString user)
{
    QSqlQuery query, queryPassword;
    query.prepare ("SELECT numberGroup, user FROM addGroup WHERE numberGroup = ? AND user = ?");
    query.addBindValue(group.getNumberGroup());
    query.addBindValue(user);
    query.exec();
    query.next();
    if (query.value(0).toString() != "")
        return;
    query.prepare("INSERT INTO addGroup VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(group.getNumberGroup());
    query.addBindValue(user);
    query.addBindValue(group.getFaculty());
    query.addBindValue(group.getSpeciality());
    query.addBindValue(group.getYearOfAdmission());
    query.exec();
    AddGroupClass temp;
    queryPassword.prepare("SELECT password, id FROM userTable WHERE login = ?");
    queryPassword.addBindValue(user);
    queryPassword.exec();
    queryPassword.next();
    temp.setNameUser(user);
    temp.setPassword(queryPassword.value(0).toString());
    temp.setId (queryPassword.value(1).toInt());
    temp.appendData(group);
    data.append(temp);
}

void AddUserList::setActiveIndex(int index)
{
    activeUser = index;
    QSqlQuery query;
    int i = 0;
    query.prepare("UPDATE userTable SET correct = 1 WHERE login = ?");
    query.addBindValue(getNameActiveUser(index));
    query.exec();
    query.prepare("UPDATE userTable SET correct = 0 WHERE NOT login = ?");
    query.addBindValue(getNameActiveUser(index));
    query.exec();
}

void AddUserList::addLogin(QString login, QString password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO userTable (login, password, correct) VALUES (?, ?, 0)");
    query.addBindValue(login);
    query.addBindValue(password);
    query.exec();
    AddGroupClass obj;
    obj.setNameUser(login);
    obj.setPassword(password);
    data.append(obj);
}

void AddUserList::removeGroup(QString number, QString user)
{
    QSqlQuery query;
    query.prepare("DELETE FROM addGroup WHERE numberGroup = ? AND user = ?");
    query.addBindValue(number);
    query.addBindValue(user);
    query.exec();
    loadData();
}
