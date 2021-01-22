#include "logindialog.h"
#include "ui_logindialog.h"
#include "registerdialog.h"
#include "menu.h"
#include <QDebug>
#include <QMessageBox>
#include "rootdialog.h"

void loginDialog::fileRemove()
{
    QFile file("data.dat");
    file.remove();
}

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
//    fileRemove();
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_loginBtn_clicked()
{
    QString usr = ui->userEdit->text();
    QString pwd = ui->pwdEdit->text();
    if(check(usr, pwd)){
        menu *m = new menu;
        m->sentData(usr);
        m->show();
        this->close();
    } else if(usr == "root" &&
              pwd == "root"){
        this->close(); // 进入管理员界面
        rootDialog *r = new rootDialog;
        r->show();

    } else {
        QMessageBox::warning(this, tr("Waring"),
                                     tr("密码错误"),
                                     QMessageBox::Yes);
        ui->userEdit->clear();
        ui->pwdEdit->clear();
//        ui->pwdComfirEdit->clear();
        ui->userEdit->setFocus();
    }
}

void loginDialog::on_signUpBtn_clicked()
{
    registerDialog *reg = new registerDialog;
    this->close();
    reg->show();
}

bool loginDialog::check(QString usr, QString pwd)
{
    QFile file("data.dat");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!file.exists()) {
        qDebug() << "The file is not exist!" << "\n";
        return false;
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString lineInf = in.readLine();
        if(lineInf == usr){
            QString pwdInf = in.readLine();
            if(pwdInf == pwd){
                return 1;
            }
        }
    }
    return 0;
}
