/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *ToFilmsBDButton;
    QSpacerItem *verticalSpacer;
    QPushButton *ToCaledarButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(792, 531);
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ToFilmsBDButton = new QPushButton(centralwidget);
        ToFilmsBDButton->setObjectName(QString::fromUtf8("ToFilmsBDButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS UI Gothic"));
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        font.setKerning(true);
        ToFilmsBDButton->setFont(font);
        ToFilmsBDButton->setMouseTracking(false);
        ToFilmsBDButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));

        horizontalLayout->addWidget(ToFilmsBDButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        ToCaledarButton = new QPushButton(centralwidget);
        ToCaledarButton->setObjectName(QString::fromUtf8("ToCaledarButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS UI Gothic"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        ToCaledarButton->setFont(font1);
        ToCaledarButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));

        horizontalLayout->addWidget(ToCaledarButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        Menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Menu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 792, 20));
        Menu->setMenuBar(menubar);
        statusbar = new QStatusBar(Menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Menu->setStatusBar(statusbar);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Menu", nullptr));
        ToFilmsBDButton->setText(QApplication::translate("Menu", "\320\244\320\270\320\273\321\214\320\274\321\213", nullptr));
        ToCaledarButton->setText(QApplication::translate("Menu", "\320\232\320\260\320\273\320\265\320\275\320\264\320\260\321\200\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
