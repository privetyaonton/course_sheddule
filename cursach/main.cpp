#include "mainwindow.h"

#include <QApplication>
#include <QTextEdit>
#include <QLabel>
#include "db.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    db dataBase;
    MainWindow w;
    return a.exec();
}
