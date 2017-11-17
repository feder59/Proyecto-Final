#include "estrellas.h"
#include "dialog.h"
#include <QPainter>
#include <QGraphicsScene>
#include "bala.h"

# include <QDebug>

Estrellas::Estrellas()
{
    int startY = 0;
    int startX = 0;

    startY = (qrand ()% 700 +10);
    startX = (qrand ()% 1000 +10);
    setPos(mapToParent(startX,startY));
}

QRectF Estrellas::boundingRect() const
{
    return QRect(0,0,20,20);
}
void Estrellas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();

    if (scene()->collidingItems(this).isEmpty())
    {

    }
    else {
        colision();
    }
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(rec);
}
void Estrellas::colision()
{
    QList<QGraphicsItem*> lista = collidingItems();
    for (int i=0;i<lista.size();i++){

        if (typeid(*lista[i])==typeid(BALA)){
        return;
    }
        else{
            scene()->removeItem(this);
            delete this;
            qDebug()<<" Estrella colisiono";
            return;
    }
    }
}



