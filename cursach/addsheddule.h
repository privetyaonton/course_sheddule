#ifndef ADDSHEDDULE_H
#define ADDSHEDDULE_H

#include <QDialog>
#include "class.h"
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include "listgroup.h"
#include "listclass.h"

namespace Ui {
class AddSheddule;
}

class AddSheddule : public QDialog
{
    Q_OBJECT

public:
    explicit AddSheddule(QWidget *parent = nullptr);
    ~AddSheddule();


public slots:
    void on_enter_clicked();

private:
    Ui::AddSheddule *ui;
    ListGroup obj;
    ListClass temp;
};

#endif // ADDSHEDDULE_H
