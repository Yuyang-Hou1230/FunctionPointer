#include "subject.h"

//Subject::Subject()
//{

//}

void Subject::handleMessage(QVariant data)
{
    QMap<Observer *, void (Observer::*)(QVariant)>::iterator ite;

    for(ite = mObeservers.begin(); ite != mObeservers.end(); ite++){
        (ite.key()->*ite.value())(data);
    }
}
