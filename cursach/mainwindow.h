#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "windowsigninuser.h"
#include "addgroupwindow.h"
#include "windowvoicelogout.h"
#include <QString>
#include <QMessageBox>
#include <QLabel>
#include <QStringList>
#include <QRadioButton>
#include <QPushButton>
#include <QVBoxLayout>
#include "group.h"
#include <vector>
#include <QThread>
#include "class.h"
#include "adduserlist.h"
#include "addsheddule.h"
#include "listclass.h"
#include "infogroupwindow.h"
#include "listgroup.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void outputListGroup();
    void goToComboBox (QString year, QString faculty);
    void dayConverting (int day);
    void goToViewInfo (Group group);

private slots:
    void addGroupWidgetTable();
    void on_logIn_clicked();
    void on_addGroup_clicked();
    void on_removeGroup_clicked();
    void changeNameButton();
    void logOutMain ();
    void on_logOut_clicked();
    void editListOfGroup(QString number, QString faculty, QString speciality, QString year, int idUser);
    void on_acceptFilterButton_clicked();
    void on_searchGroup_clicked();
    void on_addItem_clicked();
    void viewShedduleTable (int day);
    void on_buttonMonday_clicked();
    void on_buttonTuesday_clicked();
    void on_buttonWednesday_clicked();
    void on_buttonThursday_clicked();
    void on_buttonFriday_clicked();
    void on_buttonSaturday_clicked();
    void on_deleteItem_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow* ui;
    AddUserList temp;
    WindowSignInUser *signIn;
    AddGroupWindow *addGroup;
    WindowVoiceLogOut *logOut;
    WindowLogIn *logIn;
    AddSheddule *addSheddule;
    InfoGroupWindow *infoWindow;
    ListClass obj;
    ListGroup listGroup;
};
#endif // MAINWINDOW_H
