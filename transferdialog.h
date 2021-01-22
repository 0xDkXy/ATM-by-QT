#ifndef TRANSFERDIALOG_H
#define TRANSFERDIALOG_H

#include <QDialog>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class transferDialog;
}

class transferDialog : public QDialog
{
    Q_OBJECT

public:
    explicit transferDialog(QWidget *parent = nullptr);
    ~transferDialog();
    void sentData(QString data);

private slots:
    void on_comfirBtn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::transferDialog *ui;
    QString usr,aimUsr;
    double keepMoney=0,aimMoney=0;
    void keepData_read();
    void keepData_write(QString data);
};

#endif // TRANSFERDIALOG_H
