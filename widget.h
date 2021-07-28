#ifndef WIDGET_H
#define WIDGET_H

#include "msgmanager.h"
                                     \
#include <QWidget>
#include <QVariant>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


struct StudentInfo{
    int age;
    QString name;
    QString description;

    StudentInfo(){

    };

    StudentInfo(int age, QString name, QString desc){
        this->age = age;
        this->name = name;
        this->description = desc;
    }
};

Q_DECLARE_METATYPE(StudentInfo)

struct TeacherInfo{
    int age;
    QString name;
    QString description;

    TeacherInfo(){

    };

    TeacherInfo(int age, QString name, QString desc){
        this->age = age;
        this->name = name;
        this->description = desc;
    }
};

Q_DECLARE_METATYPE(TeacherInfo)



template <typename T>
QVariant getdata(T t){
    QVariant data;
    data.setValue(t);

    return data;
}

class Widget : public QWidget, public Observer
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void handleMessage(QVariant data) override;



private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
