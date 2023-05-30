/********************************************************************************
** Form generated from reading UI file 'calendar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calendar
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *ShowCurrentButton;
    QPushButton *ShowNearButton;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QSpacerItem *horizontalSpacer;
    QLabel *LabelEvents;
    QPushButton *ReturnToMenuButton;
    QCalendarWidget *calendarWidget;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Calendar)
    {
        if (Calendar->objectName().isEmpty())
            Calendar->setObjectName(QString::fromUtf8("Calendar"));
        Calendar->resize(793, 529);
        gridLayout = new QGridLayout(Calendar);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(Calendar);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 3, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ShowCurrentButton = new QPushButton(Calendar);
        ShowCurrentButton->setObjectName(QString::fromUtf8("ShowCurrentButton"));

        horizontalLayout->addWidget(ShowCurrentButton);

        ShowNearButton = new QPushButton(Calendar);
        ShowNearButton->setObjectName(QString::fromUtf8("ShowNearButton"));

        horizontalLayout->addWidget(ShowNearButton);

        AddButton = new QPushButton(Calendar);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));

        horizontalLayout->addWidget(AddButton);

        DeleteButton = new QPushButton(Calendar);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));

        horizontalLayout->addWidget(DeleteButton);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 0, 1, 3);

        LabelEvents = new QLabel(Calendar);
        LabelEvents->setObjectName(QString::fromUtf8("LabelEvents"));

        gridLayout->addWidget(LabelEvents, 1, 3, 1, 1);

        ReturnToMenuButton = new QPushButton(Calendar);
        ReturnToMenuButton->setObjectName(QString::fromUtf8("ReturnToMenuButton"));

        gridLayout->addWidget(ReturnToMenuButton, 0, 0, 1, 1);

        calendarWidget = new QCalendarWidget(Calendar);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        gridLayout->addWidget(calendarWidget, 3, 0, 2, 1);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 2, 1);

        label = new QLabel(Calendar);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 3);


        retranslateUi(Calendar);

        QMetaObject::connectSlotsByName(Calendar);
    } // setupUi

    void retranslateUi(QWidget *Calendar)
    {
        Calendar->setWindowTitle(QApplication::translate("Calendar", "Form", nullptr));
        ShowCurrentButton->setText(QApplication::translate("Calendar", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216", nullptr));
        ShowNearButton->setText(QApplication::translate("Calendar", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\261\320\273\320\270\320\266\320\260\320\271\321\210\320\270\320\265 5", nullptr));
        AddButton->setText(QApplication::translate("Calendar", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        DeleteButton->setText(QApplication::translate("Calendar", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        LabelEvents->setText(QString());
        ReturnToMenuButton->setText(QApplication::translate("Calendar", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label->setText(QApplication::translate("Calendar", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \321\201\321\212\321\221\320\274\320\272\320\260\321\205:</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calendar: public Ui_Calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
