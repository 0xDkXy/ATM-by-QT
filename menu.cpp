#include "menu.h"
#include "ui_menu.h"
#include "logindialog.h"
#include "transferdialog.h"
#include "pwdchangedialog.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::sentData(QString data)
{
    usr = data;
    ui->welcomeLable->setText("welcome " + usr + "!");
}

void menu::on_exit_clicked()
{
    loginDialog *login = new loginDialog;
    this->close();
    login->show();
}

void menu::on_saveWithdrawal_clicked()
{
    saveWithdrawalDialog *s = new saveWithdrawalDialog;
    s->sentData(usr);
    this->close();
    s->show();
}

void menu::on_transfer_clicked()
{
    transferDialog *tran = new transferDialog;
    tran->sentData(usr);
    this->close();
    tran->show();
}

void menu::on_changePwd_clicked()
{
    pwdChangeDialog *pwdCha = new pwdChangeDialog;
    pwdCha->sentData(usr);
    this->close();
    pwdCha->show();
}
