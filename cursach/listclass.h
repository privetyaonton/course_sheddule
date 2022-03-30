#ifndef LISTCLASS_H
#define LISTCLASS_H
#include "class.h"
#include <QSqlQuery>
#include <QList>
#include <QDebug>
#include <QSqlError>

class ListClass
{
private:
    QList <Class> data;
    int sizeData;
public:
    ListClass();
    QList <Class> getData ();
    void loadData ();
    void addSheddule (Class count);
    void removeSheddule (int id);
    Class findClass (int id);
};

#endif // LISTCLASS_H
