/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButtonReset;
    QPushButton *pushButtonPause;
    QLabel *labelNotify;
    QLabel *labelSnakeLenght;
    QLabel *labelTimePassed;
    QLabel *labelGameScore;

    void setupUi(QDialog *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName("GameWindow");
        GameWindow->resize(849, 619);
        GameWindow->setMinimumSize(QSize(849, 619));
        GameWindow->setMaximumSize(QSize(849, 619));
        graphicsView = new QGraphicsView(GameWindow);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(20, 60, 811, 491));
        pushButtonReset = new QPushButton(GameWindow);
        pushButtonReset->setObjectName("pushButtonReset");
        pushButtonReset->setGeometry(QRect(710, 570, 121, 29));
        pushButtonPause = new QPushButton(GameWindow);
        pushButtonPause->setObjectName("pushButtonPause");
        pushButtonPause->setGeometry(QRect(580, 570, 121, 29));
        labelNotify = new QLabel(GameWindow);
        labelNotify->setObjectName("labelNotify");
        labelNotify->setGeometry(QRect(40, 340, 761, 151));
        QFont font;
        font.setPointSize(72);
        labelNotify->setFont(font);
        labelNotify->setAutoFillBackground(true);
        labelSnakeLenght = new QLabel(GameWindow);
        labelSnakeLenght->setObjectName("labelSnakeLenght");
        labelSnakeLenght->setGeometry(QRect(20, 10, 281, 41));
        QFont font1;
        font1.setPointSize(14);
        labelSnakeLenght->setFont(font1);
        labelTimePassed = new QLabel(GameWindow);
        labelTimePassed->setObjectName("labelTimePassed");
        labelTimePassed->setGeometry(QRect(610, 20, 221, 31));
        labelTimePassed->setFont(font1);
        labelGameScore = new QLabel(GameWindow);
        labelGameScore->setObjectName("labelGameScore");
        labelGameScore->setGeometry(QRect(40, 500, 331, 31));
        QFont font2;
        font2.setPointSize(16);
        labelGameScore->setFont(font2);
        labelGameScore->setAutoFillBackground(true);
        graphicsView->raise();
        pushButtonReset->raise();
        pushButtonPause->raise();
        labelNotify->raise();
        labelSnakeLenght->raise();
        labelGameScore->raise();
        labelTimePassed->raise();

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QDialog *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "SNAKE GAME: GAME", nullptr));
        pushButtonReset->setText(QCoreApplication::translate("GameWindow", "Reset game", nullptr));
        pushButtonPause->setText(QCoreApplication::translate("GameWindow", "Pause", nullptr));
        labelNotify->setText(QCoreApplication::translate("GameWindow", "You win!", nullptr));
        labelSnakeLenght->setText(QCoreApplication::translate("GameWindow", "Snake lenght: 1", nullptr));
        labelTimePassed->setText(QCoreApplication::translate("GameWindow", "Time elapsed: 0", nullptr));
        labelGameScore->setText(QCoreApplication::translate("GameWindow", "Game score: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
