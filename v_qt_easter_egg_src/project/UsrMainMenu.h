#ifndef USRMAINMENU_H
#define USRMAINMENU_H

#include <QMainWindow>

namespace Ui {
class UsrMainMenu;
}

class UsrMainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit UsrMainMenu(QWidget *parent = nullptr);
    ~UsrMainMenu();
signals:
    //信号-返回上级窗口
    void choose_scene_back();
private:
    Ui::UsrMainMenu *ui;
};

#endif // USRMAINMENU_H
