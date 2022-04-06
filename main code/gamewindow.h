#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QVector>
#include <QHash>
#include <QString>
#include <random>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    QTimer * timer = new QTimer();
    QTime time;
    int pairsLeft;
    QMessageBox msgBox;
    QVector<QString> cardsOrder{"card", "card_2","card_3","card_4",
                           "card_5","card_6","card_7","card_8","card_9",
                           "card_10","card_11","card_12","card_13","card_14","card_15","card_16","card_17","card_18"};

    QHash<QString, QString> setRandomCards;
    int points;
    bool jugadaIniciada;
    QPushButton* tarjetaAnterior;
    QPushButton* tarjetaActual;


public slots:
    void getNick1(QString (n1));
    void getNick2(QString (n2));
private slots:
    void refreshGame();
    void refreshTimer();
    void setFinalResult();
    void startGame();
    void findedCard();
    void mixVector();
    void divideImgs();
    void showImage();
    void definirResultadoParcial();
    void reiniciarTarjetas();
    void definirResultadoFinal();



private:
    Ui::GameWindow *ui;
};
#endif // GAMEWINDOW_H
