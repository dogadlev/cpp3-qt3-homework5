#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QObject>
#include <QTimer>
#include <QString>


class Stopwatch : public QObject
{
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);
    virtual ~Stopwatch(void);
    void setInterval(int &&interval);
    void startTimer(void);
    void stopTimer(void);
    QString getTime(void) const;
    bool isStarted(void) const;
    QString getLoop(void);
    QString getLoopTime(void);
    void clear(void);


signals:
    void timeoutSignal(void);

private:
    QTimer *tPtr = nullptr;
    int interval = 100;
    bool start = false;
    double time = 0.0;
    unsigned int loop = 0;
    double loopTime = 0.0;
    void updateTime(void);

private slots:
    void recieveTimeout(void);
};

#endif // STOPWATCH_H
