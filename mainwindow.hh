/*
 * COMP.CS.110 Programming 2: Structures, 2022
 * Project4: Snake GUI
 * Program description: Implements a game called Snake.
 * File: mainwindow.hh
 *
 * Description: Declares a class representing the MainWindow UI. In the UI,
 * the user can select to start the game, and edit various settings regarding
 * the gameboard that is generated in the GameWindow class. Settings such as
 * gameboard height and width, gameboard seed and snake speed can be adjusted
 * from the MainWindow UI. The user can also click the quit button to exit
 * the program.
 *
 * Author: Magnus Forsblom, student ID: 150794761, email: magnus.forsblom@tuni.fi
*/

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QCloseEvent>
#include "gamewindow.hh"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // opens the settings window to toggle game settings and start the game
    void on_playButton_clicked();

    // returns from settings menu to main menu
    void on_pushButtonCancelGame_clicked();

    // starts the game (opens GameWindow) with params that are defined in
    // settings menu
    void on_pushButtonStartGame_clicked();

    // quits the game
    void on_pushButtonQuit_clicked();

private:
    Ui::MainWindow *ui;

    //defnie gamewindow (main game window)
    GameWindow *gw = nullptr;

    // handles window close event (window closed by user)
    void closeEvent(QCloseEvent *e);

};
#endif // MAINWINDOW_HH
