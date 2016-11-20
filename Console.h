#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>
#include <QJSValue>
#include <QTextStream>

class Console : public QObject
{
    Q_OBJECT
    QTextStream out;

public:
    Console();
    virtual ~Console();

    Q_INVOKABLE QJSValue print(QString cb);
};

#endif /* CONSOLE_H */
