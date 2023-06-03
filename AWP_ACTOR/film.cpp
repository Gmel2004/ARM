#include "film.h"
#include "ui_film.h"

Film::Film(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Film)
{
    ui->setupUi(this);
}

Film::~Film()
{
    delete ui;
}
