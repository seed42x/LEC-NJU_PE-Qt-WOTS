#ifndef USRINFOMAINMENU_H
#define USRINFOMAINMENU_H

#include <QMainWindow>

namespace Ui {
class UsrInfoMainMenu;
}

class UsrInfoMainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit UsrInfoMainMenu(QWidget *parent = nullptr);
    ~UsrInfoMainMenu();
    void show_info();
    void modify_info();
    void recharge();

signals:
    void choose_scene_back();

private:
    Ui::UsrInfoMainMenu *ui;
};

#endif // USRINFOMAINMENU_H
