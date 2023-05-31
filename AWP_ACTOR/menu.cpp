#include "menu.h"
#include "ui_menu.h"
#include <QLabel>
#include <QTextEdit>
#include <QTime>

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::SuccessfulAuthorization() {
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel("🔓"), 0, 0);
    window->setLayout(layout);
    delay(60);
    layout->addWidget(new QLabel("🔐"), 0, 0);
}

void CheckData() {

}

void Menu::on_LoginButton_clicked()
{
    window = new QWidget;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel("Введите логин: "), 0, 0);
    InputLog = new QTextEdit;
    layout->addWidget(InputLog, 0, 1);
    layout->addWidget(new QLabel("Введите пароль: "), 1, 0);
    InputPas = new QTextEdit;
    layout->addWidget(InputPas, 0, 1);
    layout->addWidget(InputPas, 1, 1);
    QPushButton *Ok = new QPushButton;
    Ok->setText("ОК");
    layout->addWidget(new QTextEdit, 1, 1);
    layout->addWidget(Ok, 2, 1);
    window->setLayout(layout);
    window->setWindowTitle("Авторизация");
    window->show();
    connect(Ok, &QPushButton::clicked, this, CheckData);
}

void Menu::delay(int time){
    clock_t now = clock();
    while(clock() - now < time);
}

void AddNewUser() {
    //добавляем


}

void Menu::on_RegisterButton_clicked()
{
    window = new QWidget;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel("Введите логин: "), 0, 0);
    InputLog = new QTextEdit;
    layout->addWidget(InputLog, 0, 1);
    layout->addWidget(new QLabel("Введите пароль: "), 1, 0);
    InputPas = new QTextEdit;
    layout->addWidget(InputPas, 0, 1);
    layout->addWidget(InputPas, 1, 1);
    QPushButton *Ok = new QPushButton;
    Ok->setText("ОК");
    layout->addWidget(new QTextEdit, 1, 1);
    layout->addWidget(Ok, 2, 1);
    window->setLayout(layout);
    window->setWindowTitle("Авторизация");
    window->show();
    connect(Ok, &QPushButton::clicked, this, AddNewUser);
}

