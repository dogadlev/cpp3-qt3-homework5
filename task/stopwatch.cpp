#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject{parent}
{
    tPtr = new QTimer(this);
    QObject::connect(tPtr, &QTimer::timeout, this, &Stopwatch::recieveTimeout);
    setInterval(100);
}

Stopwatch::~Stopwatch()
{
    delete tPtr;
}

void Stopwatch::setInterval(int &&interval)
{
    this->interval = interval;
}

void Stopwatch::startTimer()
{
    tPtr->start(interval);
    start = true;
}

void Stopwatch::stopTimer()
{
    tPtr->stop();
    start = false;
}

void Stopwatch::updateTime()
{
    time += static_cast<double>(interval)/1000;
}

QString Stopwatch::getTime() const
{
    return QString("%1").arg(time);
}

bool Stopwatch::isStarted() const
{
    return start;
}

QString Stopwatch::getLoop()
{
    ++loop;
    return QString("%1").arg(loop);
}

QString Stopwatch::getLoopTime()
{
    double res = time - loopTime;
    loopTime = time;
    return QString("%1").arg(res);
}

void Stopwatch::clear()
{
    time = 0.0;
    loopTime = 0.0;
    loop = 0;
}

void Stopwatch::recieveTimeout()
{
    Stopwatch::updateTime();
    emit timeoutSignal();
}
