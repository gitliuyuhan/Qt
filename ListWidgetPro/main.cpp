/*
Function:main
程序入口函数
by www.hnmade.com
 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    w.resize(800,600);

    return a.exec();
}
