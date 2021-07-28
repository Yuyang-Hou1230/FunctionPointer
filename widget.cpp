#include "widget.h"
#include "ui_widget.h"

#include "msgmanager.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    StudentInfo info1(18, "aaa1", "Qt工程师");
    StudentInfo info2(19, "aaa2", "Qt工程师");
    StudentInfo info3(20, "aaa3", "Qt工程师");
    StudentInfo info4(21, "aaa4", "Qt工程师");
//    getInfo(getdata(info));

    MessageManager msgManager;
    msgManager.Register(MessageManager::INSIDE_1, &info1);
    msgManager.Register(MessageManager::INSIDE_1, &info2);
    msgManager.Register(MessageManager::INSIDE_1, &info3);
    msgManager.Register(MessageManager::INSIDE_1, &info4);

    msgManager.PutInsideMessage(MessageManager::INSIDE_1, getdata(info1));
    msgManager.PutInsideMessage(MessageManager::INSIDE_1, getdata(info2));
    msgManager.PutInsideMessage(MessageManager::INSIDE_1, getdata(info3));
    msgManager.PutInsideMessage(MessageManager::INSIDE_1, getdata(info4));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::getInfo(QVariant data)
{
    if(data.canConvert<StudentInfo>()){
        StudentInfo info = data.value<StudentInfo>();
        qDebug() << data.type();
        qDebug() << info.age << info.name << info.description;
    }
}

