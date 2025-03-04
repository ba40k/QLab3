//
// Created by radamir on 04.03.25.
//

#ifndef TREEPAINT_H
#define TREEPAINT_H

#include <QWidget>
#include <QPainter>
#include <QApplication>

class treePaint : public QWidget {
  Q_OBJECT;
  private:
    void paintEvent(QPaintEvent *event) override;
    public:
     treePaint(QWidget *parent = nullptr);


};



#endif //TREEPAINT_H
