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
#include <QRadioButton>
#include<QLabel>
#include<QLineEdit>
#include<QTextEdit>
#include<QPainter>
#include"treePaint.h"
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
    QHBoxLayout* screenSplit;
    QVBoxLayout* leftScreenPart;
    QHBoxLayout* rightScreenPart;
    QVBoxLayout* rightRightScreenPart;
    QVBoxLayout* rightLeftScreenPart;

    QRadioButton* inOrderTraversalFlag;
    QRadioButton* forwardTraversalFlag;
    QRadioButton* backwardTraversalFlag;

    QPushButton* insertButton;
    QPushButton* deleteButton;
    QPushButton* searchButton;

    QLabel* inputLabel;
    QLabel* outputLabel;
    QTextEdit* output;
    QTextEdit* input;

    treePaint* treePainter;

    QVector<bool> traversalOrder; // f w inO

public:



private slots:
    void insert();
    void search();
    void erase();
    void forwardTraversalPressed();
    void backwardTraversalPressed();
    void inOrderTraversalPressed();





public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
