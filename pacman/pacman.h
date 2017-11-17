#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsObject>
//#include "Score.h"
#include "bala.h"


class PACMAN:public QGraphicsItem
{

public:

    PACMAN();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    void colision();
    float getvi() const;
    void setvi(float value);
    bool getFlag_down();
    bool getFlag_up();
    bool getFlag_lef();
    bool getFlag_rig();

    void setFlag_down(bool value);
    void setFlag_up(bool values);
    void setFlag_lef(bool value);
    void setFlag_rig(bool value);
    int getscore();
    int getlives();
private:
    int score;
    qreal radio;
    int  vidas;
    float posx;
    float posy;
    bool flag_up;
    bool flag_down;
    bool flag_lef;
    bool flag_rig;
    //Score *score;
    BALA *bala;


};



#endif // PACMAN_H
