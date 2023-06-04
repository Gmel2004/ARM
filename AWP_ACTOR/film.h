#ifndef FILM_H
#define FILM_H

#include <QWidget>

namespace Ui {
class Film;
}

class Film : public QWidget
{
    Q_OBJECT

public:
    explicit Film(QString m_Log, QString m_name, QWidget *parent);
    ~Film();

private:
    Ui::Film *ui;
    QString Log;
    QString name;
};

#endif // FILM_H
