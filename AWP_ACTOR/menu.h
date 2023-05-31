#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:

    void on_ToCaledarButton_clicked();

    void on_LoginButton_clicked();

    void on_RegisterButton_clicked();

private:
    QWidget *window;
    Ui::Menu *ui;
    void SuccessfulAuthorization();
    QTextEdit *InputLog;
    QTextEdit *InputPas;
    void delay(int time);
};
#endif // MENU_H
