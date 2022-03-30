#ifndef LISTGROUP_H
#define LISTGROUP_H
#include <QList>
#include "group.h"
#include <QSqlQuery>Q

class ListGroup
{
private:
    QList <Group> data;
public:
    ListGroup();
    QList <Group> getData ();
    void loadData ();
    void clearData ();
    QStringList findGroup (QString fac, QString spec, QString year);
    void appendData (Group group);
    Group findGroup (QString number);
};

#endif // LISTGROUP_H
