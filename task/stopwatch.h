#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QObject>
#include <QTimer>


class Stopwatch : public QObject
{
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);
    virtual ~Stopwatch(void);
    QTimer *tPtr = nullptr;

signals:
    void sig_sendStart(void);
};

#endif // STOPWATCH_H
