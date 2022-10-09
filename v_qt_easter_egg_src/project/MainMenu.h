#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "Usr.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
    //管理员
    void admin_login();

    //用户
    //登录 & 注册
    void usr_login();
    void usr_register();
signals:
    //信号-返回上级窗口
    void choose_scene_back();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
