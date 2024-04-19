/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frameMenu;
    QPushButton *playButton;
    QPushButton *pushButtonQuit;
    QFrame *frameStartGame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBoxWidth;
    QSpinBox *spinBoxHeight;
    QLineEdit *lineEditSeed;
    QPushButton *pushButtonStartGame;
    QPushButton *pushButtonCancelGame;
    QLabel *label_4;
    QSpinBox *spinBoxSnakeSpeed;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frameMenu = new QFrame(centralwidget);
        frameMenu->setObjectName("frameMenu");
        frameMenu->setGeometry(QRect(320, 230, 151, 91));
        frameMenu->setFrameShape(QFrame::StyledPanel);
        frameMenu->setFrameShadow(QFrame::Raised);
        playButton = new QPushButton(frameMenu);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(10, 10, 131, 24));
        pushButtonQuit = new QPushButton(frameMenu);
        pushButtonQuit->setObjectName("pushButtonQuit");
        pushButtonQuit->setGeometry(QRect(10, 40, 131, 24));
        frameStartGame = new QFrame(centralwidget);
        frameStartGame->setObjectName("frameStartGame");
        frameStartGame->setGeometry(QRect(200, 150, 391, 251));
        frameStartGame->setFrameShape(QFrame::StyledPanel);
        frameStartGame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frameStartGame);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 171, 20));
        label_2 = new QLabel(frameStartGame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 171, 20));
        label_3 = new QLabel(frameStartGame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 120, 171, 61));
        spinBoxWidth = new QSpinBox(frameStartGame);
        spinBoxWidth->setObjectName("spinBoxWidth");
        spinBoxWidth->setGeometry(QRect(210, 20, 48, 29));
        spinBoxWidth->setMinimum(1);
        spinBoxWidth->setValue(15);
        spinBoxHeight = new QSpinBox(frameStartGame);
        spinBoxHeight->setObjectName("spinBoxHeight");
        spinBoxHeight->setGeometry(QRect(210, 50, 48, 29));
        spinBoxHeight->setMinimum(1);
        spinBoxHeight->setValue(15);
        lineEditSeed = new QLineEdit(frameStartGame);
        lineEditSeed->setObjectName("lineEditSeed");
        lineEditSeed->setGeometry(QRect(180, 140, 131, 28));
        pushButtonStartGame = new QPushButton(frameStartGame);
        pushButtonStartGame->setObjectName("pushButtonStartGame");
        pushButtonStartGame->setGeometry(QRect(290, 210, 83, 29));
        pushButtonCancelGame = new QPushButton(frameStartGame);
        pushButtonCancelGame->setObjectName("pushButtonCancelGame");
        pushButtonCancelGame->setGeometry(QRect(10, 210, 83, 29));
        label_4 = new QLabel(frameStartGame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 80, 171, 51));
        spinBoxSnakeSpeed = new QSpinBox(frameStartGame);
        spinBoxSnakeSpeed->setObjectName("spinBoxSnakeSpeed");
        spinBoxSnakeSpeed->setGeometry(QRect(200, 100, 111, 29));
        spinBoxSnakeSpeed->setMinimum(50);
        spinBoxSnakeSpeed->setMaximum(1000);
        spinBoxSnakeSpeed->setValue(300);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SNAKE GAME: MENU", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        pushButtonQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter gameboard width", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter gameboard height", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Enter seed for game:</p></body></html>", nullptr));
        lineEditSeed->setText(QCoreApplication::translate("MainWindow", "69696969", nullptr));
        pushButtonStartGame->setText(QCoreApplication::translate("MainWindow", "Start!", nullptr));
        pushButtonCancelGame->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Snake speed</p><p>(move 1 step/ms)</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
