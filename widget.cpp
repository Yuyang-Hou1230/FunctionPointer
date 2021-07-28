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
    TeacherInfo info4(21, "aaa4", "Qt工程师");
//    getInfo(getdata(info));

    MSG_MANAGER->Register(MessageManager::INSIDE_1, this);


    MSG_MANAGER->PutInsideMessage(MessageManager::INSIDE_1, getdata(info1));
    MSG_MANAGER->PutInsideMessage(MessageManager::INSIDE_1, getdata(info4));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleMessage(QVariant data)
{
    if(data.canConvert<StudentInfo>()){
        StudentInfo info = data.value<StudentInfo>();
        qDebug() << data.type();
        qDebug() << "Student: " << info.age << info.name << info.description;
    }

    if(data.canConvert<TeacherInfo>()){
        TeacherInfo info = data.value<TeacherInfo>();
        qDebug() << data.type();
        qDebug() << "Teacher: " << info.age << info.name << info.description;
    }
}


