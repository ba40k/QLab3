#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) {

    traversalOrder.resize(3,0);

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
    rightLeftScreenPart->addWidget(inputLabel);
    inputLabel->setMaximumWidth(100);
    inputLabel->setMaximumHeight(20);

    outputLabel = new QLabel(centralWidget);
    outputLabel->setText("output:");
    rightRightScreenPart->addWidget(outputLabel);
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

    treePainter = new treePaint(centralWidget);
    leftScreenPart->addWidget(treePainter);

    screenSplit->addLayout(leftScreenPart);
    screenSplit->addLayout(rightScreenPart);

    rightScreenPart->addLayout(rightLeftScreenPart);
    rightScreenPart->addLayout(rightRightScreenPart);

    connect(insertButton, &QPushButton::clicked, this, &MainWindow::insert);
    connect(searchButton, &QPushButton::clicked, this, &MainWindow::search);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::erase);
    connect(forwardTraversalFlag, &QRadioButton::clicked, this, &MainWindow::forwardTraversalPressed);
    connect(backwardTraversalFlag, &QRadioButton::clicked, this, &MainWindow::backwardTraversalPressed);
    connect(inOrderTraversalFlag, &QRadioButton::clicked, this, &MainWindow::inOrderTraversalPressed);


    setCentralWidget(centralWidget);

}
void MainWindow::insert() {

    int data = input->toPlainText().toInt();
  //  std::cout<<data<<'\n';
    input->clear();
    output->clear();
    treePainter->treeInsert(data);
  //  std::cout<<treePainter->treeSearch(data)<<'\n';
    QVector<int> currentTraverse;
    if (traversalOrder[0]) {
        currentTraverse = treePainter->getForwardTraverse();
    }
    if (traversalOrder[1]) {
        currentTraverse = treePainter->getBackwardTraverse();
    }
    if (traversalOrder[2]) {
        currentTraverse = treePainter->getInOrderTraverse();
    }

    QString outputText;

    for (auto num : currentTraverse) {
        QString numStr;
        numStr.setNum(num);
        outputText.append(numStr+ " ");
    }

    output->setText(outputText);

    treePainter->update();
}
void MainWindow::search() {
    int data = input->toPlainText().toInt();
    input->clear();
    output->clear();
    if ( treePainter->treeSearch(data)) {
        output->setText("true");
    } else {
        output->setText("false");
    }

}
void MainWindow::erase() {


    int data = input->toPlainText().toInt();
    input->clear();

    output->clear();
    treePainter->treeDelete(data);
    QVector<int> currentTraverse;
    if (traversalOrder[0]) {
        currentTraverse = treePainter->getForwardTraverse();
    }
    if (traversalOrder[1]) {
        currentTraverse = treePainter->getBackwardTraverse();
    }
    if (traversalOrder[2]) {
        currentTraverse = treePainter->getInOrderTraverse();
    }

    QString outputText;

    for (auto num : currentTraverse) {
        QString numStr;
        numStr.setNum(num);
        outputText.append(numStr+ " ");
    }

    output->setText(outputText);
    treePainter->update();

}

void MainWindow::forwardTraversalPressed() {
    std::cout<<124;

        forwardTraversalFlag->setChecked(true);
        traversalOrder[0] = 1;
        backwardTraversalFlag->setChecked(false);
        traversalOrder[1] = 0;
        inOrderTraversalFlag->setChecked(false);
        traversalOrder[2] = 0;
        QVector<int> currentTraverse = treePainter->getForwardTraverse();

        QString outputText;

        for (auto num : currentTraverse) {
            QString numStr;
            numStr.setNum(num);
            outputText.append(numStr+ " ");
        }

        output->setText(outputText);

}

void MainWindow::backwardTraversalPressed() {

        backwardTraversalFlag->setChecked(true);
        traversalOrder[1] = 1;
        forwardTraversalFlag->setChecked(false);
        traversalOrder[0] = 0;
        inOrderTraversalFlag->setChecked(false);
        traversalOrder[2] = 0;

        QVector<int> currentTraverse = treePainter->getBackwardTraverse();

        QString outputText;

        for (auto num : currentTraverse) {
            QString numStr;
            numStr.setNum(num);
            outputText.append(numStr+ " ");
        }

        output->setText(outputText);

}

void MainWindow::inOrderTraversalPressed() {

        inOrderTraversalFlag->setChecked(true);
        traversalOrder[2] = 1;
        forwardTraversalFlag->setChecked(false);
        traversalOrder[0] = 0;
        backwardTraversalFlag->setChecked(false);
        traversalOrder[1] = 0;
        QVector<int> currentTraverse = treePainter->getInOrderTraverse();

        QString outputText;

        for (auto num : currentTraverse) {
            QString numStr;
            numStr.setNum(num);
            outputText.append(numStr + " ");
        }

        output->setText(outputText);

}

MainWindow::~MainWindow() {

}