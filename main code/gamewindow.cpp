#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "ui_lobby.h"
//==============================================================================================================

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    //Buttons connections
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
//Functions to set the nicknames on screen
void GameWindow:: getNick1(QString n1){
    ui->nickPlayer1->setText(QString (n1));

}
void GameWindow:: getNick2(QString n2){
    ui->nickPlayer2->setText(QString (n2));
}
//Function to randomize who starts
void GameWindow:: randomStartPlayer(){
    actualPlayer = (rand()%2);

}


void GameWindow:: winner(){
    if (points1 > points2){
        msgBox.setText("You Win Player 1! Final Score: " + QString::number(points1) + "\nWanna play again?");
    }
    else{
        msgBox.setText("You Win Player 2! Final Score: " + QString::number(points2) + "\nWanna play again?");
    }

}
void GameWindow:: setFinalResult(){
    msgBox.setWindowTitle("Game Finished");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);

    if (pairsLeft == 0){
        timer->stop();
        winner();
        //msgBox.setText("You Win, Wanna Play Again?");
        //msgBox.setText("¡Ganaste! Puntaje final: " + QString::number(points1) + "\nVolver a jugar?");
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
    tarjetaAnterior->setStyleSheet("#" + tarjetaAnterior->objectName() + "{ background-image: url(:/back_card.png);}");
    tarjetaActual->setStyleSheet("#" + tarjetaActual->objectName() + "{ background-image: url(:/back_card.png);}");
    //re-enable both tiles so they can be used on another turn
    tarjetaActual->setEnabled(true);
    tarjetaAnterior->setEnabled(true);
    //re-enable the whole tile section
    ui->CardsFrame->setEnabled(true);
}


void GameWindow :: showCurrentPlayer(){
    if (actualPlayer == 1){
        ui->currentPlayer->setText(QString("Player1 is your turn"));
        ui->frameP1->setStyleSheet("background-image: url(:/bgLobby.png);");
        ui->frameP2->setStyleSheet(" ");
        ui->currentPlayer->setStyleSheet("QLabel{font-size: 18px;font-family: Segoe UI;color: white;font-weight: bold;background-color: rgb(0,0,0);}");
    }
    else{
        ui->currentPlayer->setText(QString("Player2 is your turn"));
        ui->frameP2->setStyleSheet("background-image: url(:/bgLobby.png);");
        ui->frameP1->setStyleSheet(" ");
    }


}
void GameWindow:: changeCurrentPlayer(){
    if (actualPlayer == 1){
        actualPlayer = 2;
    }
    else{
        actualPlayer = 1;
    }

}

void GameWindow::definirResultadoParcial(){
    if (setRandomCards[tarjetaActual->objectName()]==setRandomCards[tarjetaAnterior->objectName()]){
        pairsLeft--;
        ui->CardsFrame->setEnabled(true);
        if (actualPlayer == 1){
            points1+=100;
            ui->PointsP1->setText(QString::number(points1));
        }
        else{
            points2+=100;
            ui->PointsP2->setText(QString::number(points2));
        }
    }
    else{
        ui->CardsFrame->setEnabled(false);
        QTimer::singleShot(900, this, SLOT(reiniciarTarjetas()));

        if (actualPlayer == 1){
            points1-=20;
            ui->PointsP1->setText(QString::number(points1));
            changeCurrentPlayer();
            showCurrentPlayer();
        }
        else{
            points2-=20;
            ui->PointsP2->setText(QString::number(points2));
            changeCurrentPlayer();
            showCurrentPlayer();

        }
    }
}

void GameWindow::showImage(){
    QString nombre_tarjeta=tarjetaActual->objectName();
    QString img= setRandomCards[nombre_tarjeta];
    tarjetaActual->setStyleSheet("#" + nombre_tarjeta + "{ background-image: url(://" + img + ") }");

}

void GameWindow::startGame(){
    jugadaIniciada = false;
    randomStartPlayer();
    showCurrentPlayer();
    points1 = 0;
    points2 = 0;
    ui->PointsP1->setText(QString::number(points1));
    ui->PointsP2->setText(QString::number(points2));
    pairsLeft = 9;
    time.setHMS(0,4,0);
    ui->seconds->setText(time.toString("m;ss"));
    timer->start(1000);
    mixVector();
    divideImgs();
    ui->CardsFrame->setEnabled(true);
    QList<QPushButton *> botones = ui->CardsFrame->findChildren<QPushButton*>();
    foreach (QPushButton* b, botones){
        b->setEnabled(true);
        b->setStyleSheet("#" + b->objectName() + "{ background-image: url(:/back_card.png);}");
    }
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
