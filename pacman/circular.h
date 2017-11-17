#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <QGraphicsItem>
#include <QPainter>

class circular :public QGraphicsItem
{
public:
    circular();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void Actualizar_angulo();
    void Actulizar_aceleracion();
    void Actualizar_posicion();
protected slots:
    void advance(int phase);

private:
    float posx;
    float posy;
    float angulo;
    float vel_W;
    float acel_W;
    float radio;
    float long_cuer;


};
#endif // CIRCULAR_H
