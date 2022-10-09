#ifndef EASTEREGGWINDOW_H
#define EASTEREGGWINDOW_H

#include <QMainWindow>

namespace Ui {
class EasterEggWindow;
}

class EasterEggWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EasterEggWindow(QWidget *parent = nullptr);
    ~EasterEggWindow();
    void paintEvent(QPaintEvent *);

private:
    Ui::EasterEggWindow *ui;
};

#endif // EASTEREGGWINDOW_H
