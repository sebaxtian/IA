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
#include <QtWidgets/QCheckBox>
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
    QComboBox *cmb_tipo_busqueda;
    QPushButton *btn_busqueda;
    QCheckBox *chk_ind_env_devol;
    QComboBox *cmb_clase_busqueda;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1100, 650);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_sel_entorno = new QPushButton(centralWidget);
        btn_sel_entorno->setObjectName(QStringLiteral("btn_sel_entorno"));
        btn_sel_entorno->setGeometry(QRect(10, 560, 111, 27));
        tablaEntono = new QTableWidget(centralWidget);
        if (tablaEntono->rowCount() < 1)
            tablaEntono->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablaEntono->setVerticalHeaderItem(0, __qtablewidgetitem);
        tablaEntono->setObjectName(QStringLiteral("tablaEntono"));
        tablaEntono->setGeometry(QRect(10, 11, 1081, 541));
        tablaEntono->setLineWidth(0);
        tablaEntono->setMidLineWidth(0);
        tablaEntono->setShowGrid(true);
        tablaEntono->horizontalHeader()->setVisible(false);
        tablaEntono->horizontalHeader()->setCascadingSectionResizes(true);
        tablaEntono->verticalHeader()->setVisible(false);
        btn_salir = new QPushButton(centralWidget);
        btn_salir->setObjectName(QStringLiteral("btn_salir"));
        btn_salir->setGeometry(QRect(851, 559, 112, 27));
        cmb_tipo_busqueda = new QComboBox(centralWidget);
        cmb_tipo_busqueda->setObjectName(QStringLiteral("cmb_tipo_busqueda"));
        cmb_tipo_busqueda->setEnabled(false);
        cmb_tipo_busqueda->setGeometry(QRect(344, 560, 221, 30));
        btn_busqueda = new QPushButton(centralWidget);
        btn_busqueda->setObjectName(QStringLiteral("btn_busqueda"));
        btn_busqueda->setEnabled(false);
        btn_busqueda->setGeometry(QRect(710, 560, 131, 27));
        chk_ind_env_devol = new QCheckBox(centralWidget);
        chk_ind_env_devol->setObjectName(QStringLiteral("chk_ind_env_devol"));
        chk_ind_env_devol->setEnabled(false);
        chk_ind_env_devol->setGeometry(QRect(570, 564, 131, 22));
        chk_ind_env_devol->setChecked(true);
        cmb_clase_busqueda = new QComboBox(centralWidget);
        cmb_clase_busqueda->setObjectName(QStringLiteral("cmb_clase_busqueda"));
        cmb_clase_busqueda->setEnabled(false);
        cmb_clase_busqueda->setGeometry(QRect(130, 560, 211, 33));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1100, 25));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Buscando a Nemo 3", 0));
        btn_sel_entorno->setText(QApplication::translate("MainWindow", "Cargar entorno", 0));
        QTableWidgetItem *___qtablewidgetitem = tablaEntono->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "New Row", 0));
        btn_salir->setText(QApplication::translate("MainWindow", "Salir", 0));
        cmb_tipo_busqueda->clear();
        cmb_tipo_busqueda->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Preferente por amplitud", 0)
         << QApplication::translate("MainWindow", "Costo uniforme", 0)
         << QApplication::translate("MainWindow", "Preferente por profundidad", 0)
         << QApplication::translate("MainWindow", "Limitada por profundidad", 0)
         << QApplication::translate("MainWindow", "Por profundizaci\303\263n iterativa", 0)
        );
        btn_busqueda->setText(QApplication::translate("MainWindow", "Ejecutar busqueda", 0));
        chk_ind_env_devol->setText(QApplication::translate("MainWindow", "Evita devolverse", 0));
        cmb_clase_busqueda->clear();
        cmb_clase_busqueda->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Busqueda no informada", 0)
         << QApplication::translate("MainWindow", "Busqueda informada", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
