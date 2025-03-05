//
// Created by radamir on 04.03.25.
//

#ifndef TREEPAINT_H
#define TREEPAINT_H
#include "tree.h"
#include <QWidget>
#include <QPainter>
#include <QApplication>
#include <QVBoxLayout>

class treePaint : public QWidget {
  Q_OBJECT;
  private:
    void paintEvent(QPaintEvent *event) override;
    Tree<int> tree;
    public:
     void treeInsert(int data);
     void treeDelete(int data);
     bool treeSearch(int data);
     QVector<int> getForwardTraverse();
    QVector<int> getBackwardTraverse();
    QVector<int> getInOrderTraverse();
     treePaint(QWidget *parent = nullptr);
    ~treePaint();

};



#endif //TREEPAINT_H
