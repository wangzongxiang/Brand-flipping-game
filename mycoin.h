#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QString>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    // explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString btnimg);
    void changeFlag();
    int x;
    int y;
    bool flag;
    bool iswin=false;
    void mousePressEvent(QMouseEvent* e);
signals:
};

#endif // MYCOIN_H
