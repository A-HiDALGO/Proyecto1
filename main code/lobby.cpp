#include "lobby.h"
#include "ui_lobby.h"
#include "gamewindow.h"
#include <QApplication>
#include <QString>
#include "ui_gamewindow.h"
//==============================================================================================
Lobby::Lobby(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lobby)
{
    ui->setupUi(this);
    connect(ui ->startGame, SIGNAL(clicked()),this,SLOT(verifyThenStart()));
}

Lobby::~Lobby()
{
    delete ui;
}

//Function To Verify if both Players type their Nicknames to start to play
void Lobby::verifyThenStart(){
    QString nickP1 = ui->nickname1->text();
    QString nickP2 = ui->nickname2->text();
    if (nickP1 == "" || nickP2 == ""){
        ui->nicksError->setText(QString("Put 2 nicknames to start"));
        ui->nicksError->setStyleSheet("QLabel{font-size: 12px;font-family: Segoe UI;color: white;font-weight: bold;background-color: rgb(0,0,0);}");
    }
    else{
        startGame();
    }
}
void Lobby::startGame(){
    GameWindow *win1 = new GameWindow;
    win1->show();
    this->close();
    QString nickP1 = ui->nickname1->text();
    win1->getNick1(nickP1);
    QString nickP2 = ui->nickname2->text();
    win1->getNick2(nickP2);

}
