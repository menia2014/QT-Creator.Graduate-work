/********************************************************************************
** Form generated from reading UI file 'adding.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDING_H
#define UI_ADDING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_adding
{
public:
    QGridLayout *gridLayout;
    QLineEdit *nameL;
    QLineEdit *priceL;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *countL;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QDateEdit *dateEdit;

    void setupUi(QDialog *adding)
    {
        if (adding->objectName().isEmpty())
            adding->setObjectName(QString::fromUtf8("adding"));
        adding->resize(357, 95);
        gridLayout = new QGridLayout(adding);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nameL = new QLineEdit(adding);
        nameL->setObjectName(QString::fromUtf8("nameL"));
        nameL->setFrame(true);

        gridLayout->addWidget(nameL, 1, 0, 1, 1);

        priceL = new QLineEdit(adding);
        priceL->setObjectName(QString::fromUtf8("priceL"));

        gridLayout->addWidget(priceL, 1, 3, 1, 1);

        label_3 = new QLabel(adding);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        label = new QLabel(adding);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(adding);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 1, 1, 2);

        label_2 = new QLabel(adding);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        countL = new QLineEdit(adding);
        countL->setObjectName(QString::fromUtf8("countL"));

        gridLayout->addWidget(countL, 1, 1, 1, 2);

        pushButton = new QPushButton(adding);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 3, 1, 1);

        pushButton_2 = new QPushButton(adding);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 1, 1, 2);

        dateEdit = new QDateEdit(adding);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        gridLayout->addWidget(dateEdit, 1, 4, 1, 1);

        label_3->raise();
        label_4->raise();
        nameL->raise();
        priceL->raise();
        label->raise();
        label_2->raise();
        pushButton->raise();
        pushButton_2->raise();
        countL->raise();
        dateEdit->raise();
        QWidget::setTabOrder(nameL, countL);
        QWidget::setTabOrder(countL, priceL);
        QWidget::setTabOrder(priceL, dateEdit);
        QWidget::setTabOrder(dateEdit, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        retranslateUi(adding);

        QMetaObject::connectSlotsByName(adding);
    } // setupUi

    void retranslateUi(QDialog *adding)
    {
        adding->setWindowTitle(QCoreApplication::translate("adding", "Dialog", nullptr));
        nameL->setInputMask(QString());
        label_3->setText(QCoreApplication::translate("adding", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\276\320\264\320\260\320\266\320\270", nullptr));
        label->setText(QCoreApplication::translate("adding", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("adding", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_2->setText(QCoreApplication::translate("adding", "\320\246\320\265\320\275\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("adding", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("adding", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adding: public Ui_adding {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDING_H
