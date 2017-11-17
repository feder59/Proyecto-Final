#include "circular.h"
#include <math.h>

#include <QDebug>

#define delta 0.009
#define grave -10


circular::circular()
{
    posx = 185;
    posy = 140;
    vel_W = 5;
    acel_W = 1.3;
    angulo = 0;
    radio = 15;
    long_cuer= 25;
    setPos(QPointF(posx,posy));

}

QRectF circular::boundingRect() const
{
    return QRectF(this->posx,this->posy,2*radio,2*radio);
}


void circular::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF rec = boundingRect();


    painter->setPen(Qt::red);
    painter->setBrush(Qt::gray);

    //painter->drawLine(posx,posy,posx+42,posy+32);
    //painter->drawLine(posx,posy,100,100);
    //painter.drawEllipse(XI,YI,XE,YE);
    painter->drawPolygon(rec);

}

void circular::advance(int phase)
{

    if(phase==0)
    return;
    else
       {
        this->Actualizar_angulo();
        this->Actulizar_aceleracion();
        this->Actualizar_posicion();
        this->setPos(QPointF(this->posx,this->posy));

    }


}

void circular::Actualizar_angulo()
{
    angulo = angulo + vel_W*delta + (acel_W*delta*delta)/2;

}
void circular::Actulizar_aceleracion()

{
    acel_W = grave*cos(angulo);

}
void circular::Actualizar_posicion()
{

    qDebug() <<"Angulo"<<angulo;

    posx = long_cuer*sin(angulo)+185;
    posy = long_cuer*cos(angulo)+140;
    update();

}
