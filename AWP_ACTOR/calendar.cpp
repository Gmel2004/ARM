#include "calendar.h"
#include "ui_calendar.h"
using namespace std;
#include <string>
#include<QKeyEvent>

bool isDateTimeValid(string str) {
    return !(stoi(str.substr(3, 2)) > 12//месяц не может быть > 12
             || stoi(str.substr(0, 2)) > 31//день не может быть > 31
             || (stoi(str.substr(0, 2)) == 31 && ( QList<int>{4, 6, 9, 11}.contains(stoi(str.substr(3, 2)))))//не может быть 31 день в данные месяца
             || (str.substr(3, 2) == "02" && (stoi(str.substr(0, 2)) > 29//в феврале не может быть больше 29 дней
                                              || (stoi(str.substr(0, 2)) == 29 && (stoi(str.substr(6, 4)) % 100 % 4 != 0))))//проверка на високосный
             || stoi(str.substr(11, 2)) > 23 || stoi(str.substr(14, 2)) > 59);//Проверка времени
}
bool isTemplate(string str) {
    int cnt = 0;
    for (char i : str) {
        if (isdigit(i)) {
            cnt += 1;
        }
    }
    return ((str[2] == '.') && (str[5] == '.') && (str[10] == ' ') && (str[13] == ':') && (cnt == 12));
}

void CheckStr() {

}

Calendar::Calendar(QString m_Log, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calendar)
{
    Log = m_Log;
    ui->setupUi(this);
    setWindowTitle("Календарь");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./" + Log + "Calendar.db");
    db.open();
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Календарь(Название TEXT, Дата TEXT);");
    model = new QSqlTableModel(this, db);
    model->setTable("Календарь");
    model->select();
    ui->tableView->setModel(model);
    for(int i = 0; i < 2; i++) {
        ui->tableView->setColumnWidth(i, (width() - 38)/2);
    }
    int rowCnt = ui->tableView->model()->rowCount();
    for (int i = 0, j = 0; i < rowCnt; i++) {
        row = j;
        string str = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString().toStdString();
        if (ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toString() == ""
                || !isTemplate(str)
                || !isDateTimeValid(str)) {
            on_DelButton_clicked();
        }
        else {
            j++;
        }
    }
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::on_MoveButton_clicked()
{

}

void Calendar::on_AddButton_clicked()
{
    model->insertRow(model->rowCount());
}


void Calendar::on_DelButton_clicked()
{
    model->removeRow(row);
    ui->tableView->setSortingEnabled(true);
}


void Calendar::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}


void Calendar::on_calendarWidget_clicked(const QDate &date)
{
    ui->AddButton->setText(date.toString("dd.MM.yyyy"));
}


void Calendar::on_SignOutButton_clicked()
{
    QWidget *m_Authortization = new Authorization;
    m_Authortization->setGeometry(geometry());
    m_Authortization->show();
    close();
}

