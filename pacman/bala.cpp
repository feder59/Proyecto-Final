#include "bala.h"
#include <math.h>
#include "estrellas.h"
#define delta 0.1

BALA::BALA()
{
    radio = 15;
    masa = 558;
    vx = -34;
    vy = -20;
    K = 0.009;
    e =(qrand() % 1 + 0.5);
    int startX = 240;
    int startY = 40;
    x = startX;
    y = startY;
    setPos(QPointF(startX,startY));
}

QRectF BALA::boundingRect() const
{

    return QRectF(this->x,this->y,2*radio,2*radio);

}
void BALA::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   QRectF rec = boundingRect();
   //determiar si hay colision

   if (scene()->collidingItems(this).isEmpty())
    {
        //no hay colision
        painter->setBrush(Qt::red);
    }
    else{
        //hubo colision.
        painter->setBrush(Qt::red);
        //cambian posicion o direccion
        colision();
    }
    painter->setPen(Qt::yellow);
    painter->drawEllipse(rec);
}
void BALA::advance(int phase){
    //autocrear();
    if(phase==0) return;
    else{
        //ACTUALIZACION DE LAS ACELERACIONES Y POSCION DE L OBJETO.
        this->Actualizar_aceleracionx();
        this->Actualizar_aceleraciony();
        this->Actualizar_posicion();
        this->setPos(QPointF(this->x,this->y));
        this->rotation();

    }
}

void BALA::colision()
{
    QList<QGraphicsItem*> lista=collidingItems();
    for(int i=0;i<lista.size();i++){
        if (typeid(*lista[i])==typeid(Estrellas)){
            return;
        }
        else{
        delete this;
        return;
        }
}
}

void BALA::Actualizar_aceleraciony()
{
    //ANGULO DE MOVIMIENTO.
    float ang = atan2(vy,vx);
    //MAGNITUD DE LA LA VELOCIDAD.
    float magvel= pow(this->vy,2)+ pow(this->vx,2);
    //DESACELERACION DEL CUALPO , ACCELERACION GENERAL EN Y.
    ay = (-(K*magvel*pow(radio,2)*sin(ang)))/masa +10 ;
}

void BALA::Actualizar_aceleracionx()
{

    //ANGULO DE MOVIMIENTO.
    float ang = atan2(this->vy,this->vx);
    float magvel = 0;
    //MAGNITUD DE LA LA VELOCIDAD.
    magvel = pow(this->vy,2)+ pow(this->vx,2);
    //DESACELERACION DEL CUALPO , ACCELERACION GENERAL EN X
    ax = -(K*magvel*pow(radio,2)*cos(ang))/masa ;
}
void BALA::Actualizar_posicion()

{

    //ACTUALIZACION DE LAS VELOSCIDADES EN X Y Y

    this->vx = this->ax*delta + this->vx;
    this->vy = this->ay*delta + this->vy;

    //ECUACIONES DE POCISION EN X y Y;
    this->x = this->ax*(delta*delta)/2 + this->vx*delta + this->x;
    this->y = this->ay*(delta*delta)/2 + this->vy*delta + this->y;
    update();

}

