#ifndef REMOVESHEDDULEWINDOW_H
#define REMOVESHEDDULEWINDOW_H

#include <QDialog>
#include <QSqlQuery>
#include "db.h"

namespace Ui {
class RemoveShedduleWindow;
}

class RemoveShedduleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveShedduleWindow(QWidget *parent = nullptr);
    ~RemoveShedduleWindow();

private:
    Ui::RemoveShedduleWindow *ui;
};

#endif // REMOVESHEDDULEWINDOW_H
