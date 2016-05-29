#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "entorno.h"

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
    void busquedaAmplitud(Entorno pentorno);
    Entorno entornoUI;

private slots:
    void on_btn_sel_entorno_clicked();

    void on_btn_salir_clicked();

    void on_btn_busquda_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
