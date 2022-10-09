#ifndef ADMINMAINMENU_H
#define ADMINMAINMENU_H

#include <QMainWindow>

namespace Ui {
class AdminMainMenu;
}

class AdminMainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainMenu(QWidget *parent = nullptr);
    ~AdminMainMenu();

signals:
    //信号-返回上级窗口
    void choose_scene_back();

private:
    Ui::AdminMainMenu *ui;
    /*功能函数*/
    //查看所有商品
    void show_all_merchandises();
    //搜索商品
    void select_merchandise();
    //下架商品
    void remove_merchandise();
    //查看所有订单
    void show_all_orderforms();
    //查看所有用户
    void show_all_usrs();
    //封禁用户
    void ban_usr();
};

#endif // ADMINMAINMENU_H
