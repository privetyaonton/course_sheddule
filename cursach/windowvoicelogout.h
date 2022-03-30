#ifndef WINDOWVOICELOGOUT_H
#define WINDOWVOICELOGOUT_H

#include <QDialog>

namespace Ui {
class WindowVoiceLogOut;
}

class WindowVoiceLogOut : public QDialog
{
    Q_OBJECT

public:
    explicit WindowVoiceLogOut(QWidget *parent = nullptr);
    ~WindowVoiceLogOut();

 signals:
    void logOut();

private slots:
    void on_pushyes_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::WindowVoiceLogOut *ui;
};

#endif // WINDOWVOICELOGOUT_H
