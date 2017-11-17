#include "dialog.h"
#include "ui_dialog.h"
#include <QGraphicsRectItem>
//#include<QList>
#include "bala.h"
//#include <QApplication>
#include <QDebug>
#include "circular.h"
#include "escenario.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //this->showMaximized();
    scene = new QGraphicsScene(this);

    //asignacion para agragar la scena
    ui ->graphicsView->setRenderHint(QPainter::Antialiasing);

    //para agrgar el escenario creado
    ui->graphicsView->setScene(scene);

    //pintura escenario fondo
    ui->graphicsView->setBackgroundBrush(Qt::black);
    //tamaño del scenario
    scene->setSceneRect(0,0,1040,790);
    ui->graphicsView->scale(1,1);


    //por defecto inicia en el primer escenario
    scenario = 1;

    cam_nivel(scenario);


}



Dialog::~Dialog()
{
    delete ui;
    delete scene;
    //delete pacman;
    delete bola;
}


void Dialog::keyReleaseEvent(QKeyEvent *ev )
{


   ui->score->display(pacman->getscore());
   ui->vidas->display(pacman->getlives());
   if(ev->key()==Qt::Key_Right && pacman->getFlag_rig()==true)
    {
       pacman->setPos(pacman->x()+4,pacman->y());
    }
    else if(ev->key()==Qt::Key_Left && pacman->getFlag_lef()==true)
    {

       pacman->setPos(pacman->x()-4,pacman->y());
       scenario=1;

       scene->clear();
       delete timer;
       delete timer2;
       delete timer3;
       cam_nivel(scenario);

    }
    else if(ev->key()==Qt::Key_Up && pacman->getFlag_up()==true)
    {

       pacman->setPos(pacman->x(),pacman->y()-4);

    }
    else if(ev->key()==Qt::Key_Down && pacman->getFlag_down()==true)

    {
       pacman->setPos(pacman->x(),pacman->y()+4);
       scenario=2;
       scene->clear();
       delete timer;
       delete timer2;
       delete timer3;
       cam_nivel(scenario);
    }



}
void Dialog::agregue_bala(){
    qDebug() << "Hola";
    // crear un enemigo
    bala = new BALA();
    scene->addItem(bala);
}

void Dialog::on_score_overflow()
{

}

void Dialog::on_vidas_overflow()
{

}


void Dialog::on_score_2_overflow()
{

}

void Dialog::on_vidas_2_overflow()
{

}




void Dialog::cam_nivel(int scenario){

    QPointF botizq = scene->sceneRect().topLeft();
    QPointF botder = scene->sceneRect().topRight();
    QPointF topizq = scene->sceneRect().bottomLeft();
    QPointF topder = scene->sceneRect().bottomRight();

    QLineF Lineasuperior(botizq.x(),botizq.y(),botder.x(),botder.y());
    QLineF Lineainferior(topizq,topder);
    QLineF Lineaizquierda(scene->sceneRect().bottomLeft(),scene->sceneRect().topLeft());
    QLineF Lineaderecha(scene->sceneRect().bottomRight(),scene->sceneRect().topRight());

    QPen bordes = QPen(Qt::blue);

    scene->addLine(Lineasuperior,bordes);
    scene->addLine(Lineainferior,bordes);
    scene->addLine(Lineaderecha,bordes);
    scene->addLine(Lineaizquierda,bordes);
    QPen ejes = QPen(Qt::blue);

    if(scenario==1){
        QLineF uno((topizq.x()+topder.x())/4,(botder.y()+topder.y())*3/4,(topizq.x()+topder.x())/4,(botder.y()+topder.y())/4);
        QLineF dos((botizq.x()+botder.x())/2 ,botder.y(),(botizq.x()+botder.x())/2, (botder.y()+topizq.y())/2);
        QLineF segunda(topizq.x(),topizq.y(),(topizq.x()+topder.x())/4,(botder.y()+topder.y())*3/4);
        QLineF tercera((topizq.x()+topder.x())/4,(botder.y()+topder.y())/2,(botder.x()+botizq.x())*1/8,(topizq.y()+botizq.y())/2);
        QLineF cuarta((topizq.x()+topder.x()/4),(botizq.y()+topizq.y())/4,(botizq.x()+botder.x())*3/8,(botder.y()+topder.y())/4);
        QLineF quinta((topizq.x()+topder.x())/4,(botder.y()+topder.y())*3/4,(topder.x()+topizq.x())*3/4,(botizq.y()+topizq.y())*3/4);
        QLineF sexta((topizq.x()+topder.x())*2/4,(botder.y()+topder.y())*2/4,(topder.x()+topizq.x())*3/8,(botder.y()+topizq.y())/2);
        QLineF septima((topder.x()+topizq.x())*3/4,(botizq.y()+topizq.y())*3/4,(botder.x()+botizq.x())*3/4,(topder.y()+botder.y())/4);
        QLineF octava((topder.x()+topizq.x())*5/8,(botizq.y()+topizq.y())/4,(botder.x()+botizq.x())*7/8,(topder.y()+botder.y())/4);

        scene->addLine(uno,ejes);
        scene->addLine(dos,ejes);
        scene->addLine(segunda,ejes);
        scene->addLine(tercera,ejes);
        scene->addLine(cuarta,ejes);
        scene->addLine(quinta,ejes);
        scene->addLine(sexta,ejes);
        scene->addLine(septima,ejes);
        scene->addLine(octava,ejes);

    }
    else if(scenario==2){

        QLineF uno((topizq.x()+topder.x())/5,(topizq.y()+botizq.y())*3/5 ,(topizq.x()+topder.x())*4/5 ,(topizq.y()+botizq.y())*3/5);
        QLineF dos((topizq.x()+topder.x())/5,(botder.y()+topder.y())*4/5,(botizq.x()+botder.x())*1/5,(topizq.y()+botder.y())*3/5);
        QLineF segunda(topizq.x(),topizq.y(),(topizq.x()+topder.x())/5,(botder.y()+topder.y())*4/5);
        QLineF tercera((topizq.x()+topder.x())/5,botizq.y(),(topizq.x()+topder.x())/5,(topizq.y()+botizq.y())/5);
        QLineF cuarta((topizq.x()+topder.x())/5,(topizq.y()+botizq.y())/5,(topizq.x()+topder.x())*2/5,(topizq.y()+botizq.y())/5);
        QLineF quinta((topizq.x()+topder.x())*3/5,(topizq.y()+botizq.y())*1/5,(topizq.x()+topder.x())*3/5,(topizq.y()+botizq.y())*3/5);
        QLineF sexta((topizq.x()+topder.x())*3/5,(topizq.y()+botizq.y())*1/5,(topizq.x()+topder.x())*4/5,(topizq.y()+botizq.y())*1/5);
        QLineF septima(topder.x(),(topizq.y()+botizq.y())*4/5 ,(botizq.x()+botder.x())*3/5,(topizq.y()+botizq.y())*4/5);
        QLineF octava(topder.x() , (topder.y()+botizq.y())*2/5,(botizq.x()+botder.x())*4/5,(topizq.y()+botizq.y())*2/5);
        QLineF novena(topizq.x(),(topizq.y()+ botizq.y())*2/5,(topizq.x()+topder.x())*2/5,(topizq.y()+botizq.y())*2/5);
        QLineF decima((botizq.x()+botder.x())/5,(botizq.y()+topizq.y())*4/5,(botizq.x()+botder.x()*2/5),(botizq.y()+topizq.y())*4/5);


        scene->addLine(uno,ejes);
        scene->addLine(dos,ejes);
        scene->addLine(segunda,ejes);
        scene->addLine(tercera,ejes);
        scene->addLine(cuarta,ejes);
        scene->addLine(quinta,ejes);
        scene->addLine(sexta,ejes);
        scene->addLine(septima,ejes);
        scene->addLine(octava,ejes);
        scene->addLine(novena,ejes);
        scene->addLine(decima,ejes);


    }
    else{
        //default finalizo juego
    }

    //jugador
    pacman = new PACMAN();
    scene->addItem(pacman);

    //estrellas en la escena
    //int cant =(qrand()% 25+20);
    //for (int i=0;i<cant;i++)
    //{

       // estre = new Estrellas();
      //  scene->addItem(estre);
    //}
    //bola = new circular();
    //scene->addItem(bola);


    //especifico para determinar el instante de tiempo y ejecutar deacuerdo a este.
    timer = new QTimer(this);
    //por cada iteracion tiene en cuanta el tiempo (a medida que avanza)
    connect(timer, SIGNAL(timeout()),scene,SLOT(advance()));
    //Inicializacion del tiempo.
    timer ->start(100);
    timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(agregue_bala()));
    timer2->start(3000);
    timer3=new QTimer();
    connect(timer3,SIGNAL(timeout()),scene,SLOT(advance()));
    timer3->start(40);
}

