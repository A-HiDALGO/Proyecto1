#include "gamewindow.h"
#include "lobby.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lobby window;
    window.show();
    return a.exec();
}
