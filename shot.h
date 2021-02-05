#ifndef SHOT_H
#define SHOT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <math.h>

#define G 9.81
#define v_limit 720

class Shot : public QObject, public QGraphicsItem {
    Q_OBJECT
public: //variables
    float x_i, y_i;
    float x, y; //posicion del disparo
    float V0; //velocidad inicial del disparo
    float Vx, Vy;
    float f_time; //tiempo final de impacto
    int angle; //angulo inicial del disparo
    float impact_radio; //radio de impacto ya multiplicado por la distancia

    std::string type;

private: //variables

public: //methods
    Shot(float xi, float yi, float posx, float posy, float vx_, float vy_, int angle_, float final_time, float impact_radio, std::string type);
    Shot(int velocity, int angle_, std::string type);
    Shot();
    ~Shot();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    int getAngle() const;
    float getV0();
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

    float getVx() const;

    float getVy() const;

    std::string getType() const;

private: //methods

};

#endif // SHOT_H
