/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_sel_entorno;
    QTableWidget *tablaEntono;
    QPushButton *btn_salir;
    QComboBox *comboBox;
    QPushButton *btn_busquda;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(925, 459);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_sel_entorno = new QPushButton(centralWidget);
        btn_sel_entorno->setObjectName(QStringLiteral("btn_sel_entorno"));
        btn_sel_entorno->setGeometry(QRect(810, 10, 111, 27));
        tablaEntono = new QTableWidget(centralWidget);
        if (tablaEntono->columnCount() < 1)
            tablaEntono->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablaEntono->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tablaEntono->rowCount() < 1)
            tablaEntono->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablaEntono->setVerticalHeaderItem(0, __qtablewidgetitem1);
        tablaEntono->setObjectName(QStringLiteral("tablaEntono"));
        tablaEntono->setGeometry(QRect(20, 10, 671, 391));
        tablaEntono->setLineWidth(0);
        tablaEntono->setMidLineWidth(0);
        tablaEntono->setShowGrid(true);
        tablaEntono->horizontalHeader()->setVisible(false);
        tablaEntono->horizontalHeader()->setCascadingSectionResizes(true);
        tablaEntono->verticalHeader()->setVisible(false);
        btn_salir = new QPushButton(centralWidget);
        btn_salir->setObjectName(QStringLiteral("btn_salir"));
        btn_salir->setGeometry(QRect(810, 150, 112, 27));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(700, 40, 221, 33));
        btn_busquda = new QPushButton(centralWidget);
        btn_busquda->setObjectName(QStringLiteral("btn_busquda"));
        btn_busquda->setGeometry(QRect(790, 90, 131, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 925, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btn_sel_entorno->setText(QApplication::translate("MainWindow", "Cargar entorno", 0));
        QTableWidgetItem *___qtablewidgetitem = tablaEntono->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "New Column", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tablaEntono->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "New Row", 0));
        btn_salir->setText(QApplication::translate("MainWindow", "Salir", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Busqueda por amplitud", 0)
         << QApplication::translate("MainWindow", "Busqueda por costo uniforme", 0)
        );
        btn_busquda->setText(QApplication::translate("MainWindow", "Ejecutar busqueda", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
