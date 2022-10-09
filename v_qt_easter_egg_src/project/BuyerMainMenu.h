#ifndef BUYERMAINMENU_H
#define BUYERMAINMENU_H

#include <QMainWindow>

namespace Ui {
class BuyerMainMenu;
}

class BuyerMainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit BuyerMainMenu(QWidget *parent = nullptr);
    ~BuyerMainMenu();
    //查看商品列表
    void show_all_merchandises();
    //购买商品
    void purchase_merchandise();
    //搜索商品
    void select_merchandise();
    //查看历史订单
    void show_all_orderforms();
    //查看商品详细信息
    void show_specific_merchandise_details_info();

signals:
    void choose_scene_back();

private:
    Ui::BuyerMainMenu *ui;
};

#endif // BUYERMAINMENU_H
