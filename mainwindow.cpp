#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) {
    centralWidget = new QWidget(this);

    setWindowTitle("Tree vizualization");
    setMinimumHeight(800);
    setMinimumWidth(800);
    screenSplit = new QHBoxLayout();
    centralWidget->setLayout(screenSplit);
    leftScreenPart = new QVBoxLayout();
    rightScreenPart = new QHBoxLayout();

    rightRightScreenPart = new QVBoxLayout();
    rightLeftScreenPart = new QVBoxLayout();

    forwardTraversalFlag = new QRadioButton(centralWidget);
    forwardTraversalFlag->setText("Forward");
    rightRightScreenPart->addWidget(forwardTraversalFlag);

    backwardTraversalFlag = new QRadioButton(centralWidget);
    backwardTraversalFlag->setText("Backward");
    rightRightScreenPart->addWidget(backwardTraversalFlag);

    inOrderTraversalFlag = new QRadioButton(centralWidget);
    inOrderTraversalFlag ->setText("Symmetric");
    rightRightScreenPart->addWidget(inOrderTraversalFlag );

    forwardTraversalFlag->setChecked(false);
    inOrderTraversalFlag->setChecked(true);

    screenSplit->addLayout(leftScreenPart);
    screenSplit->addLayout(rightScreenPart);

    rightScreenPart->addLayout(rightRightScreenPart);
    rightScreenPart->addLayout(rightLeftScreenPart);


    setCentralWidget(centralWidget);

}
MainWindow::~MainWindow() {

}