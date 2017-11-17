#ifndef BALA_H
#define BALA_H


#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>


class BALA :public QGraphicsItem
{
public:
    BALA();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    void colision();
    void Actualizar_aceleraciony();
    void Actualizar_aceleracionx();
    void  Actualizar_posicion();
    //void autocrear();
protected slots:
    void advance(int phase);
private:
    float x;
    float y;
    float radio;
    float masa;
    float K;
    float vx;
    float vy;
    float ax;
    float ay;
    float e;
    float coefres;
    bool flag;
};
#endif // BALA_H
