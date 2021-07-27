#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"

#include <QVariant>

/*1、及时通知
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/


class Subject
{
public:
    Subject(){

    };

//接口
public:

    void Register(Observer *t, void (Observer::*func)(QVariant)){
        mObeservers.insert(t, func);
    }

    void Notify(){

    }

    void handleMessage(QVariant data);

private:


private:
     QMap<Observer *, void (Observer::*)(QVariant)> mObeservers;
};

#endif // SUBJECT_H
