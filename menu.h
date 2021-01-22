#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "savewithdrawaldialog.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
    void sentData(QString data);

private slots:
    void on_exit_clicked();

    void on_saveWithdrawal_clicked();

    void on_transfer_clicked();

    void on_changePwd_clicked();

private:
    Ui::menu *ui;
    QString usr;
};

#endif // MENU_H
