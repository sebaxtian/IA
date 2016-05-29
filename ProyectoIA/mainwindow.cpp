#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <string>
#include <string.h>
#include <iostream>
#include <QMessageBox>
#include "entorno.h"
#include <QTime>
#include "amplitud.h"
#include "nodo.h"
#include <queue>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_sel_entorno_clicked()
{
 QString lvFileName =  QFileDialog::getOpenFileName(this, tr("Seleccione el entorno"),"/home/fabian/gitHub/IA/ProyectoIA/Entornos/","Archivo de texto (*.txt)");

 if (lvFileName==""){
     QMessageBox::warning(this,tr("Información"),"Debe seleccionar un archivo. Corrija e intente de nuevo.");
 }
 else{
     Entorno lvEntorno;
     lvEntorno.loadFile(lvFileName.toStdString());

     int posI = lvEntorno.getPosInitRobot()[0];
     int posJ = lvEntorno.getPosInitRobot()[1];
     cout << "Posicion Inicial del Robot: (" << posI << "," << posJ << ")" << endl;
        lvEntorno.imprimir();
        this->entornoUI = lvEntorno;
     pintarEntorno(lvEntorno);
 }
}

void MainWindow::pintarEntorno(Entorno pentorno)
{
    for (int i = 0;i<ui->tablaEntono->rowCount();i++){
        ui->tablaEntono->removeRow(i);
    }
    ui->tablaEntono->setColumnCount(pentorno.getAlto());
    QString rutaImagen = "/home/fabian/gitHub/IA/ProyectoIA/Imagenes/";
    for(int i=0;i<pentorno.getAlto();i++){
        ui->tablaEntono->insertRow(i);
        for(int j=0;j<pentorno.getAncho();j++){
            QTableWidgetItem *mediaCell = new QTableWidgetItem();
            QString rutaTmpImagen;

            if (pentorno.getAmbiente()[i][j] == 0)
            {
                rutaTmpImagen = rutaImagen + "robot.jpg";
            }
            if (pentorno.getAmbiente()[i][j] == 1)
            {
                rutaTmpImagen = rutaImagen + "roca.jpg";
            }
            if (pentorno.getAmbiente()[i][j] == 2)
            {
                rutaTmpImagen = rutaImagen + "blanco.jpg";
            }
            if (pentorno.getAmbiente()[i][j] == 3)
            {
                rutaTmpImagen = rutaImagen + "tiburon.jpg";
            }
            if (pentorno.getAmbiente()[i][j] == 4)
            {
                rutaTmpImagen = rutaImagen + "tortuga.jpg";
            }
            if (pentorno.getAmbiente()[i][j] == 5)
            {
                rutaTmpImagen = rutaImagen + "doli.jpg";
            }
            if (pentorno.getAmbiente()[i][j] == 6)
            {
                rutaTmpImagen = rutaImagen + "marlin.jpg";
            }
            if (pentorno.getAmbiente()[i][j] == 7)
            {
                rutaTmpImagen = rutaImagen + "nemo.jpg";
            }
            if (pentorno.getAmbiente()[i][j] == 8)
            {
                rutaTmpImagen = rutaImagen + "arpon.jpg";
            }
            if (rutaTmpImagen == "")
            {
                rutaTmpImagen = rutaImagen + "blanco.jpg";
            }
             mediaCell->setData(Qt::DecorationRole, QPixmap(rutaTmpImagen).scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));

             ui->tablaEntono->setItem(i,j,mediaCell);
             ui->tablaEntono->setRowHeight(i,70);
             ui->tablaEntono->setColumnWidth(j,70);

        }
    }
}

void MainWindow::on_btn_salir_clicked()
{
   MainWindow::close();
}

void MainWindow::on_btn_busquda_clicked()
{
    busquedaAmplitud(this->entornoUI);
}


void MainWindow::busquedaAmplitud(Entorno pentorno)
{
    cout << "Busqueda por Amplitud" << endl;



    int posI = pentorno.getPosInitRobot()[0];
    int posJ = pentorno.getPosInitRobot()[1];

    //Nodo raiz(posI, posJ, 0);
    //NodoFinal raiz(posI, posJ, onRobot, entorno);
    Nodo raiz(posI, posJ, onRobot);


    // Aplica el algoritmo de Bisqueda Preferente por Amplitud
    Amplitud amplitud(&raiz, pentorno);
    //queue<string> solucion = amplitud.busquedaPreferente();
    string * solucion;

    solucion = amplitud.busquedaPreferente();
    cout << *solucion << endl;

    QStringList listadeSolucion = QString::fromStdString(*solucion).split(";");

    queue<QString>  colaSolucion;
    for(int i=0;i<listadeSolucion.size();i++){
       colaSolucion.push(listadeSolucion.at(i));
    }

    pintarSolucion(pentorno, colaSolucion);


    cout << endl;

    cout << endl;
}

void MainWindow::pintarSolucion(Entorno pentorno,queue<QString>  pcolaSolucion )
{
    // mover recibe un arreglo.
 while(!pcolaSolucion.empty()) {
     QString  lvCelda = pcolaSolucion.front();
     QStringList listaCelda = lvCelda.split(",");

     int coordI = listaCelda[0].toInt();
     int coordJ =listaCelda[1].toInt();



     pentorno.setAmbiente(coordI, coordJ, 0);
     pcolaSolucion.pop();
     pintarEntorno(pentorno);
     QTime dieTime = QTime::currentTime().addSecs(1);
     while (QTime::currentTime() < dieTime)
         QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
 }





}

