#include "TableWindow.h"
#include "ui_TableWindow.h"

TableWindow::TableWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableWindow)
{
    ui->setupUi(this);
    table.move(0, 0);
    table.resize(800, 450);
    table.setWindowIcon(QIcon(":/imgs/imgs/symbol.jpg"));
    table.show();
}

TableWindow::~TableWindow()
{
    delete ui;
}
