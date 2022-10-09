#include "mainwindow.h"
#include <QFile>
#include <QApplication>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //使用QSS样式表---
    QString qss;
    QFile qssfile(":/qss/qss/stylesheet.qss");
    qssfile.open(QFile::ReadOnly);

    if(qssfile.isOpen())
    {
        qss = QLatin1String(qssfile.readAll());
        qApp->setStyleSheet(qss);
        qssfile.close();
    }
    //---

    MainWindow w;
    w.show();
    return a.exec();
}
