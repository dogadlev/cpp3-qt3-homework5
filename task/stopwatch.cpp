#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject{parent}
{
    tPtr = new QTimer(this);
    tPtr->setInterval(100);
}

Stopwatch::~Stopwatch()
{
    delete tPtr;
}

void Stopwatch::sig_sendStart()
{
    tPtr->start();
}
