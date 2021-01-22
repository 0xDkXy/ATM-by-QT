#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QString>
#include "logindialog.h"
#include <QFile>

namespace Ui {
class registerDialog;
}

class registerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit registerDialog(QWidget *parent = nullptr);
    ~registerDialog();
    void sentData(QString data);

private slots:
    void on_pushButton_clicked();

    void on_exitBtn_clicked();

    void on_confirBtn_clicked();

private:
    Ui::registerDialog *ui;
    QString usr;

};

#endif // REGISTERDIALOG_H
