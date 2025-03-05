//
// Created by radamir on 04.03.25.
//


#include "treePaint.h"
void treePaint::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(Qt::green);
    painter.drawRect(0, 0, 350, 400);
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
