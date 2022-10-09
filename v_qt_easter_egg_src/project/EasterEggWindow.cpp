#include "EasterEggWindow.h"
#include "ui_EasterEggWindow.h"
#include "QLabel"
#include "QPixmap"
#include "QPainter"
#include "QIcon"

EasterEggWindow::EasterEggWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EasterEggWindow)
{
    ui->setupUi(this);
    setFixedSize(300, 400);
    setWindowIcon(QIcon(":/imgs/imgs/symbol.jpg"));
}

EasterEggWindow::~EasterEggWindow()
{
    delete ui;
}

void EasterEggWindow::paintEvent(QPaintEvent *)
{
    QPainter painter = QPainter(this);
    QPixmap funny = QPixmap(":/imgs/imgs/fun.png");
    painter.drawPixmap(0, 0, funny.scaled(300, 400, Qt::KeepAspectRatio));
}
