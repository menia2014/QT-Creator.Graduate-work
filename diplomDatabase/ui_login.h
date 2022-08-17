/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *txtUser;
    QLineEdit *txtPass;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginbt;
    QPushButton *regbt;
    QLabel *lblResult;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(264, 195);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        txtUser = new QLineEdit(centralwidget);
        txtUser->setObjectName(QString::fromUtf8("txtUser"));

        verticalLayout->addWidget(txtUser);

        txtPass = new QLineEdit(centralwidget);
        txtPass->setObjectName(QString::fromUtf8("txtPass"));
        txtPass->setFrame(true);
        txtPass->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(txtPass);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        loginbt = new QPushButton(centralwidget);
        loginbt->setObjectName(QString::fromUtf8("loginbt"));

        horizontalLayout->addWidget(loginbt);

        regbt = new QPushButton(centralwidget);
        regbt->setObjectName(QString::fromUtf8("regbt"));

        horizontalLayout->addWidget(regbt);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        lblResult = new QLabel(centralwidget);
        lblResult->setObjectName(QString::fromUtf8("lblResult"));
        lblResult->setFrameShape(QFrame::Box);
        lblResult->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(lblResult, 2, 0, 1, 2);

        login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 264, 21));
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "login", nullptr));
        label->setText(QCoreApplication::translate("login", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_2->setText(QCoreApplication::translate("login", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        loginbt->setText(QCoreApplication::translate("login", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        regbt->setText(QCoreApplication::translate("login", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        lblResult->setText(QCoreApplication::translate("login", "[+]Status...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
