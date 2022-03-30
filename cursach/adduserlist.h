#ifndef ADDUSERLIST_H
#define ADDUSERLIST_H
#include <QList>
#include "addgroupclass.h"
#include <QSqlQuery>

class AddUserList
{
private:
    QList <AddGroupClass> data;
    int activeUser;
public:
    AddUserList();
    int getActiveUser();
    QString getNameActiveUser ();
    QString getNameActiveUser (int index);
    void loadData ();
    QList <AddGroupClass> getData ();
    void addGroup (Group group, QString user);
    void setActiveIndex (int index);
    void addLogin (QString login, QString password);
    void removeGroup (QString number, QString user);
};

#endif // ADDUSERLIST_H
