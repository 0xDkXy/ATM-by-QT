#ifndef PWDCHANGEDIALOG_H
#define PWDCHANGEDIALOG_H

#include <QDialog>
#include <QString>
namespace Ui {
class pwdChangeDialog;
}

class pwdChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit pwdChangeDialog(QWidget *parent = nullptr);
    ~pwdChangeDialog();
    void sentData(QString data);
    void keepData_read();
    void keepData_write(QString data);


private slots:
    void on_exitBtn_clicked();

    void on_confirBtn_clicked();

private:
    Ui::pwdChangeDialog *ui;
    QString usr, pwd;
};

#endif // PWDCHANGEDIALOG_H
