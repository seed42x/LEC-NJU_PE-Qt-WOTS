#ifndef SELLERMAINMENU_H
#define SELLERMAINMENU_H

#include <QMainWindow>

namespace Ui {
class SellerMainMenu;
}

class SellerMainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit SellerMainMenu(QWidget *parent = nullptr);
    ~SellerMainMenu();
    void add_merchandise();
    void show_my_added_merchandises();
    void modify_merchandise_info();
    void remove_merchandise();
    void show_my_orderforms();

signals:
    void choose_scene_back();

private:
    Ui::SellerMainMenu *ui;
};

#endif // SELLERMAINMENU_H
