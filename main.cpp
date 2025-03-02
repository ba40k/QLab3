#include <iostream>

#include "mainwindow.h"
#include <QApplication>
#include "tree.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Tree t;
    t.insert(5);
    t.insert(6);
    t.insert(7);
    std::cout<<t.search(5)<<' '<<t.search(6)<<' '<<t.search(7)<<std::endl;
    t.erase(5);
    std::cout<<t.search(5)<<' '<<t.search(6)<<' '<<t.search(7)<<std::endl;
    w.show();
    return a.exec();
}
