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
    forwardTraversalFlag->setMaximumHeight(40);
    rightRightScreenPart->addWidget(forwardTraversalFlag);

    backwardTraversalFlag = new QRadioButton(centralWidget);
    backwardTraversalFlag->setText("Backward");
    backwardTraversalFlag->setMaximumHeight(40);
    rightRightScreenPart->addWidget(backwardTraversalFlag);

    inOrderTraversalFlag = new QRadioButton(centralWidget);
    inOrderTraversalFlag ->setText("Symmetric"); inOrderTraversalFlag->setMaximumWidth(100);
    inOrderTraversalFlag->setMaximumHeight(40);
    rightRightScreenPart->addWidget(inOrderTraversalFlag );

    forwardTraversalFlag->setChecked(false);

    insertButton = new QPushButton(centralWidget);
    insertButton->setText("Insert");
    insertButton->setMaximumWidth(100);
    insertButton->setMaximumHeight(40);
    rightLeftScreenPart->addWidget(insertButton);

    deleteButton = new QPushButton(centralWidget);
    deleteButton->setText("Delete");
    deleteButton->setMaximumWidth(100);
    deleteButton->setMaximumHeight(40);
    rightLeftScreenPart->addWidget(deleteButton);

    searchButton = new QPushButton(centralWidget);
    searchButton->setText("search");
    searchButton->setMaximumWidth(100);
    searchButton->setMaximumHeight(40);
    rightLeftScreenPart->addWidget(searchButton);

    inputLabel = new QLabel(centralWidget);
    inputLabel->setText("input:");
    rightRightScreenPart->addWidget(inputLabel);
    inputLabel->setMaximumWidth(100);
    inputLabel->setMaximumHeight(20);

    outputLabel = new QLabel(centralWidget);
    outputLabel->setText("output:");
    rightLeftScreenPart->addWidget(outputLabel);
    outputLabel->setMaximumWidth(100);
    outputLabel->setMaximumHeight(20);


    input = new QTextEdit(centralWidget);
    rightLeftScreenPart->addWidget(input);
    input->setMaximumWidth(200);
    input->setMaximumHeight(200);

    output = new QTextEdit(centralWidget);
    output->setReadOnly(true);
    rightRightScreenPart->addWidget(output);
    output->setMaximumWidth(200);
    output->setMaximumHeight(200);

    screenSplit->addLayout(leftScreenPart);
    screenSplit->addLayout(rightScreenPart);

    rightScreenPart->addLayout(rightLeftScreenPart);
    rightScreenPart->addLayout(rightRightScreenPart);

    setCentralWidget(centralWidget);

}
MainWindow::~MainWindow() {

}