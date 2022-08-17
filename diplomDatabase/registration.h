#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>



namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Registration *ui;
    QSqlDatabase db;
    QSqlQuery query;
};

#endif // REGISTRATION_H
