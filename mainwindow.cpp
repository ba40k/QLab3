#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) {
    centralWidget = new QWidget(parent);
    setCentralWidget(centralWidget);
    setWindowTitle("TreeDrawingTest");
    layout = new QHBoxLayout(centralWidget);
    setMinimumHeight(500);
    setMinimumWidth(500);
}
MainWindow::~MainWindow() {

}
