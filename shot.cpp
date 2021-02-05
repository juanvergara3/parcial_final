#include "shot.h"

Shot::Shot() {
    x = 0;
    y = 0;
    V0 = 0;
   angle = 0;
   f_time = 0;
}
Shot::Shot(float xi, float yi, float posx, float posy, int vx_, int vy_, int angle_, float final_time, float impact_radio_) {
    x_i = xi;
    y_i = yi;
    x = posx;
    y = posy;
    Vx = vx_;
    Vy = vy_;
    angle = angle_;
    f_time = final_time;
    impact_radio = impact_radio_;
}
float Shot::getImpact_radio() const
{
    return impact_radio;
}

void Shot::set_end_pos() {
    x = x_i + Vx*f_time;
    y = y_i + Vy*f_time -(0.5*G*f_time*f_time);

    setPos(x, v_limit - y);
}

Shot::Shot(int velocity, int angle_) {
    V0 = velocity;
    angle = angle_;
}
Shot::~Shot() {

}

QRectF Shot::boundingRect() const {
    return QRectF(-2, -2, 4, 4);
}
void Shot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect().center(), impact_radio, impact_radio); // radious has to change
    painter->setBrush(Qt::blue);
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
float Shot::getF_time() const {
    return f_time;
}
int Shot::getV0() const {
    return V0;
}

float Shot::getX_i() const
{
    return x_i;
}
float Shot::getY_i() const
{
    return y_i;
}
int Shot::getVx() const
{
    return Vx;
}
int Shot::getVy() const
{
    return Vy;
}
