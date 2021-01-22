#include "savewithdrawaldialog.h"
#include "ui_savewithdrawaldialog.h"
#include <QDebug>

saveWithdrawalDialog::saveWithdrawalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saveWithdrawalDialog)
{
    ui->setupUi(this);
}

saveWithdrawalDialog::~saveWithdrawalDialog()
{
    delete ui;
}

void saveWithdrawalDialog::keepData_read()
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
            lineinf = in.readLine();kepData += lineinf;kepData += "\n";
            lineinf = in.readLine();
            QString newData = QString::number(keepMoney, 'f', 2);
            newData += "\n";
            kepData += newData;
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

void saveWithdrawalDialog::keepData_write(QString data)
{
    QFile file("data.dat");
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out << data;
    file.close();
}

void saveWithdrawalDialog::sentData(QString data)
{
    usr = data;
    ui->usrLabel->setText("Hello! " + usr);
    QFile file("data.dat");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    while(!in.atEnd()){
        QString lineinf = in.readLine();
        if(lineinf == usr) {
            QString num = in.readLine();num.clear();num = in.readLine();
            ui->restLabel->setText(num + "元");
            double money = num.toDouble();
            keepMoney = money;
        }
    }
    file.close();
}

void saveWithdrawalDialog::on_exitBtn_clicked()
{
    menu *m = new menu;
    m->sentData(usr);
    this->close();
    m->show();
}

void saveWithdrawalDialog::on_saveBtn_clicked()
{
    QString str = ui->monEdit->text();
    double num = str.toDouble();
    keepMoney += num;
    str = QString::number(keepMoney, 'f', 2);
    ui->restLabel->setText(str + "元");
    keepData_read();
}

void saveWithdrawalDialog::on_withdrawBtn_clicked()
{
    QString str = ui->monEdit->text();
    double num = str.toDouble();
    if(num > keepMoney){
        QMessageBox::warning(this, tr("Waring"),
                                     tr("对不起,您没有这么多钱!"),
                                     QMessageBox::Yes);
        ui->monEdit->clear();
        ui->monEdit->setFocus();
    } else {
        keepMoney -= num;
        str = QString::number(keepMoney, 'f', 2);
        ui->restLabel->setText(str + "元");
        keepData_read();
    }
}
