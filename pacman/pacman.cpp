#include  "pacman.h"
#include <QGraphicsEllipseItem>
#include <QPainter>
#include "dialog.h"
#include <QFont>
#include "Score.h"
#include <QDebug>
#include <QMessageBox>
#include "bala.h"

extern Dialog * Dialog;
PACMAN::PACMAN()
{
    posx = 40;
    posy = 700;
    radio = 20;
    setPos(posx,posy);
    vidas = 3;
    flag_down = true;
    flag_lef = true;
    flag_rig = true;
    flag_up = true;
    score = 0;


}

QRectF PACMAN::boundingRect() const
{
    return QRect(-radio,-radio,2*radio,2*radio);
}

void PACMAN::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();


    qDebug()<<"Pacmanx"<<this->pos().x();
    qDebug()<<"Pacmany"<<this->pos().y();


   // score = new Score();
   // scene()->addItem(score);

    if (scene()->collidingItems(this).isEmpty())
    {
        this->flag_down = true;
        this->flag_lef = true;
        this->flag_rig = true;
        this->flag_up = true;
    }
    else {
        colision();

    }
    painter->setBrush(Qt::green);
    painter->drawEllipse(rec);
}
void PACMAN::colision()
{


            //agrego las lista con todo los objetos que colisionan para definir cada colision

            QList<QGraphicsItem *> lista = scene()->collidingItems(this);

           //si uno de los items es una estrella borrela y agregue puntaje

           for (int i = 0; i<lista.size(); i++){
               if (typeid(*(lista[i])) == typeid(Estrellas)){
                   // increase the score
                   score++;
                   return;
               }

           //si el pacman colisiono con un muro limite el movimiento segun sea este.

           else if (typeid(*(lista[i])) == typeid(QGraphicsLineItem)){





                float x1 = ((QGraphicsLineItem*) lista[i])->line().x1();
                float y1 = ((QGraphicsLineItem*) lista[i])->line().y1();
                float x2 = ((QGraphicsLineItem*) lista[i])->line().x2();
                float y2 = ((QGraphicsLineItem*) lista[i])->line().y2();

                qDebug()<<"x1"<< x1;
                qDebug()<<"x2"<< x2;

                qDebug()<<"y1"<< y1;
                qDebug()<<"y2"<< y2;

                float posyenlarecta;
                float posxenlarecta;

                qDebug()<<"Pacmanx"<<this->pos().x();
                qDebug()<<"Pacmany"<<this->pos().y();


                if (x2!=x1 && y2!=y1){
                    float m = (y2-y1)/(x2-x1);
                    qDebug()<<"m"<< m;
                    posxenlarecta = (1/m*(this->pos().y() - y1) + x1);
                    posyenlarecta = (m*(this->pos().x() - x1) + y1);



                    if (this->pos().x() <  posxenlarecta ){
                        flag_rig = false;
                    }
                    else{
                        flag_lef = false;
                    }
                    if (this->pos().y() >  posyenlarecta ){
                        flag_up = false;
                    }
                    else{
                        flag_down = false;
                    }
                }
                else if(y1!=y2){
                    posxenlarecta = x1;

                    if (this->pos().x() <  posxenlarecta ){
                        flag_rig = false;
                    }
                    else{
                        flag_lef = false;
                    }
                }
                else{
                    posyenlarecta = y1;

                    if (this->pos().y() >  posyenlarecta ){
                        flag_up = false;
                    }
                    else{
                        flag_down = false;
                    }
                }





            qDebug() << "colisono con linea";
            return;

           }
               else{
                   this->setPos(QPointF(40,700));
                   vidas--;

                   return;
               }

       }
}

bool PACMAN::getFlag_down()
{
    return flag_down;
}

bool PACMAN::getFlag_up()
{
    return flag_up;
}

bool PACMAN::getFlag_lef()
{
    return flag_lef;
}

bool PACMAN::getFlag_rig()
{
    return flag_rig;
}

void PACMAN::setFlag_down(bool value)
{
    flag_down = value;
}

void PACMAN::setFlag_up(bool values)
{
    flag_up = values;
}

void PACMAN::setFlag_lef(bool value)
{
    flag_lef = value;
}
void PACMAN::setFlag_rig(bool value){
    flag_rig = value;
}

int PACMAN::getscore()
{
    return score;
}

int PACMAN::getlives()
{
    return vidas;
}

float PACMAN::getvi() const
{
    return vidas;
}
void PACMAN::setvi(float value)
{
    vidas = value;
}


