#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    connect(timer, SIGNAL(timeout()),this, SLOT(refreshGame()));

    connect(ui ->card, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_2, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_3, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_4, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_5, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_6, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_7, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_8, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_9, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_10, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_11, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_12, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_13, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_14, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_15, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_16, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_17, SIGNAL(clicked()),this,SLOT(findedCard()));
    connect(ui ->card_18, SIGNAL(clicked()),this,SLOT(findedCard()));


    startGame();


}

void GameWindow:: setFinalResult(){
    msgBox.setWindowTitle("Game Finished");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);

    if (pairsLeft == 0){
        timer->stop();
        msgBox.setText("You Win, Wanna Play Again?");
        if (QMessageBox::Yes == msgBox.exec()){
            startGame();
        }
        else{
            QCoreApplication::quit();
        }
    }
    else{
        if (time.toString()== "00:00:00"){
            timer ->stop();
            msgBox.setText("You Lost, Wanna try again?");
            if (QMessageBox::Yes == msgBox.exec()){
                startGame();
        }
        else{
            QCoreApplication::quit();
        }

     }
   }
}



void GameWindow::findedCard(){
    tarjetaActual=qobject_cast<QPushButton*> (sender());
    showImage();
    tarjetaActual->setEnabled(false);
    if (!jugadaIniciada){
        tarjetaAnterior = tarjetaActual;
        jugadaIniciada=true;
    }
    else{
        definirResultadoParcial();
        jugadaIniciada=false;
    }

}

void GameWindow::reiniciarTarjetas(){
    //return tiles from current turn to the default state (remove backgrounds)
    tarjetaAnterior->setStyleSheet("#" + tarjetaAnterior->objectName() + "{ background-image: url(:/back_card.png);}");
    tarjetaActual->setStyleSheet("#" + tarjetaActual->objectName() + "{ background-image: url(:/back_card.png);}");

    //re-enable both tiles so they can be used on another turn
    tarjetaActual->setEnabled(true);
    tarjetaAnterior->setEnabled(true);

    //re-enable the whole tile section
    ui->CardsFrame->setEnabled(true);
}


void GameWindow::definirResultadoFinal(){
    msgBox.setWindowTitle("Juego terminado");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setEscapeButton(QMessageBox::No);

    if (pairsLeft==0){
        timer->stop();
        msgBox.setText("¡Ganaste! Puntaje final: " + QString::number(points) + "\nVolver a jugar?");
        if (QMessageBox::Yes == msgBox.exec()){
            startGame();
        }
        else{
            QCoreApplication::quit();
        }
    }
    else{
        if (time.toString()=="00:00:00"){
            timer->stop();
            ui->CardsFrame->setEnabled(false);
            msgBox.setText("Perdiste ;( \n¿Volver a jugar?");
            if (QMessageBox::Yes == msgBox.exec()){
                startGame();
            }
            else{
                QCoreApplication::quit();
            }
        }
    }
}

void GameWindow::definirResultadoParcial(){
    if (setRandomCards[tarjetaActual->objectName()]==setRandomCards[tarjetaAnterior->objectName()]){
        points+=100;
        ui->PointsP1->setText(QString::number(points));
        pairsLeft--;


    }
    else{
        points-=5;
        ui->PointsP1->setText(QString::number(points));

        //disable the whole tile section so no tiles can be turned during the 1-second "memorizing period"
        ui->PointsP1->setEnabled(false);

        //if there is no match, let user memorize tiles and after 1 second hide tiles from current turn so they can be used on another turn
        QTimer::singleShot(1000, this, SLOT(reiniciarTarjetas()));
    }
}



void GameWindow::showImage(){
    QString nombre_tarjeta=tarjetaActual->objectName();
    QString img= setRandomCards[nombre_tarjeta];
    tarjetaActual->setStyleSheet("#" + nombre_tarjeta + "{ background-image: url(://" + img + ") }");

}


void GameWindow::startGame(){
    jugadaIniciada = false;
    points = 0;
    pairsLeft = 9;
    time.setHMS(0,1,0);
    ui->seconds->setText(time.toString("m;ss"));
    timer->start(1000);
    mixVector();
    divideImgs();
    ui->CardsFrame->setEnabled(true);
}








void GameWindow::refreshTimer(){
    time=time.addSecs(-1);
    ui ->seconds->setText(time.toString("m:ss"));
}

void GameWindow::refreshGame(){
    refreshTimer();
    setFinalResult();
}

void GameWindow::mixVector(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(cardsOrder.begin() , cardsOrder.end(), std::default_random_engine(seed));
}

void GameWindow::divideImgs(){
    auto iterador = cardsOrder.begin();
    for (int i=1; i<=9; i++){
        QString file_name = "0"+ QString::number(i)+".png";
        setRandomCards[(*iterador)]= file_name;
        iterador++;
        setRandomCards[(*iterador)]= file_name;
        iterador++;
    }
}



GameWindow::~GameWindow()
{
    delete ui;
}

