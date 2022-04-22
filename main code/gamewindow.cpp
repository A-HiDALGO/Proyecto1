#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "ui_lobby.h"
#include <QThread>
//======================================================================

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    //Create the Cards connections with the functions
    connect(timer, SIGNAL(timeout()),this, SLOT(refreshGame()));
    connect(ui ->card, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_2, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_3, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_4, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_5, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_6, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_7, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_8, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_9, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_10, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_11, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_12, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_13, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_14, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_15, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_16, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_17, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_18, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_19, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_20, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_21, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_22, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_23, SIGNAL(clicked()),this,SLOT(flippedCard()));
    connect(ui ->card_24, SIGNAL(clicked()),this,SLOT(flippedCard()));
    //Create the PowerUps connections with the functions
    connect(ui ->PowerUp1, SIGNAL(clicked()),this,SLOT(DoPowerUp1()));
    connect(ui ->PowerUp2, SIGNAL(clicked()),this,SLOT(DoPowerUp2()));
    connect(ui ->PowerUp3, SIGNAL(clicked()),this,SLOT(DoPowerUp3()));
    connect(ui ->PowerUp1_P2, SIGNAL(clicked()),this,SLOT(DoPowerUp1()));
    connect(ui ->PowerUp2_P2, SIGNAL(clicked()),this,SLOT(DoPowerUp2()));
    connect(ui ->PowerUp3_P2, SIGNAL(clicked()),this,SLOT(DoPowerUp3()));



    startGame();
}
//======================================================================
//Functions to set the nicknames on screen
void GameWindow:: getNick1(QString n1){
    ui->nickPlayer1->setText(QString (n1));
}
void GameWindow:: getNick2(QString n2){
    ui->nickPlayer2->setText(QString (n2));
}

//Function to randomize who play first
void GameWindow:: randomStartPlayer(){
    actualPlayer = (rand()%2);

}

//Function to define the winner
void GameWindow:: winner(){
    if (points1 > points2){
        msgBox.setText("You Win Player 1! Final Score: " + QString::number(points1) + "\nWanna play again?");
    }
    else{
        msgBox.setText("You Win Player 2! Final Score: " + QString::number(points2) + "\nWanna play again?");
    }

}

//Function to End the game
void GameWindow:: setFinalResult(){
    msgBox.setWindowTitle("Game Finished");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    //The Game Finish When There are no pairs left to find
    if (pairsLeft == 0){
        timer->stop();
        winner();
        if (QMessageBox::Yes == msgBox.exec()){
            startGame();
        }
        else{
            QCoreApplication::quit();
        }
    }
    //also the game end when the time's gone
    else{
        if (time.toString()== "00:00:00"){
            timer ->stop();
            winner();
            if (QMessageBox::Yes == msgBox.exec()){
                startGame();
        }
        else{
            QCoreApplication::quit();
        }
     }
   }
}



//Function to restart the Cars Flipped if they're not pairs
void GameWindow::restartCards(){
    PreviousCard->setStyleSheet("#" + PreviousCard->objectName() + "{ background-image: url(:/back_card.png);}");
    ActualCard->setStyleSheet("#" + ActualCard->objectName() + "{ background-image: url(:/back_card.png);}");
    //re-enable both tiles so they can be used on another turn
    ActualCard->setEnabled(true);
    PreviousCard->setEnabled(true);
    //re-enable the whole tile section
    ui->CardsFrame->setEnabled(true);
}

//Function to show on screen the current player turn
void GameWindow :: showCurrentPlayer(){
    if (actualPlayer == 1){
        ui->frameP1->setStyleSheet("background-image: url(:/bgLobby.png);");
        ui->frameP2->setStyleSheet(" ");
    }
    else{    
        ui->frameP2->setStyleSheet("background-image: url(:/bgLobby.png);");
        ui->frameP1->setStyleSheet(" ");
    }
}

//Function to switch player turns
void GameWindow:: changeCurrentPlayer(){
    if (actualPlayer == 1){
        actualPlayer = 2;
        BlockPowerUps();
    }
    else{
        actualPlayer = 1;
        BlockPowerUps();
    }
}

//Function to compare if flipped cards are pair or not
void GameWindow::setPartialResult(){
    if (setRandomCards[ActualCard->objectName()]==setRandomCards[PreviousCard->objectName()]){  // If cards are pair :
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
    else{   // If cards arent pair :
        ui->CardsFrame->setEnabled(false);
        QTimer::singleShot(900, this, SLOT(restartCards()));

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



//Power Ups ====================================
void GameWindow :: reShowPowerUps(){
    ui->PowerUp1->show();
    ui->PowerUp2->show();
    ui->PowerUp3->show();
    ui->PowerUp1_P2->show();
    ui->PowerUp2_P2->show();
    ui->PowerUp3_P2->show();

}
void GameWindow:: BlockPowerUps(){
    if (actualPlayer == 1){
        ui->PowerUp1_P2->setEnabled(false);
        ui->PowerUp2_P2->setEnabled(false);
        ui->PowerUp3_P2->setEnabled(false);
        ui->PowerUp1->setEnabled(true);
        ui->PowerUp2->setEnabled(true);
        ui->PowerUp3->setEnabled(true);
    }
    else{
        ui->PowerUp1->setEnabled(false);
        ui->PowerUp2->setEnabled(false);
        ui->PowerUp3->setEnabled(false);
        ui->PowerUp1_P2->setEnabled(true);
        ui->PowerUp2_P2->setEnabled(true);
        ui->PowerUp3_P2->setEnabled(true);

    }
}

//This powerUp Add 15 seconds on the timer .
void GameWindow:: DoPowerUp1(){
    time=time.addSecs(15);
    if (actualPlayer == 1){
        ui->PowerUp1->hide();
    }
    else{
        ui->PowerUp1_P2->hide();
    }
}

//This powerUp substracts 15 seconds on the timer
void GameWindow:: DoPowerUp2(){
    time=time.addSecs(-15);
    if (actualPlayer == 1){
        ui->PowerUp2->hide();
    }
    else{
        ui->PowerUp2_P2->hide();
    }
}

//This powerUp Add 100 extra points when a player use it
void GameWindow:: DoPowerUp3(){
    if (actualPlayer == 1){
        points1+=100;
        ui->PointsP1->setText(QString::number(points1));
        ui->PowerUp3->hide();

    }
    else{
        points2+=100;
        ui->PointsP2->setText(QString::number(points2));
        ui->PowerUp3_P2->hide();
    }
}

//Function to show the flipped card image on screen
void GameWindow::showImage(){
    QString cardName=ActualCard->objectName();
    QString img= setRandomCards[cardName];
    ActualCard->setStyleSheet("#" + cardName + "{ background-image: url(://" + img + ") }");
}

//Principal Function to Start the Game
void GameWindow::startGame(){
    GameStarted = false;
    randomStartPlayer();
    showCurrentPlayer();
    points1 = 00;
    points2 = 00;
    ui->PointsP1->setText(QString::number(points1));
    ui->PointsP2->setText(QString::number(points2));
    pairsLeft = 12;
    time.setHMS(0,2,00);
    ui->seconds->setText(time.toString("m;ss"));
    timer->start(1000);
    mixVector();
    divideImgs();
    BlockPowerUps();
    reShowPowerUps();
    ui->CardsFrame->setEnabled(true);
    QList<QPushButton *> buttons = ui->CardsFrame->findChildren<QPushButton*>();
    foreach (QPushButton* b, buttons){
        b->setEnabled(true);
        b->setStyleSheet("#" + b->objectName() + "{ background-image: url(:/back_card.png);}");
    }
}

//Fucntion that refresh Timer
void GameWindow::refreshTimer(){
    time=time.addSecs(-1);
    ui ->seconds->setText(time.toString("m:ss"));
}

void GameWindow::refreshGame(){
    refreshTimer();
    setFinalResult();
}

//Function for randomize the cards Vector
void GameWindow::mixVector(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(cardsOrder.begin() , cardsOrder.end(), std::default_random_engine(seed));
}

//This function divide all the images
void GameWindow::divideImgs(){
    auto iterador = cardsOrder.begin();
    for (int i=1; i<=12; i++){
        QString file_name = "0"+ QString::number(i)+".png";
        setRandomCards[(*iterador)]= file_name;
        iterador++;
        setRandomCards[(*iterador)]= file_name;
        iterador++;
    }
}

//Function to set Actual Cards when some player flip a card
void GameWindow::flippedCard(){
    ActualCard=qobject_cast<QPushButton*> (sender());
    showImage();
    ActualCard->setEnabled(false);
    //Set PreviusCard with the first card player flipped to compare it yet
    if (!GameStarted){
        PreviousCard = ActualCard;
        GameStarted=true;
    }
    else{
        setPartialResult();
        GameStarted=false;
    }
}
//======================================================================
GameWindow::~GameWindow()
{
    delete ui;
}
