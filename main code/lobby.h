#ifndef LOBBY_H
#define LOBBY_H

#include <QMainWindow>

namespace Ui {
class Lobby;
}

class Lobby : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lobby(QWidget *parent = nullptr);
    ~Lobby();

private slots:
    void startGame();
    void verifyThenStart();

private:
    Ui::Lobby *ui;
};

#endif // LOBBY_H
