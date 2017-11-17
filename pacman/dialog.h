#ifndef DIALOG_H
#define DIALOG_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QApplication>
#include <QDialog>
#include <QKeyEvent>
#include <pacman.h>
#include <QEvent>
#include <QList>
#include "estrellas.h"
//#include "Score.h"
#include <QTimer>
#include <bala.h>
#include "circular.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;

    //QGraphicsItem *llegada;
    QList<QLineF> lineas;
    PACMAN *pacman;
    Estrellas *estre;
    //Score *score;
    QTimer *timer;
    BALA *bala;
    circular *bola;
    QTimer *timer2;
    QTimer *timer3;

    int scenario;
    //int Score;
    //void score();
    //void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    void cam_nivel(int);
public slots:
    void agregue_bala();
    void on_score_overflow();
    void on_vidas_overflow();
    void on_score_2_overflow();
    void on_vidas_2_overflow();
};

#endif // DIALOG_H
