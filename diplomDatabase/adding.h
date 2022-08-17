#ifndef ADDING_H
#define ADDING_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>


namespace Ui {
class adding;
}

class adding : public QDialog
{
    Q_OBJECT

public:
    explicit adding(QWidget *parent = nullptr);
    ~adding();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::adding *ui;
    QSqlDatabase db;
    QSqlQuery query;
};

#endif // ADDING_H
