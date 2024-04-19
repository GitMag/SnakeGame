/*
####################################################################
# COMP.CS.110 Programming 2: Structures, 2022
#
# Project4: Snake GUI
# Program description: Implements a game called Snake.
#
# File: gamewindow.cpp
# Description: Defines a class representing the gameboard UI.
#
# Author: Magnus Forsblom, student ID: 150794761, email: magnus.forsblom@tuni.fi
####################################################################
*/


#include "gamewindow.hh"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent, int width, int height, int seed, int speed) :
    QDialog(parent),
    ui_(new Ui::GameWindow),
    width_(width),
    height_(height),
    seed_(seed),
    snakeSpeed_(speed)
{
    ui_->setupUi(this);

    //set graphics scene as background for dialog
    scene = new QGraphicsScene(this);
    ui_->graphicsView->setScene(scene);

    //add and connect snake timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(updateGame()));

    //add timer that counts seconds passed
    timerGameTime = new QTimer(this);
    connect(timerGameTime, SIGNAL(timeout()),this, SLOT(updateGameTime()));

    // set outline to be 2px wide
    outlinePen.setWidth(2);

    //init game
    initGame();

}

GameWindow::~GameWindow()
{
    // destructor, cleanup memory
    delete ui_;
    delete board;
    delete scene;
    delete timer;
    delete timerGameTime;
}

void GameWindow::initGame() {

    // hide notification label
    ui_->labelNotify->hide();
    ui_->labelGameScore->hide();
    ui_->pushButtonPause->show();

    // configure board
    if (board != nullptr) {
        delete board;
    }
    board = new GameBoard(width_,height_, seed_);

    // set bg color
    scene->setBackgroundBrush(Qt::white);

    //unpause game
    setPauseStatus(false);

    //start snake timer
    timer->start(snakeSpeed_);

    //start gametimer
    gameTime_ = 0;
    ui_->labelTimePassed->setText("Time passed: " + QString::number(gameTime_));
    timerGameTime->start(1000);
}

void GameWindow::keyPressEvent(QKeyEvent* event) {
    // set snake direction according to keypress
    // dont allow direction to be opposite of current direction
    // (unless snake lenght is 1)
    if (not game_paused_) {
        if (event->key() == Qt::Key_W
                and (snakeLenght_ == 1 or direction_ != "s")) {
            direction_ = "w";
        } else if (event->key() == Qt::Key_S
                   and (snakeLenght_ == 1 or direction_ != "w")) {
            direction_ = "s";
        } else if (event->key() == Qt::Key_D
                   and (snakeLenght_ == 1 or direction_ != "a")) {
            direction_ = "d";
        } else if (event->key() == Qt::Key_A
                   and (snakeLenght_ == 1 or direction_ != "d")) {
            direction_ = "a";
        }
    }
}

void GameWindow::drawSnake() {

    // get snake coords and draw the snake
    std::deque<Point> snake_coords = {};
    snake_coords = board->getSnakeCoords();

    for (auto coord : snake_coords) {
        if (coord == board->getHead()) {
            // draw head
            scene->addRect(coord.get_x() * SNAKE_PIECE_SIZE, coord.get_y()
                           * SNAKE_PIECE_SIZE, SNAKE_PIECE_SIZE,
                             SNAKE_PIECE_SIZE, outlinePen, Qt::red);
        } else if (coord == board->getTail()) {
            // draw tail
            scene->addRect(coord.get_x() * SNAKE_PIECE_SIZE, coord.get_y()
                           * SNAKE_PIECE_SIZE, SNAKE_PIECE_SIZE,
                             SNAKE_PIECE_SIZE, outlinePen, Qt::yellow);
        } else {
            // draw body piece
             scene->addRect(coord.get_x() * SNAKE_PIECE_SIZE, coord.get_y()
                            * SNAKE_PIECE_SIZE, SNAKE_PIECE_SIZE,
                              SNAKE_PIECE_SIZE, outlinePen, Qt::green);
        }
    }
}

void GameWindow::drawFood() {

    // get food coordinates and draw the food
    std::deque<Point> snake_coords = {};
    Point food_coord = board->getFoodCoords();

     scene->addRect(food_coord.get_x() * SNAKE_PIECE_SIZE, food_coord.get_y()
                    * SNAKE_PIECE_SIZE, SNAKE_PIECE_SIZE, SNAKE_PIECE_SIZE,
                      outlinePen, Qt::blue);

}

void GameWindow::drawWalls() {
    int x = -1;
    while (x <= width_) {
        // draw vertical wall if x is 0 or end of width
        if (x == -1 or x == width_) {
            for (int y = -1; y <= height_; ++y) {
                // draw vertical
                scene->addRect(x * SNAKE_PIECE_SIZE, y * SNAKE_PIECE_SIZE, SNAKE_PIECE_SIZE, SNAKE_PIECE_SIZE, outlinePen, Qt::black);
            }
        } else {
            // draw horizontal line
            scene->addRect(x * SNAKE_PIECE_SIZE, -1 * SNAKE_PIECE_SIZE, SNAKE_PIECE_SIZE, SNAKE_PIECE_SIZE, outlinePen, Qt::black);
            scene->addRect(x * SNAKE_PIECE_SIZE, height_ * SNAKE_PIECE_SIZE, SNAKE_PIECE_SIZE, SNAKE_PIECE_SIZE, outlinePen, Qt::black);
        }
        ++x;
    }
}

void GameWindow::postGameActions(bool victory) {
    //stop timer and do other general stuff
    timer->stop();
    timerGameTime->stop();

    if (victory) {
        // display victory message
        ui_->labelNotify->setText("You won!");

        // set victory bg color
        scene->setBackgroundBrush(Qt::green);
    } else {
        ui_->labelNotify->setText("You lost!");

        // set lost bg color
        scene->setBackgroundBrush(Qt::red);
    }

    ui_->pushButtonPause->hide();
    ui_->labelNotify->show();
    ui_->labelGameScore->setText("Game score: " + QString::number(snakeLenght_)
                                 + "/" + QString::number(width_ * height_));
    ui_->labelGameScore->show();
}


void GameWindow::updateGame() {

    //check if game has been won/lost
    if (board->gameWon()) {
        postGameActions(true);
    } else if (board->gameLost()) {
        postGameActions();
    }
    // clear scene
    board->moveSnake(direction_);
    scene->clear();

    // draw walls
    drawWalls();

    // draw snake
    drawSnake();

    //draw food
    drawFood();

    // update snake lenght in ui
   snakeLenght_ = board->getSnakeCoords().size();
   ui_->labelSnakeLenght->setText("Snake lenght: " + QString::number(snakeLenght_));
}

void GameWindow::updateGameTime() {
    gameTime_++;
    ui_->labelTimePassed->setText("Time passed: " + QString::number(gameTime_));
}

void GameWindow::on_pushButtonReset_clicked()
{
    //reset
    initGame();
}

void GameWindow::on_pushButtonPause_clicked()
{
    // pause game
    if (game_paused_) {
        setPauseStatus(false);
    } else {
        setPauseStatus(true);
    }
}

void GameWindow::setPauseStatus(bool setPause) {
    if (setPause) {
        timer->stop();
        timerGameTime->stop();
        game_paused_ = true;
        ui_->pushButtonPause->setText("Resume");
        ui_->labelNotify->setText("Game paused!");
        ui_->labelNotify->show();
    } else {
        timer->start();
        timerGameTime->start();
        game_paused_ = false;
        ui_->pushButtonPause->setText("Pause");
        ui_->labelNotify->hide();
    }
}

