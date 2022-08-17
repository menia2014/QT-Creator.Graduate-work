#include "mainwindow.h"
#include "ui_mainwindow.h"

#define Path_to_DB "./database/database.db"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);

    ui->fdateEdit->setDisplayFormat("dd.MM.yyyy");
    ui->ldateEdit->setDisplayFormat("dd.MM.yyyy");

    ui->fdateEdit->setDate(QDate::currentDate());
    ui->ldateEdit->setDate(QDate::currentDate());

    qDebug()<<QDir("./database").exists();

    if (myDB.open()) {
        qDebug("Open");
        query = new QSqlQuery(myDB);
        if (!myDB.tables().contains(QLatin1String("database"))) {
            query->exec("CREATE TABLE database (ID INTEGER PRIMARY KEY AUTOINCREMENT,name STRING  NOT NULL CHECK (name <> ''), amount INTEGER NOT NULL CHECK (amount <> '' AND typeof(amount) = 'integer'), price INTEGER NOT NULL CHECK (price <> '' AND typeof(price) = 'integer'), date DATE CHECK (date <> '') NOT NULL);");
        }
        model = new QSqlTableModel(this, myDB);
        model->setTable("database");
        model->select();
        model->setHeaderData(1,Qt::Horizontal,"Название",Qt::DisplayRole);
        model->setHeaderData(2,Qt::Horizontal,"Количество",Qt::DisplayRole);
        model->setHeaderData(3,Qt::Horizontal,"Цена",Qt::DisplayRole);
        model->setHeaderData(4,Qt::Horizontal,"Дата продажи",Qt::DisplayRole);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView->setColumnHidden(0, true);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableView->setSortingEnabled(true);
        ui->dateBox->setEnabled(false);
        ui->nameBox->setEnabled(false);
        QSqlQuery qry;
        if(qry.exec("SELECT SUM(price*amount) FROM database")){
            qDebug() << "robit!";
            qry.next();
            ui->label_4->setText("Полная стоимость продажи (кол-во*цена):"+qry.value(0).toString());
        }
    }

    else qDebug("Dont open");
    this->setWindowTitle("Система учёта продаж");

}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::on_btnAdd_clicked()
{
    //model->insertRow(model->rowCount()); //backup

    adding.setModal(true);
    adding.exec();

    model = new QSqlTableModel(this, myDB);
    model->setTable("database");
    model->select();
    model->setHeaderData(1,Qt::Horizontal,"Название",Qt::DisplayRole);
    model->setHeaderData(2,Qt::Horizontal,"Количество",Qt::DisplayRole);
    model->setHeaderData(3,Qt::Horizontal,"Цена",Qt::DisplayRole);
    model->setHeaderData(4,Qt::Horizontal,"Дата продажи",Qt::DisplayRole);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->selectRow(currentRow);;
    ui->searchLine->setText("");
    datas = 0;
    ui->dateBox->setChecked(false);
    ui->nameBox->setChecked(false);
    QSqlQuery qry;
    if(qry.exec("SELECT SUM(price*amount) FROM database")){
        qDebug() << "robit!";
        qry.next();
        ui->label_4->setText("Полная стоимость продажи (кол-во*цена):"+qry.value(0).toString());
    }
}


void MainWindow::on_btnRemove_clicked()
{

    QMessageBox msgBox;
    msgBox.setText(tr("Вы уверены, что хотите удалить запись?"));
    msgBox.setWindowTitle("Удаление");
    QAbstractButton* pButtonYes = msgBox.addButton(tr("Да"), QMessageBox::YesRole);
    msgBox.addButton(tr("Нет"), QMessageBox::NoRole);

    msgBox.exec();

    if (msgBox.clickedButton()==pButtonYes) {
        model->removeRow(currentRow);
        model->select();
        QSqlQuery qry;
        if(qry.exec("SELECT SUM(price*amount) FROM database")){
            qDebug() << "robit!";
            qry.next();
            ui->label_4->setText("Полная стоимость продажи (кол-во*цена):"+qry.value(0).toString());
        }
    }
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    currentRow = index.row();
}


void MainWindow::on_btnRefresh_clicked()
{
    model = new QSqlTableModel(this, myDB);
    model->setTable("database");
    model->select();
    model->setHeaderData(1,Qt::Horizontal,"Название",Qt::DisplayRole);
    model->setHeaderData(2,Qt::Horizontal,"Количество",Qt::DisplayRole);
    model->setHeaderData(3,Qt::Horizontal,"Цена",Qt::DisplayRole);
    model->setHeaderData(4,Qt::Horizontal,"Дата продажи",Qt::DisplayRole);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->selectRow(currentRow);;
    ui->searchLine->setText("");
    datas = 0;
    ui->dateBox->setChecked(false);
    ui->nameBox->setChecked(false);
    QSqlQuery qry;
    if(qry.exec("SELECT SUM(price*amount) FROM database")){
        qDebug() << "robit!";
        qry.next();
        ui->label_4->setText("Полная стоимость продажи (кол-во*цена):"+qry.value(0).toString());
    }
}

void MainWindow::on_dataSearch_clicked()
{
    //fdate = QDate().currentDate().toString(Qt::ISODate);
    if(ui->fdateEdit->text()>ui->ldateEdit->text()){
        QMessageBox::warning(this,"Ошибка даты!","Дата \"От\" не может привышать \"До\"");
        return;
    }
        if(ui->searchLine->text().size()==0){
            model->setFilter("date>=\'"+ui->fdateEdit->text()+"\' AND date<=\'"+ui->ldateEdit->text()+"\'");
            QSqlQuery qry;
            if(qry.exec("SELECT SUM(price*amount) FROM database where date>=\'"+ui->fdateEdit->text()+"\'AND date<=\'"+ui->ldateEdit->text()+"\'")){
                qDebug() << "robit!";
                qry.next();
                ui->label_4->setText("Полная стоимость продажи (кол-во*цена):"+qry.value(0).toString());
            }
        }
        else{
            model->setFilter("date>=\'"+ui->fdateEdit->text()+
                             "\' AND date<=\'"+ui->ldateEdit->text()+
                             "\' AND name=\'"+ui->searchLine->text()+"\'");
            qDebug()<<"datename2";
            QSqlQuery qry;
            if(qry.exec("SELECT SUM(price*amount) FROM database where date>=\'"
                        +ui->fdateEdit->text()+"\' AND date<=\'"+ui->ldateEdit->text()+
                        "\' AND name=\'"+ui->searchLine->text()+"\'")){
                qDebug() << "robit!";
                qry.next();
                ui->label_4->setText("Полная стоимость продажи (кол-во*цена):"+qry.value(0).toString());
            }
            ui->nameBox->setChecked(true);
            ui->dateBox->setChecked(true);
        }



    datas = 1;
    ui->dateBox->setChecked(true);
}

void MainWindow::on_nameSearch_clicked()
{
    QString sl;
    sl = ui->searchLine->text();
    qDebug()<<sl.size()<< endl << datas;
    if(sl.size()==0 && datas == 0){
        model->setTable("database");
        model->select();
        model->setHeaderData(1,Qt::Horizontal,"Название",Qt::DisplayRole);
        model->setHeaderData(2,Qt::Horizontal,"Количество",Qt::DisplayRole);
        model->setHeaderData(3,Qt::Horizontal,"Цена",Qt::DisplayRole);
        model->setHeaderData(4,Qt::Horizontal,"Дата продажи",Qt::DisplayRole);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView->setColumnHidden(0, true);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableView->setSortingEnabled(true);
        ui->tableView->selectRow(currentRow);
        ui->searchLine->setText("");
        datas=0;
        qDebug()<<"refresh1";
        ui->dateBox->setChecked(false);
        ui->nameBox->setChecked(false);
        QSqlQuery qry;
        if(qry.exec("SELECT SUM(price*amount) FROM database")){
            qDebug() << "robit!";
            qry.next();
            ui->label_4->setText("Полная стоимость продажи (кол-во*цена):"+qry.value(0).toString());
        }
    }
    else if(sl.size()==0 && datas == 1){
        model->setFilter("date>=\'"+ui->fdateEdit->text()+"\' AND date<=\'"+ui->ldateEdit->text()+"\'");
        qDebug()<<"date1";
        ui->dateBox->setChecked(true);
        ui->nameBox->setChecked(false);
        QSqlQuery qry;
        if(qry.exec("SELECT SUM(price*amount) FROM database where date>=\'"+ui->fdateEdit->text()+"\' AND date<=\'"+ui->ldateEdit->text()+"\'")){
            qDebug() << "robit!";
            qry.next();
            ui->label_4->setText("Полная стоимость продажи (кол-во*цена):"+qry.value(0).toString());
        }
    }
    else if(datas==1 && sl.size()!=0){
        model->setFilter("date>=\'"+ui->fdateEdit->text()+"\' AND date<=\'"+ui->ldateEdit->text()+"\' AND name=\'"+ui->searchLine->text()+"\'");
        qDebug()<<"datename2";
        QSqlQuery qry;
        if(qry.exec("SELECT SUM(price*amount) FROM database where date>=\'"+ui->fdateEdit->text()+"\' AND date<=\'"+ui->ldateEdit->text()+"\' AND name=\'"+ui->searchLine->text()+"\'")){
            qDebug() << "robit!";
            qry.next();
            ui->label_4->setText("Полная стоимость продажи (кол-во*цена):"+qry.value(0).toString());
        }
        ui->nameBox->setChecked(true);
        ui->dateBox->setChecked(true);
    }
    else{
        model->setFilter("name=\'"+ui->searchLine->text()+"\'");
        qDebug()<<"name1";
        QSqlQuery qry;
        if(qry.exec("SELECT SUM(price*amount) FROM database where name=\'"+ui->searchLine->text()+"\'")){
            qDebug() << "robit!";
            qry.next();
            ui->label_4->setText("Полная стоимость продажи (кол-во*цена):"+qry.value(0).toString());
        }
        ui->nameBox->setChecked(true);
    }
}
