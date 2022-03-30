#ifndef INFOGROUPWINDOW_H
#define INFOGROUPWINDOW_H

#include <QDialog>
#include "group.h"

namespace Ui {
class InfoGroupWindow;
}

class InfoGroupWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InfoGroupWindow(QWidget *parent = nullptr);
    ~InfoGroupWindow();

private slots:
    void on_pushButton_clicked();

public slots:
    void viewInfo (Group group);

private:
    Ui::InfoGroupWindow *ui;
};

#endif // INFOGROUPWINDOW_H
