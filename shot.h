#ifndef SHOT_H
#define SHOT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

#define G 9.81
#define v_limit 720

class Shot : public QObject, public QGraphicsItem {
    Q_OBJECT
public: //variables
    float x_i, y_i;
    float x, y; //posicion del disparo
    int V0; //velocidad inicial del disparo
    int Vx, Vy;
    float f_time; //tiempo final de impacto
    int angle; //angulo inicial del disparo
    float impact_radio; //radio de impacto ya multiplicado por la distancia

private: //variables

public: //methods
    Shot(float xi, float yi, float posx, float posy, int vx_, int vy_, int angle_, float final_time, float impact_radio);
    Shot(int velocity, int angle_);
    Shot();
    ~Shot();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getAngle() const;
    int getV0() const;
    float getF_time() const;
    float getX() const;
    float getY() const;

    void setX(float value);
    void setY(float value);
    void setAngle(int value);
    void setF_time(int value);
    void setV0(int value);

    float getImpact_radio() const;

    void set_end_pos();

    float getX_i() const;

    float getY_i() const;

    int getVx() const;

    int getVy() const;

private: //methods

};

#endif // SHOT_H
