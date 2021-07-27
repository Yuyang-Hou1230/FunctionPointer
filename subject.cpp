#include "subject.h"

#include <QDebug>

//Subject::Subject()
//{

//}


void MessageManager::Register(MessageManager::MsgTypeOutside msgType, Observer *obj){
    registerMsg(msgType, obj);
}

void MessageManager::Register(MessageManager::MsgTypeInside msgType, Observer *obj){
    registerMsg(msgType, obj);
}

void MessageManager::PutOutsideMessage(MsgTypeOutside msgType, QVariant data){

    // 1、 加入消息队列中，通过算法进行处理（不需要加锁，程序自动分发）
//    Message msg(MSG_OUTSIDE, msgType, data);
//    mMsgList.enqueue(msg);

    // 2、 直接分发至消息注册对象进行处理（此处需要加锁）

    // 首先判断该消息是否被注册，否则打印警告信息
    mLock.lock();
    if(mObeservers.contains(msgType)){
        QList<Observer *> observers = mObeservers[msgType];
        if(!observers.isEmpty()){        // 判空
            for(auto p : observers){
                p->handleMessage(data);
            }
        }
    }
    else{
        qWarning() << QString("This msg : %1 , is not registered!").arg(msgType);
    }
    mLock.unlock();

}

void MessageManager::PutInsideMessage(MsgTypeInside msgType, QVariant data){
    // 1、 加入消息队列中，通过算法进行处理（不需要加锁，程序自动分发）
//    Message msg(MSG_INSIDE, msgType, data);
//    mMsgList.enqueue(msg);

    // 2、 直接分发至消息注册对象进行处理（此处需要加锁）

    // 首先判断该消息是否被注册，否则打印警告信息
    mLock.lock();
    if(mObeservers.contains(msgType)){
        QList<Observer *> observers = mObeservers[msgType];
        if(!observers.isEmpty()){        // 判空
            for(auto p : observers){
                p->handleMessage(data);
            }
        }
    }
    else{
        qWarning() << QString("This msg : %1 , is not registered!").arg(msgType);
    }
    mLock.unlock();
}

void MessageManager::registerMsg(int msgType, Observer *obj){
    // 判断键值是否存在
    if(mObeservers.contains(msgType)){

        //判断该消息的观察列表中对象是否已经存在，不存在则加入
        if(!mObeservers[msgType].contains(obj)){
            mObeservers[msgType].append(obj);
        }
    }
    else{       // 不存在则插入键值
        QList<Observer *> observers;
        observers.append(obj);
        mObeservers.insert(msgType, observers);
    }
}

void MessageManager::handleMessage()
{

}
