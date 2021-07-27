#ifndef OBSERVER_H
#define OBSERVER_H

#include <QVariant>

//观察者
class Observer
{
public:
    Observer();

public:
    virtual void handleMessage(QVariant data) = 0;
};

#endif // OBSERVER_H
