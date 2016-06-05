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
    QString lvFileName =  QFileDialog::getOpenFileName(this, tr("Seleccione el entorno"),"../ProyectoIA/Entornos/","Archivo de texto (*.txt)");

    if (lvFileName==""){
        QMessageBox::warning(this,tr("Información"),"Debe seleccionar un archivo. Corrija e intente de nuevo.");
        ui->cmb_clase_busqueda->setEnabled(false);
        ui->cmb_tipo_busqueda->setEnabled(false);
        ui->chk_ind_env_devol->setEnabled(false);
        ui->btn_busqueda->setEnabled(false);
    }
    else
    {
        Entorno lvEntorno;
        lvEntorno.loadFile(lvFileName.toStdString());

        int posI = lvEntorno.getPosInitRobot()[0];
        int posJ = lvEntorno.getPosInitRobot()[1];
        cout << "Posicion Inicial del Robot: (" << posI << "," << posJ << ")" << endl;
        lvEntorno.imprimir();
        this->entornoUI = lvEntorno;
        ui->tablaEntono->setColumnCount(lvEntorno.getAlto());

        pintarEntorno(lvEntorno);

        ui->cmb_clase_busqueda->setEnabled(true);
        ui->cmb_tipo_busqueda->setEnabled(true);
        ui->chk_ind_env_devol->setEnabled(true);
        ui->btn_busqueda->setEnabled(true);
    }
}

void MainWindow::pintarEntorno(Entorno pentorno)
{

    ui->tablaEntono->setRowCount(0);

    QString rutaImagen = "../ProyectoIA/Imagenes/";
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
            //mediaCell->setData(Qt::DecorationRole, QPixmap(rutaTmpImagen).scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            mediaCell->setData(Qt::DecorationRole, QPixmap(rutaTmpImagen));

            ui->tablaEntono->setItem(i,j,mediaCell);
            ui->tablaEntono->setRowHeight(i,70);
            ui->tablaEntono->setColumnWidth(j,70);

        }
    }
    ui->tablaEntono->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    ui->tablaEntono->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

void MainWindow::on_btn_salir_clicked()
{
    MainWindow::close();
}

void MainWindow::busquedaAmplitud(Entorno pentorno)
{
    cout << "Busqueda por Amplitud" << endl;



    int posI = pentorno.getPosInitRobot()[0];
    int posJ = pentorno.getPosInitRobot()[1];

    //Nodo raiz(posI, posJ, 0);
    //NodoFinal raiz(posI, posJ, onRobot, entorno);

    int ** lvAmbiente = new int*[pentorno.getAlto()];
    for(int i=0;i<pentorno.getAlto();i++){
        lvAmbiente[i] = new int[pentorno.getAncho()];
        for(int j=0;j<pentorno.getAncho();j++){
            lvAmbiente[i][j] = pentorno.getAmbiente()[i][j];
        }
    }

    Nodo raiz(posI, posJ, posI, posJ, onRobot, lvAmbiente);


    // Aplica el algoritmo de Bisqueda Preferente por Amplitud
    Amplitud amplitud(&raiz, pentorno, ui->chk_ind_env_devol->isChecked());
    //queue<string> solucion = amplitud.busquedaPreferente();
    string * solucion;

    solucion = amplitud.busquedaPreferente();
    cout << *solucion << endl;
    cout << "Nodos creados: " << amplitud.getNodosCreados() << endl;
    cout << "Nodos expandidos: " << amplitud.getNodosExpandidos() << endl;
    cout << "Costo de la Solucion: " << amplitud.getCostoSolucion() << endl;

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
    int lvEstado_ant = 0;
    while(!pcolaSolucion.empty()) {
        QString  lvCelda = pcolaSolucion.front();
        QStringList listaCelda = lvCelda.split(",");


        int coordI = listaCelda[0].toInt();
        int coordJ = listaCelda[1].toInt();


        lvEstado_ant = pentorno.getAmbiente()[coordI][coordJ];

        //pentorno.ambiente[coordI][coordJ] = 0;
        pentorno.setAmbiente(coordI, coordJ, 0);
        pcolaSolucion.pop();
        pintarEntorno(pentorno);

        if ((lvEstado_ant == 0) || (lvEstado_ant == 2) || (lvEstado_ant == 4) || (lvEstado_ant == 7)) {
            //pentorno.ambiente[coordI][coordJ] = 2;
            pentorno.setAmbiente(coordI, coordJ, 2);
            if (lvEstado_ant == 7){
                pentorno.setIndMetaEncontrada();
            }
        }else{
            if  ((lvEstado_ant == 6) && (pentorno.getIndMetaEncontrada() == 1)) {
                pentorno.setAmbiente(coordI, coordJ, 2);
                pentorno.setIndMetaEncontrada();
            }
            else
            {
                if  ((lvEstado_ant == 5) && (pentorno.getIndMetaEncontrada() == 2)) {
                    pentorno.setAmbiente(coordI, coordJ, 2);
                    pentorno.setIndMetaEncontrada();
                }
                else
                {
                    //pentorno.ambiente[coordI][coordJ] = lvEstado_ant;
                    pentorno.setAmbiente(coordI, coordJ, lvEstado_ant);
                }
            }
        }

        QTime dieTime = QTime::currentTime().addSecs(1);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    }




}

void MainWindow::on_btn_busqueda_clicked()
{
    if (ui->cmb_clase_busqueda->currentIndex() == 0){
        if (ui->cmb_tipo_busqueda->currentIndex() == 0){
            busquedaAmplitud(this->entornoUI);
        }
    }
}


void MainWindow::on_cmb_clase_busqueda_currentIndexChanged(int index)
{
    if (ui->cmb_clase_busqueda->currentIndex() == 0){
       ui->cmb_tipo_busqueda->clear();
       ui->cmb_tipo_busqueda->addItem("Preferente por amplitud");
       ui->cmb_tipo_busqueda->addItem("Costo uniforme");
       ui->cmb_tipo_busqueda->addItem("Preferente por profundidad");
       ui->cmb_tipo_busqueda->addItem("Limitada por profundidad");
       ui->cmb_tipo_busqueda->addItem("Por profundización iterativa");
    }
    if (ui->cmb_clase_busqueda->currentIndex() == 1){
       ui->cmb_tipo_busqueda->clear();
       ui->cmb_tipo_busqueda->addItem("Busqueda avara");
       ui->cmb_tipo_busqueda->addItem("Algoritmo A*");
    }

}
