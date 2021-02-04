#ifndef CANYON_H
#define CANYON_H

#include <QObject>

class Canyon : public QObject
{
    Q_OBJECT
public:
    explicit Canyon(QObject *parent = nullptr);

signals:

};

#endif // CANYON_H
