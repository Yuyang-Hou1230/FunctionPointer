#ifndef MSGMANAGER_H
#define MSGMANAGER_H

#include <QQueue>
#include <QVariant>
#include <QMutex>

#define MSG_MANAGER MessageManager::GetInstance()

/*1、及时通知
 *
 *
 *
 *
*/

// 观察者
class Observer
{
public:
    Observer(){

    };

    ~Observer(){

    };

public:
    // 消息处理虚函数
    virtual void handleMessage(QVariant data) = 0;
};


/*-----------------------------------------------------------------
* @类名           MessageManager
* @说明           消息管理类
* @作者           hyy
* @日期           2021/07/28
------------------------------------------------------------------*/
class MessageManager
{
public:
    static MessageManager *GetInstance(){
        static MessageManager m;
        return &m;
    }

public:

//外部消息类型
    enum MsgTypeOutside{
        Outside_1,
        Outside_2,
        Outside_3,
        Outside_4,
        MsgTypeOutside_num

    };

//内部消息类型（带参和不带参）
    enum MsgTypeInside{
        INSIDE_1 = MsgTypeOutside_num + 1,      // 使两个枚举类型的范围不一样，方便判断
        INSIDE_2,
        INSIDE_3,
        INSIDE_4,
    };

//接口
public:
    //注册及其处理函数函数
    void Register(MsgTypeOutside msgType, Observer *obj);

    void Register(MsgTypeInside msgType, Observer *obj);

    // 将外部消息放入队列中
    void PutOutsideMessage(MsgTypeOutside msgType, QVariant data);;

    // 将内部消息放入队列中
    void PutInsideMessage(MsgTypeInside msgType, QVariant data);;

private:
    //构造函数私有化
    MessageManager(){};


    void registerMsg(int msgType, Observer *obj);;

    //消息处理函数
    void handleMessage();


private:
    //消息来源类型
    enum MsgSourceType{
        MSG_OUTSIDE,
        MSG_INSIDE
    };

    struct Message{
        MsgSourceType sourceType;       // 消息源类型
        int msgType;                    // 具体的消息类型
        QVariant data;                  // 数据

        Message(){

        };

        Message(MsgSourceType source, int msgType, QVariant data) :
            sourceType(source),
            msgType(msgType),
            data(data)
        {

        };
    };

private:
     QMap<int, QList<Observer *>> mObeservers;
     QQueue<Message> mMsgList;

     // 消息处理互斥锁
     QMutex mLock;
};

#endif // MSGMANAGER_H
