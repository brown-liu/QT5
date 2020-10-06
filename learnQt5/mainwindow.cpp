#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QPushButton>
#include <QDebug>
#include <QToolBar>
#include <QMenu>
#include <QAction>
#include <iostream>

using namespace std;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set screen size// width * height

    resize(800,600);


    //QPushButton

   QPushButton * btn=new QPushButton();
   btn->resize(90,40);
   btn->setText("PushPush");
   btn->setParent(this);
   btn->move(400,300);

   //connet and lambda // in [], set range which variable need access

   connect (btn,&QPushButton::clicked,this, []()
   {
       qDebug() << '\a'<<endl;
   });


   //Menubar, ONLY one in one app

   QMenuBar *bar = menuBar();
   setMenuBar(bar);

    QMenu *filemenu = bar->addMenu("FILE");

    QMenu *editmenu = bar->addMenu("EDIT");

    QMenu *viewmenu = bar->addMenu("VIEW");

    QMenu *toolsmenu = bar->addMenu("TOOL");

    QMenu *windowmenu = bar->addMenu("WINDOW");

    QMenu *helpmenu = bar->addMenu("HELP");

    QAction *newAction = filemenu->addAction("new");
    filemenu->addSeparator();
    QAction *exitAction = filemenu->addAction("Exit");


    //toolbar

    QToolBar *toolbar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolbar);

    toolbar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);

    toolbar->addAction(newAction);
    toolbar->addSeparator();
    toolbar->addAction(exitAction);
   QPushButton *btn2=new QPushButton("CLOSE",this);
   toolbar->addWidget(btn2);
   connect(btn2,&QPushButton::clicked,this,&QMainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
    cout <<"HOHHOHO"<<endl;
}

