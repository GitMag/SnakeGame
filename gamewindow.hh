/*
 * COMP.CS.110 Programming 2: Structures, 2022
 * Project4: Snake GUI
 * Program description: Implements a game called Snake.
 * File: gamewindow.hh
 *
 * Description: Declares a class representing the gameboard UI. In the UI,
 * the snake is drawn at the gameboard. Uses the GameBoard class for the game
 * logic. The snake moves according to user input recieved from WASD keys.
 * The UI also allows the user to pause the game, and resume when ready. When the
 * game is paused. A label is displayed to notify the user about the pause state.
 * It is also possible to reset the gameboard and snake lenght to initial
 * parameters, in order tostart the game over again.
 *
 * When the snake dies (hits a wall or itself), the user is notified and a
 * message is displayed, along with a red window background. If the game is won,
 * the user is also notified, and a green background is displayed.
 *
 * Author: Magnus Forsblom, student ID: 150794761, email: magnus.forsblom@tuni.fi
*/

#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include "gameboard.hh"
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <qtimer.h>
#include <QKeyEvent>

// adjust piece sizes in gameboard UI (pixels)
// e.g 10 means 10x10 squares that represent walls and the snake in the UI.
const int SNAKE_PIECE_SIZE = 20;

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr, int height=5, int width=5, int seed=0, int speed=300);
    ~GameWindow();

    // catch keypresses
    void keyPressEvent(QKeyEvent* event) override;

    //  draws snake piece
    void drawSnake();

    // draws food
    void drawFood();

    //draw walls, only exec on game start
    void drawWalls();

    // initializes the game
    void initGame();

    // exect ui actions after game has been won
    void postGameActions(bool victory=false);

    void setPauseStatus(bool setPaused = true);

private slots:
    // update game for every timer (timer) timeout
    // updates snake movement and draws snake and walls. Also checks game
    // status (won or lost)
    void updateGame();

    // updates how long the player has survived in seconds in the game ui
    void updateGameTime();

    // handles the game pause actions
    void on_pushButtonPause_clicked();

    // resets the gameboard to initial params
    void on_pushButtonReset_clicked();

private:
    // used for ui
    Ui::GameWindow *ui_;

    // for drawing the gameboard
    QGraphicsScene *scene;

    // default gameboard
    GameBoard *board = nullptr;

    // timer for game time (how many seconds has been played)
    QTimer *timer;

    // timer for drawing the gameboard and updating snake movement
    QTimer *timerGameTime;

    // pen used to draw snake outlines
    QPen outlinePen;

    // default direction for snake
    std::string direction_ = "w";

    // variable to store game paused state
    bool game_paused_ = false;

    // configs for gameboard and snake movement
    int width_ = 15;
    int height_ = 15;
    int seed_ = 0;
    int snakeSpeed_ = 300;

    // variables to keep track of game time (survived time in seconds)
    int gameTime_ = 0;

    // variable to track snake lenght
    int snakeLenght_ = 1;
};

#endif // GAMEWINDOW_HH
