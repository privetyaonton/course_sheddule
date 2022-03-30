#include "usergroup.h"

UserGroup::UserGroup()
{

}

std::vector<std::vector<Group>> UserGroup::getListData()
{
    return data;
}

std::vector<QString> UserGroup::getNameUser()
{
    return nameUser;
}

int UserGroup::getActiveIndex()
{
    return activeIndex;
}

std::vector<QString> UserGroup::getPassword()
{
    return password;
}

void UserGroup::loadData()
{
    data.clear();
    nameUser.clear();
    password.clear();
    activeIndex = -1;
    QSqlQuery queryGroup, queryUser;
    int i = 0;
    Group group;
    queryGroup.exec("SELECT * FROM addGroup");
    queryUser.exec("SELECT * FROM userTable");
    std::vector<Group> adddata;
    while (queryUser.next())
    {
        data.push_back(adddata);
        nameUser.push_back(queryUser.value(0).toString());
        password.push_back(queryUser.value(1).toString());
        if (queryUser.value(2).toString() == "1")
            setActiveIndex(i);
        i++;
    }
    for (int i = 0; i < nameUser.size(); i++)
    {
        queryGroup.next();
        if (queryGroup.value(1).toString() == nameUser[i])
        {
            group.setFaculty(queryGroup.value(2).toString());
            group.setNumberGroup(queryGroup.value(0).toString());
            group.setSpeciality(queryGroup.value(3).toString());
            group.setYearOfAdmission(queryGroup.value(4).toString());
            data[i].push_back(group);
        }
    }
}

void UserGroup::addUser(QString login, QString password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO userTable VALUES (?, ?, 0");
    query.addBindValue(login);
    query.addBindValue(password);
    nameUser.push_back(login);
    password.push_back(password);
}

void UserGroup::removeGroup(QString group)
{
    QSqlQuery query;
    int index = 0;
    query.prepare("SELECT numberGroup FROM addGroup WHERE user = ?");
    query.addBindValue(nameUser[activeIndex]);
    query.exec();
    while (query.next())
    {
        if (query.value(0).toString() == group)
            break;
        index++;
    }
    query.prepare("DELETE FROM addGroup WHERE numberGroup = ?");
    query.addBindValue(group);
    query.exec();
    data[activeIndex].erase(data[activeIndex].begin() + index);
}

QString UserGroup::getActiveUser()
{
    return nameUser[activeIndex];
}

QStringList UserGroup::getThisGroup(int index)
{
    QStringList temp;
    for (int i = 0; i < data[index].size(); i++)
    {
        temp.append(data[index][i].getNumberGroup());
    }
    return temp;
}

int UserGroup::getIdUser(QString user)
{
    for (int i = 0; i < nameUser.size(); i++)
    {
        if (nameUser[i] == user)
            return i;
    }
    return -1;
}

void UserGroup::setActiveIndex(int index)
{
    activeIndex = index;
    QSqlQuery query;
    query.prepare("UPDATE userTable SET correct = 1 WHERE login = ?");
    query.addBindValue(getThisUser(index));
    query.exec();
}

QString UserGroup::getThisUser(int index)
{
    return nameUser[index];
}

void UserGroup::addGroup(int idUser, QString group, QString fac, QString spec, QString year)
{
    QSqlQuery query;
    query.prepare("INSERT INTO addGroup VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(group);
    query.addBindValue(getThisUser(idUser));
    query.addBindValue(fac);
    query.addBindValue(spec);
    query.addBindValue(year);
    query.exec();
    Group temp;
    temp.setFaculty(fac);
    temp.setNumberGroup(group);
    temp.setSpeciality(spec);
    temp.setYearOfAdmission(year);
    data[idUser].push_back(temp);
}
