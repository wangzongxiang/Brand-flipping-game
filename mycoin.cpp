#include "mycoin.h"

// MyCoin::MyCoin(QPushButton *parent)
//     : QWidget{parent}
// {}
MyCoin::MyCoin(QString btnimg){
    QPixmap pix;
    bool t=pix.load(btnimg);
    if(!t){
        qDebug()<<"图片加载失败";
        return;
    }
    this->setFixedSize(80,100);
    this->setStyleSheet("QPushButton{border:0px})");
    this->setIcon(pix);
    this->setIconSize(QSize(80,100));
}

void MyCoin::changeFlag(){
    QPixmap pix;
    if(this->flag==0){
        this->flag=1;
        pix.load(":/new/prefix1/f1.png");
    }else{
        this->flag=0;
        pix.load(":/new/prefix1/f2.png");
    }
    this->setFixedSize(80,100);
    this->setStyleSheet("QPushButton{border:0px})");
    this->setIcon(pix);
    this->setIconSize(QSize(80,100));
}

void MyCoin::mousePressEvent(QMouseEvent* e){
    if(this->iswin==true) return;
    else QPushButton::mousePressEvent(e);
}
