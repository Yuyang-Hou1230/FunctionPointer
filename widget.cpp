#include "widget.h"
#include "ui_widget.h"

#include "subject.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    StudentInfo info(18, "郑刚", "Qt工程师");
//    getInfo(getdata(info));

    Subject subject;
    subject.Register(&info,&Observer::handleMessage);

    subject.handleMessage(getdata(info));
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

