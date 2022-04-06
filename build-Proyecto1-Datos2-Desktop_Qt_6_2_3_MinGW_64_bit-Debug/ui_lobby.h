/********************************************************************************
** Form generated from reading UI file 'lobby.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOBBY_H
#define UI_LOBBY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lobby
{
public:
    QWidget *centralwidget;
    QPushButton *startGame;
    QLineEdit *nickname1;

    void setupUi(QMainWindow *Lobby)
    {
        if (Lobby->objectName().isEmpty())
            Lobby->setObjectName(QString::fromUtf8("Lobby"));
        Lobby->resize(541, 464);
        centralwidget = new QWidget(Lobby);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        startGame = new QPushButton(centralwidget);
        startGame->setObjectName(QString::fromUtf8("startGame"));
        startGame->setGeometry(QRect(180, 260, 181, 111));
        QFont font;
        font.setPointSize(25);
        startGame->setFont(font);
        nickname1 = new QLineEdit(centralwidget);
        nickname1->setObjectName(QString::fromUtf8("nickname1"));
        nickname1->setGeometry(QRect(180, 210, 181, 24));
        Lobby->setCentralWidget(centralwidget);

        retranslateUi(Lobby);

        QMetaObject::connectSlotsByName(Lobby);
    } // setupUi

    void retranslateUi(QMainWindow *Lobby)
    {
        Lobby->setWindowTitle(QCoreApplication::translate("Lobby", "MainWindow", nullptr));
        startGame->setText(QCoreApplication::translate("Lobby", "PLAY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lobby: public Ui_Lobby {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOBBY_H
