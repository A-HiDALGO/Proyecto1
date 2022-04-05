/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QFrame *CardsFrame;
    QPushButton *card;
    QPushButton *card_2;
    QPushButton *card_3;
    QPushButton *card_4;
    QPushButton *card_6;
    QPushButton *card_8;
    QPushButton *card_5;
    QPushButton *card_7;
    QPushButton *card_10;
    QPushButton *card_12;
    QPushButton *card_9;
    QPushButton *card_11;
    QPushButton *card_13;
    QPushButton *card_14;
    QPushButton *card_15;
    QPushButton *card_16;
    QPushButton *card_17;
    QPushButton *card_18;
    QFrame *StatusBar;
    QLabel *GameName;
    QLabel *timer;
    QLabel *player1;
    QLabel *player2;
    QLabel *seconds;
    QLabel *PointsPlayer1;
    QLabel *PointsP1;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(1146, 656);
        GameWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/background.jfif);"));
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("color: white\n"
""));
        CardsFrame = new QFrame(centralwidget);
        CardsFrame->setObjectName(QString::fromUtf8("CardsFrame"));
        CardsFrame->setGeometry(QRect(260, 50, 871, 571));
        CardsFrame->setStyleSheet(QString::fromUtf8("color: white\n"
""));
        CardsFrame->setFrameShape(QFrame::StyledPanel);
        CardsFrame->setFrameShadow(QFrame::Raised);
        card = new QPushButton(CardsFrame);
        card->setObjectName(QString::fromUtf8("card"));
        card->setGeometry(QRect(20, 10, 125, 170));
        card->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_2 = new QPushButton(CardsFrame);
        card_2->setObjectName(QString::fromUtf8("card_2"));
        card_2->setGeometry(QRect(160, 10, 125, 170));
        card_2->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_3 = new QPushButton(CardsFrame);
        card_3->setObjectName(QString::fromUtf8("card_3"));
        card_3->setGeometry(QRect(300, 10, 125, 170));
        card_3->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_4 = new QPushButton(CardsFrame);
        card_4->setObjectName(QString::fromUtf8("card_4"));
        card_4->setGeometry(QRect(440, 10, 125, 170));
        card_4->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_6 = new QPushButton(CardsFrame);
        card_6->setObjectName(QString::fromUtf8("card_6"));
        card_6->setGeometry(QRect(160, 190, 125, 170));
        card_6->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_8 = new QPushButton(CardsFrame);
        card_8->setObjectName(QString::fromUtf8("card_8"));
        card_8->setGeometry(QRect(440, 190, 125, 170));
        card_8->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_5 = new QPushButton(CardsFrame);
        card_5->setObjectName(QString::fromUtf8("card_5"));
        card_5->setGeometry(QRect(20, 190, 125, 170));
        card_5->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_7 = new QPushButton(CardsFrame);
        card_7->setObjectName(QString::fromUtf8("card_7"));
        card_7->setGeometry(QRect(300, 190, 125, 170));
        card_7->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_10 = new QPushButton(CardsFrame);
        card_10->setObjectName(QString::fromUtf8("card_10"));
        card_10->setGeometry(QRect(160, 370, 125, 170));
        card_10->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_12 = new QPushButton(CardsFrame);
        card_12->setObjectName(QString::fromUtf8("card_12"));
        card_12->setGeometry(QRect(440, 370, 125, 170));
        card_12->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_9 = new QPushButton(CardsFrame);
        card_9->setObjectName(QString::fromUtf8("card_9"));
        card_9->setGeometry(QRect(20, 370, 125, 170));
        card_9->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_11 = new QPushButton(CardsFrame);
        card_11->setObjectName(QString::fromUtf8("card_11"));
        card_11->setGeometry(QRect(300, 370, 125, 170));
        card_11->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_13 = new QPushButton(CardsFrame);
        card_13->setObjectName(QString::fromUtf8("card_13"));
        card_13->setGeometry(QRect(580, 370, 125, 170));
        card_13->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_14 = new QPushButton(CardsFrame);
        card_14->setObjectName(QString::fromUtf8("card_14"));
        card_14->setGeometry(QRect(580, 10, 125, 170));
        card_14->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_15 = new QPushButton(CardsFrame);
        card_15->setObjectName(QString::fromUtf8("card_15"));
        card_15->setGeometry(QRect(580, 190, 125, 170));
        card_15->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_16 = new QPushButton(CardsFrame);
        card_16->setObjectName(QString::fromUtf8("card_16"));
        card_16->setGeometry(QRect(720, 10, 125, 170));
        card_16->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_17 = new QPushButton(CardsFrame);
        card_17->setObjectName(QString::fromUtf8("card_17"));
        card_17->setGeometry(QRect(720, 190, 125, 170));
        card_17->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        card_18 = new QPushButton(CardsFrame);
        card_18->setObjectName(QString::fromUtf8("card_18"));
        card_18->setGeometry(QRect(720, 370, 125, 170));
        card_18->setStyleSheet(QString::fromUtf8("background-image: url(:/back_card.png);"));
        StatusBar = new QFrame(centralwidget);
        StatusBar->setObjectName(QString::fromUtf8("StatusBar"));
        StatusBar->setGeometry(QRect(20, 50, 231, 571));
        StatusBar->setStyleSheet(QString::fromUtf8("#StatusBar{\n"
"color: white \n"
"}\n"
"\n"
"#PointsP1{\n"
"qproperty-alignment: AlignCenter;\n"
"background: teal;\n"
"border: 3px solid silver;\n"
"border-radius\n"
"}"));
        StatusBar->setFrameShape(QFrame::StyledPanel);
        StatusBar->setFrameShadow(QFrame::Raised);
        GameName = new QLabel(StatusBar);
        GameName->setObjectName(QString::fromUtf8("GameName"));
        GameName->setGeometry(QRect(10, 10, 211, 51));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(false);
        GameName->setFont(font);
        GameName->setAutoFillBackground(false);
        GameName->setStyleSheet(QString::fromUtf8("color: white"));
        GameName->setScaledContents(false);
        timer = new QLabel(StatusBar);
        timer->setObjectName(QString::fromUtf8("timer"));
        timer->setGeometry(QRect(40, 80, 61, 31));
        QFont font1;
        font1.setPointSize(12);
        timer->setFont(font1);
        timer->setStyleSheet(QString::fromUtf8("color: white"));
        player1 = new QLabel(StatusBar);
        player1->setObjectName(QString::fromUtf8("player1"));
        player1->setGeometry(QRect(10, 170, 111, 21));
        player1->setFont(font1);
        player1->setStyleSheet(QString::fromUtf8("color: white"));
        player2 = new QLabel(StatusBar);
        player2->setObjectName(QString::fromUtf8("player2"));
        player2->setGeometry(QRect(10, 370, 111, 21));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        player2->setFont(font2);
        player2->setStyleSheet(QString::fromUtf8("color: white"));
        seconds = new QLabel(StatusBar);
        seconds->setObjectName(QString::fromUtf8("seconds"));
        seconds->setGeometry(QRect(120, 80, 61, 31));
        seconds->setFont(font1);
        seconds->setStyleSheet(QString::fromUtf8("color: white"));
        PointsPlayer1 = new QLabel(StatusBar);
        PointsPlayer1->setObjectName(QString::fromUtf8("PointsPlayer1"));
        PointsPlayer1->setGeometry(QRect(20, 250, 71, 31));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        PointsPlayer1->setFont(font3);
        PointsPlayer1->setStyleSheet(QString::fromUtf8("color: white"));
        PointsP1 = new QLabel(StatusBar);
        PointsP1->setObjectName(QString::fromUtf8("PointsP1"));
        PointsP1->setGeometry(QRect(110, 250, 71, 31));
        PointsP1->setFont(font3);
        GameWindow->setCentralWidget(centralwidget);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "GameWindow", nullptr));
        card->setText(QString());
        card_2->setText(QString());
        card_3->setText(QString());
        card_4->setText(QString());
        card_6->setText(QString());
        card_8->setText(QString());
        card_5->setText(QString());
        card_7->setText(QString());
        card_10->setText(QString());
        card_12->setText(QString());
        card_9->setText(QString());
        card_11->setText(QString());
        card_13->setText(QString());
        card_14->setText(QString());
        card_15->setText(QString());
        card_16->setText(QString());
        card_17->setText(QString());
        card_18->setText(QString());
        GameName->setText(QCoreApplication::translate("GameWindow", "CASINO ROYALE", nullptr));
        timer->setText(QCoreApplication::translate("GameWindow", "TIMER:  ", nullptr));
        player1->setText(QCoreApplication::translate("GameWindow", "Player 1", nullptr));
        player2->setText(QCoreApplication::translate("GameWindow", "Player 2", nullptr));
        seconds->setText(QCoreApplication::translate("GameWindow", "00:00", nullptr));
        PointsPlayer1->setText(QCoreApplication::translate("GameWindow", "Points", nullptr));
        PointsP1->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
