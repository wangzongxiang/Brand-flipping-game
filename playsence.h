#ifndef PLAYSENCE_H
#define PLAYSENCE_H

#include <QMainWindow>

class PlaySence : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlaySence(QWidget *parent = nullptr);
    PlaySence(int k);
    int k;//关卡号
    void paintEvent(QPaintEvent*);
signals:
    void back();
};

#endif // PLAYSENCE_H
