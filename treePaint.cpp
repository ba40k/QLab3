//
// Created by radamir on 04.03.25.
//


#include "treePaint.h"
void treePaint::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(Qt::green);
    painter.drawRect(0, 0, 350, 400);
}
treePaint::treePaint(QWidget *parent) {
  update();
}
