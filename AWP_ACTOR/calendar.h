#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include <authorization.h>
#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <string>
#include <QLabel>
#include <QLineEdit>
#include<fstream>
using namespace std;

namespace Ui {
class Calendar;
}

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QString m_Log, QWidget *parent);
    ~Calendar();
    QString Log;

private slots:
    void on_MoveButton_clicked();

    void on_AddButton_clicked();

    void on_DelButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_calendarWidget_clicked(const QDate &date);

    void on_SignOutButton_clicked();

    void AddData();

    void on_ShowCurentDatesButton_clicked();

    void on_SaveChangesButton_clicked();

private:
    Ui::Calendar *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    int row;
    QLineEdit *Input1;
    QLineEdit *Input2;
    QString str;
    bool isDataValid();
    void on_ShowFullButton_clicked();
    list<int> NewDatesNumbers;
    bool FirstAdd = false;
};

#endif // CALENDAR_H
