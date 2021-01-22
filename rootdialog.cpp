#include "rootdialog.h"
#include "ui_rootdialog.h"
#include <QFile>
#include <QTextStream>
#include <logindialog.h>

rootDialog::rootDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rootDialog)
{
    ui->setupUi(this);
}

rootDialog::~rootDialog()
{
    delete ui;
}

void rootDialog::fileRemove()
{
    QFile file("data.dat");
    file.remove();
}

void rootDialog::on_clearBtn_clicked()
{
    fileRemove();
}

void rootDialog::on_outputBtn_clicked()
{
    QFile file("data.dat");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    QString kepData = in.readAll();
    ui->textEdit->setText(kepData);
    file.close();
}

void rootDialog::on_exitBtn_clicked()
{
    loginDialog *login = new loginDialog;
    login->show();
    this->close();
}
