#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include "tree.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Tree<int> t;
    std::cout<<sizeof(t)<<'\n';
    t.insert(10);
    t.insert(15);
    t.insert(7);
    t.insert(14);
    t.insert(16);
    t.insert(6);
    t.insert(8);
    std::cout<<1;
    t.erase(7);


    w.show();
    return a.exec();
}
