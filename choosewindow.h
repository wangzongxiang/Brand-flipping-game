#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QWidget>
#include "playsence.h"
class chooseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit chooseWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    PlaySence* playsence=NULL;
signals:
    void chooseBack();
};

#endif // CHOOSEWINDOW_H
