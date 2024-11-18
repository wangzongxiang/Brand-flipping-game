#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    // explicit MyPushButton(QPushButton *parent = nullptr);
    MyPushButton(QString image,QString pressImg="");
    QString image;
    QString pressImg;

signals:
};

#endif // MYPUSHBUTTON_H
