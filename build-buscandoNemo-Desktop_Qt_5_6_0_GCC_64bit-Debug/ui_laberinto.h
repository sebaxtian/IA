/********************************************************************************
** Form generated from reading UI file 'laberinto.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABERINTO_H
#define UI_LABERINTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_laberinto
{
public:
    QWidget *centralWidget;
    QTableWidget *tablaLaberinto;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *laberinto)
    {
        if (laberinto->objectName().isEmpty())
            laberinto->setObjectName(QStringLiteral("laberinto"));
        laberinto->resize(589, 466);
        centralWidget = new QWidget(laberinto);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tablaLaberinto = new QTableWidget(centralWidget);
        tablaLaberinto->setObjectName(QStringLiteral("tablaLaberinto"));
        tablaLaberinto->setGeometry(QRect(10, 20, 431, 391));
        tablaLaberinto->setLineWidth(0);
        tablaLaberinto->setMidLineWidth(0);
        tablaLaberinto->setShowGrid(true);
        tablaLaberinto->horizontalHeader()->setVisible(false);
        tablaLaberinto->horizontalHeader()->setCascadingSectionResizes(true);
        tablaLaberinto->verticalHeader()->setVisible(false);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(460, 60, 85, 27));
        laberinto->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(laberinto);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 589, 27));
        laberinto->setMenuBar(menuBar);
        mainToolBar = new QToolBar(laberinto);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        laberinto->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(laberinto);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        laberinto->setStatusBar(statusBar);

        retranslateUi(laberinto);

        QMetaObject::connectSlotsByName(laberinto);
    } // setupUi

    void retranslateUi(QMainWindow *laberinto)
    {
        laberinto->setWindowTitle(QApplication::translate("laberinto", "laberinto", 0));
        pushButton->setText(QApplication::translate("laberinto", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class laberinto: public Ui_laberinto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABERINTO_H
