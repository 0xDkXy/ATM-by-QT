#include "pwdchangedialog.h"
#include "ui_pwdchangedialog.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "menu.h"
#include <QDebug>

pwdChangeDialog::pwdChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pwdChangeDialog)
{
    ui->setupUi(this);
}

pwdChangeDialog::~pwdChangeDialog()
{
    delete ui;
}

void pwdChangeDialog::sentData(QString data)
{
    usr = data;
    QFile file("data.dat");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    while(!in.atEnd()){
        QString lineinf = in.readLine();
        if(lineinf == usr) {
            QString oldpwd = in.readLine();
            pwd = oldpwd;
            break;
        }
    }
    file.close();
}

void pwdChangeDialog::on_exitBtn_clicked()
{
    menu *m = new menu;
    m->sentData(usr);
    this->close();
    m->show();
}

void pwdChangeDialog::keepData_read()
{
    QFile file("data.dat");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    QString kepData = "";
    while(!in.atEnd()){
        QString lineinf = in.readLine();
        if(lineinf == usr){
            kepData += lineinf;
            kepData += "\n";
            lineinf = in.readLine();
            lineinf = pwd;
            kepData += lineinf;
            kepData += "\n";
        }else{
            kepData += lineinf;
            kepData += "\n";
        }
    }
    file.remove();
    file.close();
    keepData_write(kepData);
    qDebug() << kepData.toLatin1() << "\n";
}

void pwdChangeDialog::keepData_write(QString data)
{
    QFile file("data.dat");
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out << data;
    file.close();
}

void pwdChangeDialog::on_confirBtn_clicked()
{
    if(ui->oldEdit->text() == pwd){
        if (ui->newEdit->text() == ui->repeatEdit->text() ){
            pwd = ui->newEdit->text();
            keepData_read();
            ui->comfirlabel->setText("修改成功");
        }else{
            QMessageBox::warning(this, tr("Waring"),
                                         tr("新密码不一致"),
                                         QMessageBox::Yes);
            ui->newEdit->clear();
            ui->newEdit->setFocus();
            ui->repeatEdit->clear();
        }
    } else {
        QMessageBox::warning(this, tr("Waring"),
                                     tr("原密码错误"),
                                     QMessageBox::Yes);
        ui->oldEdit->clear();
        ui->oldEdit->setFocus();
    }
}
