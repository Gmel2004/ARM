#include "calendar.h"
#include "ui_calendar.h"
#include "menu.h"

Calendar::Calendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
    setWindowTitle("Календарь");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Films.db");
    db.open();
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Съёмки(Название TEXT, Роль TEXT, Дата TEXT, Время TEXT);");
    model = new QSqlTableModel(this, db);
    model->setTable("Съёмки");
    model->select();
    int ColWidth = ui->calendarWidget->width()/4;//не работает
    for(int i = 0; i < 4; i++) {
         ui->tableView->setColumnWidth(i, ColWidth);
    }
    ui->tableView->setModel(model);
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::on_ShowNearButton_clicked()
{

}


void Calendar::on_ShowCurrentButton_clicked()
{

}


void Calendar::on_AddButton_clicked()
{
    model->insertRow(model->rowCount());
}


void Calendar::on_DeleteButton_clicked()
{
    model->removeRow(row);
}


void Calendar::on_ReturnToMenuButton_clicked()
{
    Menu *m_Window = new Menu;
    m_Window->setGeometry(geometry());
    m_Window->setMinimumSize(946, 630);
    m_Window->show();
    hide();
}


void Calendar::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}
