#ifndef SHOT_H
#define SHOT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Shot : public QObject, public QGraphicsItem {
    Q_OBJECT
public: //variables
    float x, y; //posicion del disparo
    int V0; //velocidad inicial del disparo
    int f_time; //tiempo final de impacto
    int angle; //angulo inicial del disparo

private: //variables

public: //methods
    Shot(float posx, float posy, int velocity, int angle_, int final_time);
    Shot(int velocity, int angle_);
    Shot();
    ~Shot();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getAngle() const;
    int getV0() const;
    int getF_time() const;
    float getX() const;
    float getY() const;

    void setX(float value);
    void setY(float value);
    void setAngle(int value);
    void setF_time(int value);
    void setV0(int value);

private: //methods

};

#endif // SHOT_H
