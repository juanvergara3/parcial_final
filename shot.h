#ifndef SHOT_H
#define SHOT_H

#include <QObject>

class Shot : public QObject
{
    Q_OBJECT
public:
    explicit Shot(QObject *parent = nullptr);

signals:

};

#endif // SHOT_H
