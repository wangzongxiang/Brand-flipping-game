#include "mypushbutton.h"

MyPushButton::MyPushButton(QString image,QString pressImg){
    this->image=image;
    this->pressImg=pressImg;
    QPixmap pix;
    bool t=pix.load(image);
    if(!t){
        qDebug()<<"图片加载失败";
        return;
    }
    this->setFixedSize(pix.width()/7,pix.height()/7);
    this->setStyleSheet("QPushButton{border:0px})");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width()/7,pix.height()/7));
}
