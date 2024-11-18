#include "playsence.h"
#include <QDebug>
#include "mypushbutton.h"
#include <QPainter>
#include "mycoin.h"
#include <QVector>
#include "Data.h"
#include <QLabel>
#include <QPropertyAnimation>
PlaySence::PlaySence(int k){
    this->k=k;
    this->setFixedSize(500,600);
    this->setWindowTitle(QString("第%1关").arg(k));
    MyPushButton* mbtn1=new MyPushButton(":/new/prefix1/back1.png");
    mbtn1->setParent(this);
    mbtn1->move(this->width()-mbtn1->width(),this->height()-mbtn1->height());
    connect(mbtn1,&QPushButton::clicked,this,[=](){
        emit this->back();
    });
    Data* d=new Data();
    QVector<QVector<MyCoin*>> m;
    QVector<QVector<int>> t=d->num1.value(k);
    for(int i=0;i<4;i++){
        QVector<MyCoin*> temp;
        for(int j=0;j<4;j++){
            MyCoin* m1;
            if(t[i][j]==0){
                m1=new MyCoin(":/new/prefix1/f2.png");
                m1->flag=0;
            }else{
                m1=new MyCoin(":/new/prefix1/f1.png");
                m1->flag=1;
            }
            m1->x=i;
            m1->y=j;
            m1->setParent(this);
            m1->move(100+(m1->width()*j),150+((m1->height()+10)*i));
            temp.push_back(m1);
        }
        m.push_back(temp);
    }
    QLabel* label=new QLabel();
    label->setParent(this);
    QPixmap pix;
    pix.load(":/new/prefix1/succed1.png");
    //pix.scaled(pix.width()/50,pix.height()/50);
    label->setGeometry(0,0,pix.width()/3,pix.height()/3);
    label->setScaledContents(true);
    label->setPixmap(pix);
    label->move((this->width()-label->width())/2,-label->height());

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            connect(m[i][j],&QPushButton::clicked,[=](){
                int dx[]={-1,0,1,0};
                int dy[]={0,-1,0,1};
                m[i][j]->changeFlag();
                for(int k=0;k<4;k++){
                    if(i+dx[k]>=0&&i+dx[k]<4&&j+dy[k]>=0&&j+dy[k]<4){
                        m[i+dx[k]][j+dy[k]]->changeFlag();
                    }
                }
                bool iswin=true;
                for(int u=0;u<4;u++){
                    for(int v=0;v<4;v++){
                        if(m[u][v]->flag==0){
                            iswin=false;
                            break;
                        }
                    }
                }
                if(iswin==true){
                    qDebug()<<"win";
                    for(int u=0;u<4;u++){
                        for(int v=0;v<4;v++){
                            m[u][v]->iswin=true;
                        }
                    }
                    QPropertyAnimation* animation=new QPropertyAnimation(label,"geometry");
                    animation->setDuration(1000);
                    animation->setStartValue(QRect(label->x(),label->y(),label->width(),label->height()));
                    animation->setEndValue(QRect(label->x(),label->y()+label->height()+50,label->width(),label->height()));
                    animation->setEasingCurve(QEasingCurve::OutBounce);
                    animation->start();
                }
            });
        }
    }



}

void PlaySence::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/new/prefix1/title1.png");
    painter.drawPixmap(300,0,150,150,pix);
}
