#include "menu.h"
#include "ui_menu.h"
#include "filmsbd.h"
#include "calendar.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    QPixmap Background(":/img/img/Background.jpeg");
    Background = Background.scaled(size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, Background);
    setPalette(palette);
    setWindowTitle("АРМ Актёра");
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_ToFilmsBDButton_clicked()
{
    FilmsBD* m_FilmsBD = new FilmsBD;
    m_FilmsBD->setGeometry(geometry());
    m_FilmsBD->show();
    hide();
}

void Menu::on_ToCaledarButton_clicked()
{
    Calendar* m_Calendar = new Calendar;
    m_Calendar->setGeometry(geometry());
    m_Calendar->show();
    hide();
}

