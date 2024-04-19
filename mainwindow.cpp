/*
####################################################################
# COMP.CS.110 Programming 2: Structures, 2022
#
# Project4: Snake
# Program description: Implements a game called Snake.
#
# File: mainwindow.cpp
# Description: Defines a class representing the MainWindow UI.
#
# Author: Magnus Forsblom, student ID: 150794761, email: magnus.forsblom@tuni.fi
####################################################################
*/

#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //hide start game frame
    ui->frameStartGame->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// start GameWidnow and play
void MainWindow::on_playButton_clicked()
{
    ui->frameMenu->hide();
    ui->frameStartGame->show();

}

void MainWindow::on_pushButtonCancelGame_clicked()
{
    ui->frameStartGame->hide();
    ui->frameMenu->show();
}


void MainWindow::on_pushButtonStartGame_clicked()
{
    int width = ui->spinBoxWidth->value();
    int height = ui->spinBoxHeight->value();
    int speed = ui->spinBoxSnakeSpeed->value();
    int seed = ui->lineEditSeed->text().toInt();

    // delte old instance
    if (gw != nullptr) {
        delete gw;
    }
    gw = new GameWindow(nullptr, width, height, seed, speed);
    gw->show();
}

void MainWindow::closeEvent (QCloseEvent *e)
{
    // to get rid of compiler error
    if (e) {};

    // delete gamewindow if one exists
    if (gw != nullptr) {
    delete gw;
    }
}

void MainWindow::on_pushButtonQuit_clicked()
{
    QApplication::quit();
}

