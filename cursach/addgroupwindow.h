#ifndef ADDGROUPWINDOW_H
#define ADDGROUPWINDOW_H

#include <QDialog>
#include <QVector>
#include<QMap>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include "adduserlist.h"
#include "listgroup.h"
namespace Ui {
class AddGroupWindow;
}

class AddGroupWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddGroupWindow(QWidget *parent = nullptr);
    ~AddGroupWindow();

signals:
    void addGroupSignal();

private slots:
    void on_boxFaculty_currentIndexChanged(const QString &arg1);
    void on_boxSpeciality_currentIndexChanged(const QString &arg1);
    void on_buttonSearch_2_clicked();
    void on_buttonSearch_clicked();
private:
    Ui::AddGroupWindow *ui;
    ListGroup obj;
    AddUserList temp;
};

#endif // ADDGROUPWINDOW_H
