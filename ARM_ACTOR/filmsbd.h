#ifndef FILMSBD_H
#define FILMSBD_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class FilmsBD;
}

class FilmsBD : public QWidget
{
    Q_OBJECT

public:
    explicit FilmsBD(QWidget *parent = nullptr);
    ~FilmsBD();

private slots:
    void on_ReturnToMenuButton_clicked();

    void on_AddButton_clicked();

    void on_DeleteButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::FilmsBD *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    int row;
};

#endif // FILMSBD_H
