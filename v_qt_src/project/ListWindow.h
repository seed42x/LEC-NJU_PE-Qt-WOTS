#ifndef LISTWINDOW_H
#define LISTWINDOW_H

#include <QMainWindow>
#include "QListWidget"

namespace Ui {
class ListWindow;
}

class ListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListWindow(QWidget *parent = nullptr);
    ~ListWindow();
    QListWidget list;

signals:
    void choose_scene_back();
    void choose_sure();

private:
    Ui::ListWindow *ui;
};

#endif // LISTWINDOW_H
