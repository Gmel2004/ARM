/********************************************************************************
** Form generated from reading UI file 'filmsbd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILMSBD_H
#define UI_FILMSBD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilmsBD
{
public:
    QGridLayout *gridLayout;
    QPushButton *ReturnToMenuButton;
    QTableView *tableView;

    void setupUi(QWidget *FilmsBD)
    {
        if (FilmsBD->objectName().isEmpty())
            FilmsBD->setObjectName(QString::fromUtf8("FilmsBD"));
        FilmsBD->resize(759, 554);
        gridLayout = new QGridLayout(FilmsBD);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ReturnToMenuButton = new QPushButton(FilmsBD);
        ReturnToMenuButton->setObjectName(QString::fromUtf8("ReturnToMenuButton"));

        gridLayout->addWidget(ReturnToMenuButton, 0, 0, 1, 1);

        tableView = new QTableView(FilmsBD);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 2);


        retranslateUi(FilmsBD);

        QMetaObject::connectSlotsByName(FilmsBD);
    } // setupUi

    void retranslateUi(QWidget *FilmsBD)
    {
        FilmsBD->setWindowTitle(QApplication::translate("FilmsBD", "Form", nullptr));
        ReturnToMenuButton->setText(QApplication::translate("FilmsBD", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilmsBD: public Ui_FilmsBD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILMSBD_H
