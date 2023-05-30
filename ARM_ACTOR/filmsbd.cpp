#include "filmsbd.h"
#include "ui_filmsbd.h"
#include "menu.h"

FilmsBD::FilmsBD(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilmsBD)
{
    ui->setupUi(this);
    setWindowTitle("Съёмки");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Fis.db");
    db.open();
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Съёмки(Название TEXT, Роль TEXT, Даты TEXT);");
    model = new QSqlTableModel(this, db);
    model->setTable("Съёмки");
    model->select();
    ui->tableView->setModel(model);
    for(int i = 0; i < 3; i++) {
         ui->tableView->setColumnWidth(i, width()/3);
    }
}

FilmsBD::~FilmsBD()
{
    delete ui;
}

void FilmsBD::on_ReturnToMenuButton_clicked()
{
    Menu *m_Window = new Menu;
    m_Window->setGeometry(geometry());
    m_Window->show();
    hide();
}


void FilmsBD::on_AddButton_clicked()
{
    model->insertRow(model->rowCount());
}


void FilmsBD::on_DeleteButton_clicked()
{
    model->removeRow(row);
}


void FilmsBD::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

