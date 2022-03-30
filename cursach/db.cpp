#include "db.h"

db::db()
{
    QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("/Users/antonrozhkov/DATABASE/dataBase.db");
    if (!DB.open())
        qDebug () << DB.lastError();
}
