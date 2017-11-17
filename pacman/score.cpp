#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",20));
    setPos(QPointF(-120,0));
}

void Score::incrementar(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: +1
}

int Score::getScore(){
    return score;
}

QRectF Score::boundingRect() const
{
    return QRect(-120,0,50,40);
}


void Score::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
}
