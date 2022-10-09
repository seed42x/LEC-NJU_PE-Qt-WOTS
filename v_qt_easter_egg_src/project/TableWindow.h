#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QMainWindow>
#include "QTableWidget"

namespace Ui {
class TableWindow;
}

class TableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableWindow(QWidget *parent = nullptr);
    ~TableWindow();
    QTableWidget table;


private:
    Ui::TableWindow *ui;
};

#endif // TABLEWINDOW_H
