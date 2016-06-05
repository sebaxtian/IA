#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "entorno.h"
#include <queue>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void pintarEntorno(Entorno pentorno);
    void pintarSolucion(Entorno pentorno, queue<QString>  pcolaSolucion );
    void busquedaAmplitud(Entorno pentorno);
    void busquedaCostoUniforme(Entorno pentorno);
    Entorno entornoUI;

private slots:
    void on_btn_sel_entorno_clicked();
    void on_btn_salir_clicked();
    void on_btn_busqueda_clicked();
    void on_cmb_clase_busqueda_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
