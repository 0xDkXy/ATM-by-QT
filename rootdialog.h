#ifndef ROOTDIALOG_H
#define ROOTDIALOG_H

#include <QDialog>

namespace Ui {
class rootDialog;
}

class rootDialog : public QDialog
{
    Q_OBJECT

public:
    explicit rootDialog(QWidget *parent = nullptr);
    ~rootDialog();

private slots:
    void on_clearBtn_clicked();

    void on_outputBtn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::rootDialog *ui;
    void fileRemove();
};

#endif // ROOTDIALOG_H
