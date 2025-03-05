//
// Created by radamir on 04.03.25.
//


#include "treePaint.h"
void treePaint::paintEvent(QPaintEvent *event) {
    if (tree.getRoot() == nullptr) {
        return ;
    }
    QPainter painter(this);
    painter.setPen(Qt::black);
    const int ellipseWidth = 30;
    const int ellipseHeight = 30;
    const int rootX = 200;
    const int rootY =0;
    const int leftShift = 30;
    const int rightShift = 30;
    const int topShift = 30;
    std::function<void (Tree<int>::Node*,int,int,int,int)> recursiveDrawing = [&](Tree<int>::Node* vertex, int X, int Y,int parentX, int parentY) {
        if (vertex == nullptr) {
            return ;
        }
        if (vertex == tree.getRoot()) {
            painter.drawEllipse(X, Y, ellipseWidth, ellipseHeight);
            recursiveDrawing(vertex->getLeft(),X-leftShift,Y+topShift,X,Y);
            recursiveDrawing(vertex->getRight(),X+rightShift,Y+topShift,X,Y);
            return ;
        }
        painter.drawEllipse(X, Y, ellipseWidth, ellipseHeight);

        recursiveDrawing(vertex->getLeft(),X-leftShift,Y+topShift,X,Y);
        recursiveDrawing(vertex->getRight(),X+rightShift,Y+topShift,X,Y);

        return ;
    };

   recursiveDrawing(tree.getRoot(),0,0,200,0);
}
void treePaint::treeDelete(int data) {
    tree.erase(data);
}
void treePaint::treeInsert(int data) {
    tree.insert(data);
}
bool treePaint::treeSearch(int data) {
    return tree.search(data);
}
treePaint::treePaint(QWidget *parent) {
  update();
}
QVector<int> treePaint::getForwardTraverse() {
    QVector<int> res;
    tree.forwardTraversal(tree.getRoot(),res);
    return res;
}
QVector<int> treePaint::getBackwardTraverse() {
    QVector<int> res;
    tree.backwardTraversal(tree.getRoot(),res);
    return res;
}
QVector<int> treePaint::getInOrderTraverse() {
    QVector<int> res;
    tree.inOrderTraversal(tree.getRoot(),res);
    return res;
}
treePaint::~treePaint() {

}
