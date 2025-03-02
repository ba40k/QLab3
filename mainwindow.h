#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QString>
#include<QHBoxLayout>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMainWindow>
#include <QPainter>
#include "tree.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QPainter* painter;
    QWidget* centralWidget;
    QHBoxLayout* layout;
public:
    Tree tree;


private slots:

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
