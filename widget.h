#ifndef WIDGET_H
#define WIDGET_H

#include "observer.h"
                                     \
#include <QWidget>
#include <QVariant>
#include <QDebug>




QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


struct StudentInfo : public Observer{
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

    void handleMessage(QVariant data) override{
        if(data.canConvert<StudentInfo>()){
            StudentInfo info = data.value<StudentInfo>();
            qDebug() << data.type();
            qDebug() << info.age << info.name << info.description;
        }
    };
};

Q_DECLARE_METATYPE(StudentInfo)



template <typename T>
QVariant getdata(T t){
    QVariant data;
    data.setValue(t);

    return data;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void getInfo(QVariant data);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
