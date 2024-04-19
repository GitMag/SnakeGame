/*
####################################################################
# COMP.CS.110 Programming 2: Structures, 2022
#
# Project4: Snake GUI
# Program description: Implements a game called Snake.
#
# File: main.cpp
# Description: Starts the game UI. Read instructions.txt for more information
# about the program.
#
# Author: Magnus Forsblom, student ID: 150794761, email: magnus.forsblom@tuni.fi
####################################################################
*/

#include "mainwindow.hh"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
