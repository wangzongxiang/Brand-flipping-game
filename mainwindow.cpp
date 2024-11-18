#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPaintEvent>
#include <QPainter>
#include <MyPushButton.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //配置主场景
    this->setFixedSize(700,600);
    this->setWindowIcon(QIcon(":/new/prefix1/bei.png"));
    this->setWindowTitle("翻牌子");
    connect(ui->actionquit,&QAction::triggered,this,[=](){
        this->close();
    });
    MyPushButton* sta1=new MyPushButton(":/new/prefix1/start1.png");
    sta1->setParent(this);
    sta1->move((this->width()-sta1->width())/2,this->height()-sta1->height());
    choosewindow =new chooseWindow;
    connect(sta1,&QPushButton::clicked,this,[=](){
        this->hide();
        choosewindow->show();
    });
    connect(choosewindow,&chooseWindow::chooseBack,this,[=](){
        this->show();
        choosewindow->hide();
    });


}
void MainWindow::paintEvent(QPaintEvent* ){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/new/prefix1/main.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/new/prefix1/welcom1.png");
    painter.drawPixmap(50,0,600,300,pix);


}
MainWindow::~MainWindow()
{
    delete ui;
}
