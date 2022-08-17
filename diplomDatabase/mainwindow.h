#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDate>
#include <QMouseEvent>
#include <QDir>
#include <adding.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();

    void on_btnRemove_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_btnRefresh_clicked();

    void on_dataSearch_clicked();

    void on_nameSearch_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase myDB;
    QSqlTableModel *model;
    QSqlQuery *query;
    int currentRow;
    adding adding;
    QDate date;
    QSqlQueryModel              *modelMain;
    QSqlQueryModel              *modelDevice;
    int datas = 0;
};

#endif // MAINWINDOW_H
