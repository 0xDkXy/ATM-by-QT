#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QString>
#include <QFile>
#include <QTextStream>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = nullptr);
    ~loginDialog();

private slots:
    void on_loginBtn_clicked();

    void on_signUpBtn_clicked();

private:
    Ui::loginDialog *ui;
    bool check(QString usr, QString pwd);
    void fileRemove();
};

#endif // LOGINDIALOG_H
