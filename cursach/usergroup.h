#ifndef USERGROUP_H
#define USERGROUP_H
#include "group.h"
#include <QSqlQuery>
#include "db.h"

class UserGroup
{
private:
    db DB;
    std::vector <std::vector<Group>> data;
    std::vector <QString> nameUser;
    std::vector <QString> password;
    int activeIndex;
public:
    UserGroup();
    std::vector <std::vector<Group>> getListData ();
    std::vector <QString> getNameUser ();
    std::vector <QString> getPassword ();
    int getActiveIndex ();
    void setActiveIndex (int index);
    void loadData ();
    void addUser (QString login, QString password);
    void removeGroup (QString group);
    QString getActiveUser ();
    QString getThisUser (int index);
    QStringList getThisGroup (int index);
    int getIdUser (QString user);
    void addGroup (int idUser, QString group, QString fac, QString spec, QString year);
};
#endif // USERGROUP_H
