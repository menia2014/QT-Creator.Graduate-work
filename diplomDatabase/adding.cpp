#include "adding.h"
#include "ui_adding.h"

#define Path_to_DB "./database/database.db"

adding::adding(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adding)
{

    ui->setupUi(this);

    this->setWindowTitle("Добавление");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if(checkFile.isFile()){//backendforMe
        if(db.open()){
            qDebug() << "Опен!";
        }
        else {
            qDebug() << "closed";
        }
    }else{//backendforMe
        qDebug() << "Не нашел или клосед!";
    }

    ui->dateEdit->setDisplayFormat("dd.MM.yyyy");
    ui->dateEdit->setDate(QDate::currentDate());

}

adding::~adding()
{
    delete ui;
}

void adding::on_pushButton_2_clicked()
{
    ui->nameL->setText("");
    ui->countL->setText("");
    ui->priceL->setText("");
    ui->dateEdit->setDisplayFormat("dd.MM.yyyy");
    ui->dateEdit->setDate(QDate::currentDate());
    this->close();

}


void adding::on_pushButton_clicked()
{
    QString nameL = ui->nameL->text();
    QString countL = ui->countL->text();
    QString priceL = ui->priceL->text();
    QString dateL = ui->dateEdit->text();


    if(nameL.size() == 0){
        QMessageBox::warning(this, "Ошибка","Название пустое!");

    }
    else if(countL.size() == 0){
        QMessageBox::warning(this, "Ошибка","Количество не указано!");
    }
    else if(priceL.size() == 0){
        QMessageBox::warning(this, "Ошибка","Цена не указана!");
    }
    else{
        QSqlQuery query;
        query.prepare("INSERT INTO database(name \
                         , amount \
                         , price \
                         , date) \
                         VALUES(:name \
                         , :amount \
                         , :price \
                         , :date); ");
        query.bindValue(":name", nameL);
        query.bindValue(":amount", countL);
        query.bindValue(":price", priceL);
        query.bindValue(":date", dateL);
        if(query.exec()){
            qDebug() << "add to database!";
            QMessageBox::information(this,"Добавлено!","Запись была добавлена в базу данных!");
            ui->nameL->setText("");
            ui->countL->setText("");
            ui->priceL->setText("");
            ui->dateEdit->setDisplayFormat("dd.MM.yyyy");
            ui->dateEdit->setDate(QDate::currentDate());
            this->close();
        }
        else{
            QMessageBox::warning(this, "Ошибка","В строках \"Количество\" и \"Цена\" могут быть только числа!");
        }
        qDebug() << query.lastError();
    }
}
