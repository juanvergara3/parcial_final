#include "shot.h"

Shot::Shot() {
    x = 0;
    y = 0;
    V0 = 0;
   angle = 0;
   f_time = 0;
}
Shot::Shot(float posx, float posy, int velocity, int angle_, int final_time) {
    x = posx;
    y = posy;
    V0 = velocity;
    angle = angle_;
    f_time = final_time;
}
Shot::Shot(int velocity, int angle_) {
    V0 = velocity;
    angle = angle_;
}
Shot::~Shot() {

}

QRectF Shot::boundingRect() const {
    //return QRectF(-width/2, -height/2, width, height);
}
void Shot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void Shot::setX(float value) {
    x = value;
}
void Shot::setY(float value) {
    y = value;
}

void Shot::setAngle(int value) {
    angle = value;
}
void Shot::setF_time(int value) {
    f_time = value;
}
void Shot::setV0(int value) {
    V0 = value;
}


float Shot::getX() const {
    return x;
}
float Shot::getY() const {
    return y;
}

int Shot::getAngle() const {
    return angle;
}
int Shot::getF_time() const {
    return f_time;
}
int Shot::getV0() const {
    return V0;
}
