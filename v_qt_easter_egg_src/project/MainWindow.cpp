#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include "QPixmap"
#include "QPushButton"
#include "mainmenu.h"
#include "QIcon"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(600, 450);
    setWindowIcon(QIcon(":/imgs/imgs/symbol.jpg"));
    /*信号与槽*/
    //退出按钮
    connect(ui->cover_exit_btn, &QPushButton::clicked, [=]()->void{
        this->close();
    });
    //进入系统按钮
    connect(ui->cover_entry_btn, &QPushButton::clicked, [=]()->void{
        //创建主菜单
        MainMenu* main_window = new MainMenu();
        //保持窗口位置一致
        main_window->setGeometry(this->geometry());
        //显示切换
        this->hide();
        main_window->show();
        //TODO:监听主菜单内退出按钮
        connect(main_window, &MainMenu::choose_scene_back, this, [=]()->void{
            this->setGeometry(main_window->geometry());
            delete main_window;
            this->show();
        });
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter = QPainter(this);
    QPixmap cover = QPixmap(":/imgs/imgs/cover.png");
    painter.drawPixmap(0, 0, cover.scaled(600, 450, Qt::KeepAspectRatio));
}
