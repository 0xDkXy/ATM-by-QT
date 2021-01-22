#include "registerdialog.h"
#include "ui_registerdialog.h"
#include <QMessageBox>
#include <QTextStream>

registerDialog::registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerDialog)
{
    ui->setupUi(this);
}

registerDialog::~registerDialog()
{
    delete ui;
}

void registerDialog::sentData(QString data)
{
    usr = data;
//    ui->welcomeLabel->setText("welcome " + usr);
}

void registerDialog::on_pushButton_clicked()
{

}

void registerDialog::on_exitBtn_clicked()
{
    loginDialog *login = new loginDialog;
    this->close();
    login->show();
}

void registerDialog::on_confirBtn_clicked()
{
    if(ui->pwdComfirEdit->text() == ui->pwdEdit->text()) {
        QString usrName = ui->usrEdit->text();
        QString pwd = ui->pwdEdit->text();
        QFile file("data.dat");
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out.setCodec("UTF-8");
        out << usrName << "\n" << pwd << "\n" <<  0 << "\n";
        file.close();
        QMessageBox::warning(this, tr("Success"), tr("成功"), QMessageBox::Yes);
    } else {
        QMessageBox::warning(this, tr("Waring"),
                                     tr("密码不一样"),
                                     QMessageBox::Yes);
        ui->usrEdit->clear();
        ui->pwdEdit->clear();
        ui->pwdComfirEdit->clear();
        ui->usrEdit->setFocus();
    }

}
