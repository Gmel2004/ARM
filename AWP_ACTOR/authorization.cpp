#include "authorization.h"
#include "ui_authorization.h"
#include "calendar.h"
#include <QJsonObject>

Authorization::Authorization(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Authorization)
{
    ui->setupUi(this);
    setWindowTitle("Авторизация");
}

Authorization::~Authorization()
{
    delete ui;
}

void Authorization::ToCalendar() {
    QWidget *m_Calendar = new Calendar(Log, nullptr);
    m_Calendar->setGeometry(geometry());
    m_Calendar->show();
    hide();
}

//чтение бд (JSon)


void Authorization::on_RegisterButton_clicked()
{
    Log = ui->InputLog_2->text();
    Pas = ui->InputPas_2->text();
    if (UsersData.find(Log) == UsersData.end()) {    //проверка на оригинальность логина
        QMessageBox::about(this, "Регистрация", "Регистрация прошла успешно!");
           //Занесение в бд
        ToCalendar();
    }
    else {
        QMessageBox::critical(this, "Регистрация", "Логин уже используется!");

    }
}


void Authorization::on_LoginButton_clicked()
{
    Log = ui->InputLog->text();
    Pas = ui->InputPas->text();
    UsersData["codi"] = "test";
    UsersData["cod"] = "test";
    if (UsersData.find(Log) != UsersData.end()) {//если логин существует
        if (UsersData[Log] == Pas) {//проверка сходимости паролей
            ToCalendar();
        }
        else {
            QMessageBox::critical(this, "Ошибка", "Логин или пароль не верны!");
        }

    }
    else {
        QMessageBox::critical(this, "Ошибка", "Указанный логин не существует!");
    }

}

