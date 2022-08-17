#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <mainwindow.h>
#include <registration.h>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:

    void on_regbt_clicked();

    void on_loginbt_clicked();

private:
    Ui::login *ui;
    Registration reg;
    MainWindow *window;
    QSqlDatabase myDB,db;
    QSqlTableModel model;
    QSqlQuery *query;
};
#endif // LOGIN_H
