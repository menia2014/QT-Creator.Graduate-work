#include "registration.h"
#include "ui_registration.h"

#define Path_to_DB "./database/login.db" //Подключение базы данных

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    ui->lblResult->hide();

    this->setWindowTitle("Регистрация");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if(checkFile.isFile()){//backendforMe
        if(db.open()){
            ui->lblResult->setText("[+]Connected to Database File");
        }
    }else{//backendforMe
        ui->lblResult->setText("[!]Database file not exist");
    }
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_pushButton_clicked()
{
    QString Username, Password;
    Username = ui->txtUser->text();
    Password = ui->txtPass->text();

    QSqlQuery query;
    if(Username.size()>3 && Password.size()>=3){
        if(query.exec("SELECT Username FROM login WHERE Username=\'" + Username + "\'")){ // Проверка на униакального пользователя
            if(query.next()){
                QMessageBox::warning(this, "Регистрация", "Такой логин занят!");
                ui->txtUser->setText("");
                ui->txtPass->setText("");
            } //end
            else{ // Если пользователь уникальный, то провести регистрацию с ролью "user"
                query.prepare("INSERT INTO login(Username \
                                 , Password \
                                 , Role) \
                                 VALUES(:Username \
                                 , :Password \
                                 , :Role); ");
                query.bindValue(":Username", Username);
                query.bindValue(":Password", Password);
                query.bindValue(":Role", "user");
                if(query.exec()){ // Если регистрация прошла успешно, то открыть новое информационное окно, закрыть существующее
                    QMessageBox::information(this, "Регистрация", "Регистрация прошла успешно!");
                    qDebug()<<true;
                    this->close();
                } //end
            }
        }
    }
    else{
        if(Username.size()<3){
            QMessageBox::warning(this, "Регистрация", "Логин должен быть больше трех символов!");
            ui->txtUser->setText("");
            ui->txtPass->setText("");
        }
        else {
            if(Password.size()<3){
            QMessageBox::warning(this, "Регистрация", "Пароль должен быть не менее трех символов!");
            ui->txtUser->setText("");
            ui->txtPass->setText("");}
        }

    }
}
