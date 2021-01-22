#ifndef SAVEWITHDRAWALDIALOG_H
#define SAVEWITHDRAWALDIALOG_H

#include <QDialog>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "menu.h"

namespace Ui {
class saveWithdrawalDialog;
}

class saveWithdrawalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit saveWithdrawalDialog(QWidget *parent = nullptr);
    ~saveWithdrawalDialog();
    void sentData(QString data);

private slots:
    void on_exitBtn_clicked();

    void on_saveBtn_clicked();

    void on_withdrawBtn_clicked();

private:
    Ui::saveWithdrawalDialog *ui;
    QString usr;
    double keepMoney=0;
    void keepData_read();
    void keepData_write(QString data);
};

#endif // SAVEWITHDRAWALDIALOG_H
