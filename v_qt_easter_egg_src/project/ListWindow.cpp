#include "ListWindow.h"
#include "ui_ListWindow.h"

ListWindow::ListWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);
    setFixedSize(800, 450);
    setWindowIcon(QIcon(":/imgs/imgs/symbol.jpg"));

    this->setWindowFlags((windowFlags() & ~Qt::WindowCloseButtonHint));

    list.setParent(this);
    list.resize(800, 340);
    list.move(0, 0);
    connect(ui->exit_btn, &QPushButton::clicked, this, [=]()->void{
        emit this->choose_scene_back();
    });
    connect(ui->sure_btn, &QPushButton::clicked, this, [=]()->void{
        emit this->choose_sure();
    });
}

ListWindow::~ListWindow()
{
    delete ui;
}
