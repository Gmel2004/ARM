#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class Calendar;
}

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

private slots:
    void on_ShowNearButton_clicked();

    void on_ShowCurrentButton_clicked();

    void on_AddButton_clicked();

    void on_DeleteButton_clicked();

    void on_ReturnToMenuButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::Calendar *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    int row;
};

#endif // CALENDAR_H
