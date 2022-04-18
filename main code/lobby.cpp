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
    connect(ui ->startGame, SIGNAL(clicked()),this,SLOT(startGame()));
}

Lobby::~Lobby()
{
    delete ui;
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
