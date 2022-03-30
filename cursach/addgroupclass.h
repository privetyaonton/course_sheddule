#ifndef ADDGROUPCLASS_H
#define ADDGROUPCLASS_H
#include "listgroup.h"
#include <QString>
#include <QDebug>
#include <QSqlError>

class AddGroupClass : public ListGroup
{
private:
    QString nameUser;
    QString password;
    int id;
public:
    AddGroupClass();
    int getId ();
    QString getNameUser();
    QString getPassword ();
    void setNameUser (QString user);
    void setPassword (QString pass);
    void setId (int ID);
};

#endif // ADDGROUPCLASS_H
