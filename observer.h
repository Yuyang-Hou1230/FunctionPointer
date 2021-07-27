#ifndef OBSERVER_H
#define OBSERVER_H

#include <QVariant>


// 观察者
class Observer
{
public:
    Observer();
    ~Observer();

public:
    // 消息处理虚函数
    virtual void handleMessage(QVariant data) = 0;
};

#endif // OBSERVER_H
