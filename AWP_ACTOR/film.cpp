#include "film.h"
#include "ui_film.h"

Film::Film(QString m_Log, QString m_name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Film)
{
    ui->setupUi(this);
    Log = m_Log;
    name = m_name;
}

Film::~Film()
{
    delete ui;
}
