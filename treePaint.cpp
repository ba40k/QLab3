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
    const int rootX = 150;
    const int rootY =0;
    const int shiftY = 40;
    std::function<void (Tree<int>::Node*,int,int,int,int,int,int)> recursiveDrawing = [&](Tree<int>::Node* vertex,int X,int Y, int parentX, int parentY,int leftBorder, int rightBorder) {
        if (vertex == nullptr) {
            return ;
        }
        std::cout<<X<<' '<<Y<<' '<<leftBorder<<' '<<rightBorder<<'\n';
        if (vertex!=tree.getRoot()) {
            painter.drawLine(QPoint(X+ellipseWidth/2,Y),QPoint(parentX + ellipseWidth/2,parentY+ellipseHeight));
        }
        painter.drawEllipse(X, Y, ellipseWidth, ellipseHeight);

        recursiveDrawing(vertex->getLeft(),leftBorder + (rightBorder-leftBorder)/4 ,Y + shiftY ,X,Y,leftBorder,rightBorder - (rightBorder-leftBorder)/2);
        recursiveDrawing(vertex->getRight(),rightBorder - (rightBorder-leftBorder)/4 ,Y + shiftY ,X,Y,(rightBorder + leftBorder)/2,rightBorder);

        return ;
    };

   recursiveDrawing(tree.getRoot(),rootX,rootY,rootX,rootY,0,300);
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
