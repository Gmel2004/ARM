#include "calendar.h"
#include "ui_calendar.h"
#include <QPainter>
#include <QFont>
#include <QTableWidget>

bool isDateTimeValid(string str) {
    return !(stoi(str.substr(3, 2)) > 12//месяц не может быть > 12
             || stoi(str.substr(8, 2)) > 31//день не может быть > 31
             || (stoi(str.substr(8, 2)) == 31 && ( QList<int>{4, 6, 9, 11}.contains(stoi(str.substr(3, 2)))))//не может быть 31 день в данные месяца
             || (str.substr(3, 2) == "02" && (stoi(str.substr(8, 2)) > 29//в феврале не может быть больше 29 дней
                                              || (stoi(str.substr(8, 2)) == 29 && (stoi(str.substr(0, 4)) % 100 % 4 != 0))))//проверка на високосный
             || stoi(str.substr(11, 2)) > 23 || stoi(str.substr(14, 2)) > 59);//Проверка времени
}
bool isTemplate(string str) {
    int cnt = 0;
    for (char i : str) {
        if (isdigit(i)) {
            cnt += 1;
        }
    }
    return ((str[4] == '.') && (str[7] == '.') && (str[10] == ' ') && (str[13] == ':') && (cnt == 12));
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
    str = "CREATE TABLE Календарь(Название TEXT, Дата TEXT);";
    query->exec(str);
    model = new QSqlTableModel(this, db);
    model->setTable("Календарь");
    model->select();
    ui->tableView->setModel(model);
    for(int i = 0; i < 2; i++) {
        ui->tableView->setColumnWidth(i, (width() - 38)/2);
    }
    on_ShowCurentDatesButton_clicked();

    ifstream CurrentDates("./" + Log.toStdString() + "FullDates.txt");
    string Date;
    while (getline(CurrentDates, Date)) {
        QTextCharFormat Format;
        QFont f = QFont("MS Shell Dig 2", 14);
        f.setOverline(true);
        Format.setFont(f);
        ui->calendarWidget->setDateTextFormat(QDate::fromString(QString::fromStdString(Date),"yyyy.MM.dd"), Format);
    }
}

bool Calendar::isDataValid() {
    string str = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString().toStdString().substr(0, 10);
    return (ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toString() != ""
            || isTemplate(str)
            || isDateTimeValid(str));
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
    if (!FirstAdd) {
        FirstAdd = true;
        char FirstAddMessage[500] = "Все неправильно введённые данные будут\nудалены после завершения сессии.\n\n"
                      "Формат ввода данных:\n"
                      "Название не может являть пустой строкой\n\n"
                      "Дата: гггг.мм.дд чч:мм";
        QMessageBox::warning(this, "Внимание", FirstAddMessage);
    }
    NewDatesNumbers.push_back(model->rowCount());
    model->insertRow(model->rowCount());
}

void Calendar::on_DelButton_clicked()
{
    for (auto i = NewDatesNumbers.begin(); i != NewDatesNumbers.end();) {
        if (*i == row) {
            i = NewDatesNumbers.erase(i);
        }
        else {
            i++;
        }
    }
    model->removeRow(row);
    on_ShowCurentDatesButton_clicked();//
    ui->tableView->sortByColumn(1, Qt::AscendingOrder);
}


void Calendar::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}


void Calendar::on_calendarWidget_clicked(const QDate &date)
{
    on_ShowFullButton_clicked();
    string m_date = date.toString("yyyy.MM.dd").toStdString();
    for (int i = 0; i < ui->tableView->model()->rowCount(); i++) {
        string str = ui->tableView->model()->data(ui->tableView->model()->index(i, 1)).toString().toStdString().substr(0, 10);
        if (str != m_date) {
            ui->tableView->hideRow(i);
        }
    }
    ui->tableView->sortByColumn(1, Qt::AscendingOrder);
}


void Calendar::on_SignOutButton_clicked()
{
    ofstream CurrentDates("./" + Log.toStdString() + "FullDates.txt");
    QWidget *m_Authortization = new Authorization;
    m_Authortization->setGeometry(geometry());
    m_Authortization->show();
    close();
}
//важно: при удалении индексы в NewDates должны меняться. При удалении нужно включать или текущий день, ели он выбран или актуальные даты

void Calendar::on_ShowFullButton_clicked()
{
    const string dateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd").toStdString();
    for (int i = 0; i < ui->tableView->model()->rowCount(); i++) {
        ui->tableView->showRow(i);
    }
    ui->tableView->sortByColumn(1, Qt::AscendingOrder);
}


void Calendar::on_ShowCurentDatesButton_clicked()
{
    const string dateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd").toStdString();
    for (int i = 0; i < ui->tableView->model()->rowCount(); i++) {
        string str = ui->tableView->model()->data(ui->tableView->model()->index(i, 1)).toString().toStdString().substr(0, 10);
        if (str < dateTime) {
            ui->tableView->hideRow(i);
        }
        else {
            ui->tableView->showRow(i);
        }
    }
    ui->tableView->sortByColumn(1, Qt::AscendingOrder);
}

void Calendar::on_SaveChangesButton_clicked()
{

    int count = 0;
    NewDatesNumbers.sort();
    for (int i :NewDatesNumbers) {
        row = i - count;
        if (!isDataValid()) {
            on_DelButton_clicked();
            count++;
            //Важно: переделать count
        }
    }
}

