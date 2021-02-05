#ifndef CANYON_H
#define CANYON_H

#include <QObject>
#include <vector>
#include <math.h>
#include <iostream>
#include <QGraphicsItem>
#include "shot.h"

#define G 9.81
#define pi 3.141617
#define v_limit 720

class Canyon : public QObject, public QGraphicsItem {
    Q_OBJECT
public: //variables

private: //variables
    float posx, posy;
    float impact_multpliter;
    float impact_radio;
    float enemy_impact_radio;
    float distance;

public: //methods
    Canyon(float x_, float y_, float imp_);
    Canyon(float imp_);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    std::vector <Shot *> generate_offensive_shots(Canyon *target, bool print); //puntos 1 y 2 (target es el cañon que se quiere destruir)
    std::vector <Shot *> generate_defensive_shots(Canyon *origin, Shot *target, bool offensive_matters, bool print); //puntos 3 y 4 (target es el disparo que se quiere destruir y origin es el cañon que los disparó)
    std::vector<Shot *> generate_counter_offensive_shots(Canyon *defensive_canyon, Shot *defensive_shot, Shot *offensive_shot); //punto 5 (target_canyon es el cañon que se quiere destruir, target_shot es el disparo que hay que destruir, y mine es el disparo que hayq ue proteger)

    bool confirm_impact(Canyon *origin, Shot *ofense); //confirma que el diaparo impacta su destino (el cañon que realiza este calculo es el destino (this) )
    bool confirm_impact(Canyon *ofensive, Shot *of, Canyon *defensive, Shot *def);

    void print_results( std::vector <Shot *> shots);
    void print_results(Shot* shot);

    float getPosx() const;
    float getPosy() const;
    void setPosx(float value);
    void setPosy(float value);

    float getDistance() const;
    void setDistance(Canyon *destiny);
    void setDistance(float dis);

    float getImpact_radio() const;
    void setImpact_radio();

    void setEnemy_impact_radio(float value);

    float getImpact_multpliter() const;

private: //methods

signals:

};

#endif // CANYON_H
