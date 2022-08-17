#include "login.h"
#include "ui_login.h"
#include "registration.h"
#include "mainwindow.h"

#define Path_to_DB "./database/login.db" //путь до базы данных login

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    ui->lblResult->hide();
    this->setWindowTitle("Авторизация");



    if(!QDir("./database").exists()){
        QDir().mkdir("./database");
        QMessageBox::warning(this,"Внимание!","Отсутствуют базы данных перезапустите приложение!");
        exit(0);
    }

    ui->loginbt->setShortcut(Qt::Key_Return);

    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);

    QFileInfo checkFile(Path_to_DB);
    if(checkFile.isFile()){//backendforMe
        if(myDB.open()){
            ui->lblResult->setText("[+]Connected to Database File");
            query = new QSqlQuery(db);
            if (!myDB.tables().contains(QLatin1String("login"))) {
                query->exec("CREATE TABLE login (ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, Username STRING  NOT NULL, Password STRING  NOT NULL, Role STRING);");
                query->prepare("INSERT INTO login(Username, Password, Role) VALUES(:Username, :Password, :Role);");
                query->bindValue(":Username","admin");
                query->bindValue(":Password","admin");
                query->bindValue(":Role","admin");
                query->exec();
            }


        }
    }else{//backendforMe
        ui->lblResult->setText("[!]Database file not exist");
        qDebug()<<"[!]Database file not exist";


        //CREATE TABLE login (ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, Username STRING  NOT NULL, Password STRING  NOT NULL, Role STRING
    }
}

login::~login()
{
    delete ui;
    qDebug() << "Closing the connection to Databse file on exit!";
    myDB.close();
}


void login::on_regbt_clicked()
{
    reg.setModal(true);
    reg.exec();
}


void login::on_loginbt_clicked()//login password
{
    QString Username, Password;
    Username = ui->txtUser->text();
    Password = ui->txtPass->text();

    if(!myDB.isOpen()){//backendforMe
        qDebug() << "No connection to db!";
        return;
    }
    else{//backendforMe
        qDebug() << "Connection to db!";
    }

    QSqlQuery qry;

    if(qry.exec("SELECT Username, Password, Role FROM login WHERE Username=\'" + Username +
                "\' AND Password=\'" + Password + "\'"))
    {
        if(qry.next())
        {
            ui->lblResult->setText("[+]Valid Username and Password");//backendforMe
            window = new MainWindow;
            window->show();
            this->close();

        }else{
            ui->lblResult->setText("[-]Wrong Username or Password!");
            QMessageBox::warning(this, "Ошибка", "Неверный Логин или Пароль!");
        }
    }
    else{
        qDebug() << "nerobit";
    }
}

