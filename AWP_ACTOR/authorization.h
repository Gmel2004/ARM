#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMap>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class Authorization; }
QT_END_NAMESPACE

class Authorization : public QMainWindow
{
    Q_OBJECT

public:
    Authorization(QWidget *parent = nullptr);
    ~Authorization();

private slots:
    void on_RegisterButton_clicked();

    void on_LoginButton_clicked();

private:
    Ui::Authorization *ui;
    void ToCalendar();
    QString Log, Pas;
    QMap<QString, QString> UsersData;
    QJsonObject UsersDataJson;

};
#endif // AUTHORIZATION_H
