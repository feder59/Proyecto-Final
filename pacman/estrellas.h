#ifndef ESTRELLAS_H
#define ESTRELLAS_H
#include <QGraphicsItem>
#include "pacman.h"
class Estrellas:public QGraphicsItem
{
public:
    Estrellas();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void colision();

};

#endif // ESTRELLAS_H
