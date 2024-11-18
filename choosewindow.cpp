#include "choosewindow.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QLabel>
#include "playsence.h"
#include <QDebug>
chooseWindow::chooseWindow(QWidget *parent)
    : QWidget{parent}
{
    this->setFixedSize(700,600);
    this->setWindowIcon(QIcon(":/new/prefix1/bei.png"));
    this->setWindowTitle("选择关卡");
    QMenuBar* bar=new QMenuBar(this);
    QMenu* me= bar->addMenu("开始");
    QAction* qu= me->addAction("退出");
    connect(qu,&QAction::triggered,this,[=](){
        this->close();
    });
    MyPushButton* mbtn=new MyPushButton(":/new/prefix1/back1.png");
    mbtn->setParent(this);
    mbtn->move(this->width()-mbtn->width(),this->height()-mbtn->height());
    connect(mbtn,&QPushButton::clicked,this,[=](){
        emit this->chooseBack();
    });
    for(int i=0;i<16;i++){
        MyPushButton* men=new MyPushButton(":/new/prefix1/bei1.png");

        men->setParent(this);
        men->move((men->width()+50)*(i%4)+100,(i/4)*(men->height()+20));
        QLabel* label=new QLabel();
        label->setParent(this);
        label->setFixedSize(men->width(),men->height());
        label->setText(QString::number(i+1));
        label->setStyleSheet("color: white;");
        label->setAlignment(Qt::AlignCenter);

        label->move((men->width()+50)*(i%4)+100,(i/4)*(men->height()+20));
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        connect(men,&QPushButton::clicked,this,[=](){
            this->hide();
            this->playsence=new PlaySence(i+1);
            this->playsence->show();
            connect(this->playsence,&PlaySence::back,this,[=](){
                this->playsence->hide();
                this->show();
            });
        });

    }

}

void chooseWindow::paintEvent(QPaintEvent*){
    QPainter paint(this);
    QPixmap pix;
    pix.load(":/new/prefix1/naci.png");
    paint.drawPixmap(0,0,700,600,pix);
}
