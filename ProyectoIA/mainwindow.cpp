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
#include "costouniforme.h"
#include "avara.h"
#include "aasterisco.h"
#include "profundidad.h"


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
        string lvValidaEntorno = lvEntorno.validarEntorno();


        // validaciones básicas del entorno ejemplo: que existan las metas
        if (!(lvValidaEntorno == "")){
             QStringList listadeValidacion= QString::fromStdString(lvValidaEntorno).split("@");

             for(int i=0;i<listadeValidacion.size()-1;i++){
                 QMessageBox::warning(
                         this,
                         tr("Buscando a Nemo 3S"),
                        listadeValidacion.at(i) );
             }
        }else{

            int posI = lvEntorno.getPosInitRobot()[0];
            int posJ = lvEntorno.getPosInitRobot()[1];
            cout << "Posicion Inicial del Robot: (" << posI << "," << posJ << ")" << endl;
            lvEntorno.imprimir();
            this->entornoUI = lvEntorno;
            ui->tablaEntono->setColumnCount(lvEntorno.getAncho());

            pintarEntorno(lvEntorno);

            ui->cmb_clase_busqueda->setEnabled(true);
            ui->cmb_tipo_busqueda->setEnabled(true);
            ui->chk_ind_env_devol->setEnabled(true);
            ui->btn_busqueda->setEnabled(true);
       }
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

    QString lvHtml;
    QString lvTmpSolucion =  QString::fromStdString(*solucion);

    lvHtml = QString::fromStdString("<table><tr><td colspan=2><b>Solución: </b></td></tr>")  +
             QString::fromStdString("<tr><td colspan=2>") + lvTmpSolucion.replace(";","<b> => </b>") + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Nodos creados: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(amplitud.getNodosCreados()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Nodos expandidos: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(amplitud.getNodosExpandidos()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Costo de la Solución: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(amplitud.getCostoSolucion()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Profundidad del arbol: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(amplitud.getProfundidad()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Factor de Ramificación: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(amplitud.getFactorRamificacion()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("</table>");

    ui->txt_resultados->setText("");
    ui->txt_resultados->insertHtml(lvHtml);

    QStringList listadeSolucion = QString::fromStdString(*solucion).split(";");

    queue<QString>  colaSolucion;
    for(int i=0;i<listadeSolucion.size();i++){
        colaSolucion.push(listadeSolucion.at(i));
    }

    pintarSolucion(pentorno, colaSolucion);
}

void MainWindow::busquedaCostoUniforme(Entorno pentorno)
{
    cout << "Busqueda por Costo Uniforme" << endl;

    int posI = pentorno.getPosInitRobot()[0];
    int posJ = pentorno.getPosInitRobot()[1];

    int ** lvAmbiente = new int*[pentorno.getAlto()];
    for(int i=0;i<pentorno.getAlto();i++){
        lvAmbiente[i] = new int[pentorno.getAncho()];
        for(int j=0;j<pentorno.getAncho();j++){
            lvAmbiente[i][j] = pentorno.getAmbiente()[i][j];
        }
    }

    Nodo raiz(posI, posJ, posI, posJ, onRobot, lvAmbiente);

    // Aplica el algoritmo de Bisqueda Preferente por Amplitud
    CostoUniforme costoUniforme(&raiz, pentorno, ui->chk_ind_env_devol->isChecked());
    //queue<string> solucion = amplitud.busquedaPreferente();
    string * solucion;

    solucion = costoUniforme.busquedaUniforme();

    QString lvHtml;
    QString lvTmpSolucion =  QString::fromStdString(*solucion);

    lvHtml = QString::fromStdString("<table><tr><td colspan=2><b>Solución: </b></td></tr>")  +
             QString::fromStdString("<tr><td colspan=2>") + lvTmpSolucion.replace(";","<b> => </b>") + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Nodos creados: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(costoUniforme.getNodosCreados()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Nodos expandidos: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(costoUniforme.getNodosExpandidos()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Costo de la Solución: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(costoUniforme.getCostoSolucion()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Profundidad del arbol: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(costoUniforme.getProfundidad()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Factor de Ramificación: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(costoUniforme.getFactorRamificacion()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("</table>");

    ui->txt_resultados->setText("");
    ui->txt_resultados->insertHtml(lvHtml);

    QStringList listadeSolucion = QString::fromStdString(*solucion).split(";");

    queue<QString>  colaSolucion;
    for(int i=0;i<listadeSolucion.size();i++){
        colaSolucion.push(listadeSolucion.at(i));
    }

    pintarSolucion(pentorno, colaSolucion);
}


void MainWindow::busquedaProfundidad(Entorno pentorno)
{
    cout << "Busqueda por Profundidad" << endl;

    int posI = pentorno.getPosInitRobot()[0];
    int posJ = pentorno.getPosInitRobot()[1];

    int ** lvAmbiente = new int*[pentorno.getAlto()];
    for(int i=0;i<pentorno.getAlto();i++){
        lvAmbiente[i] = new int[pentorno.getAncho()];
        for(int j=0;j<pentorno.getAncho();j++){
            lvAmbiente[i][j] = pentorno.getAmbiente()[i][j];
        }
    }

    Nodo raiz(posI, posJ, posI, posJ, onRobot, lvAmbiente);

    // Aplica el algoritmo de Bisqueda Preferente por Amplitud
    Profundidad profundidad(&raiz, pentorno, ui->chk_ind_env_devol->isChecked());
    string * solucion;

    profundidad.setOperadores('R','L','U','D');
    solucion = profundidad.busquedaProfundidad();

    QString lvHtml;
    QString lvTmpSolucion =  QString::fromStdString(*solucion);

    lvHtml = QString::fromStdString("<table><tr><td colspan=2><b>Solución: </b></td></tr>")  +
             QString::fromStdString("<tr><td colspan=2>") + lvTmpSolucion.replace(";","<b> => </b>") + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Nodos creados: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(profundidad.getNodosCreados()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Nodos expandidos: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(profundidad.getNodosExpandidos()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Costo de la Solución: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(profundidad.getCostoSolucion()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Profundidad del arbol: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(profundidad.getProfundidad()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Factor de Ramificación: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(profundidad.getFactorRamificacion()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("</table>");

    ui->txt_resultados->setText("");
    ui->txt_resultados->insertHtml(lvHtml);

    QStringList listadeSolucion = QString::fromStdString(*solucion).split(";");

    queue<QString>  colaSolucion;
    for(int i=0;i<listadeSolucion.size();i++){
        colaSolucion.push(listadeSolucion.at(i));
    }

    pintarSolucion(pentorno, colaSolucion);
}


void MainWindow::busquedaAvara(Entorno pentorno)
{
    cout << "Busqueda por Costo Uniforme" << endl;

    int posI = pentorno.getPosInitRobot()[0];
    int posJ = pentorno.getPosInitRobot()[1];

    int ** lvAmbiente = new int*[pentorno.getAlto()];
    for(int i=0;i<pentorno.getAlto();i++){
        lvAmbiente[i] = new int[pentorno.getAncho()];
        for(int j=0;j<pentorno.getAncho();j++){
            lvAmbiente[i][j] = pentorno.getAmbiente()[i][j];
        }
    }

    Nodo raiz(posI, posJ, posI, posJ, onRobot, lvAmbiente);

    // Aplica el algoritmo de Bisqueda Preferente por Amplitud
    Avara avara(&raiz, pentorno, ui->chk_ind_env_devol->isChecked());
    //queue<string> solucion = amplitud.busquedaPreferente();
    string * solucion;

    solucion = avara.busquedaAvara();

    QString lvHtml;
    QString lvTmpSolucion =  QString::fromStdString(*solucion);

    lvHtml = QString::fromStdString("<table><tr><td colspan=2><b>Solución: </b></td></tr>")  +
             QString::fromStdString("<tr><td colspan=2>") + lvTmpSolucion.replace(";","<b> => </b>") + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Nodos creados: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(avara.getNodosCreados()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Nodos expandidos: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(avara.getNodosExpandidos()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Costo de la Solución: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(avara.getCostoSolucion()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Profundidad del arbol: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(avara.getProfundidad()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Factor de Ramificación: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(avara.getFactorRamificacion()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("</table>");

    ui->txt_resultados->setText("");
    ui->txt_resultados->insertHtml(lvHtml);

    QStringList listadeSolucion = QString::fromStdString(*solucion).split(";");

    queue<QString>  colaSolucion;
    for(int i=0;i<listadeSolucion.size();i++){
        colaSolucion.push(listadeSolucion.at(i));
    }
}

void MainWindow::busquedaAAsterisco(Entorno pentorno)
{
    cout << "Busqueda por Costo Uniforme" << endl;

    int posI = pentorno.getPosInitRobot()[0];
    int posJ = pentorno.getPosInitRobot()[1];

    int ** lvAmbiente = new int*[pentorno.getAlto()];
    for(int i=0;i<pentorno.getAlto();i++){
        lvAmbiente[i] = new int[pentorno.getAncho()];
        for(int j=0;j<pentorno.getAncho();j++){
            lvAmbiente[i][j] = pentorno.getAmbiente()[i][j];
        }
    }

    Nodo raiz(posI, posJ, posI, posJ, onRobot, lvAmbiente);

    // Aplica el algoritmo de Bisqueda Preferente por Amplitud
    AAsterisco aAsterisco(&raiz, pentorno, ui->chk_ind_env_devol->isChecked());
    //queue<string> solucion = amplitud.busquedaPreferente();
    string * solucion;

    solucion = aAsterisco.busquedaAAsterico();

    QString lvHtml;
    QString lvTmpSolucion =  QString::fromStdString(*solucion);

    lvHtml = QString::fromStdString("<table><tr><td colspan=2><b>Solución: </b></td></tr>")  +
             QString::fromStdString("<tr><td colspan=2>") + lvTmpSolucion.replace(";","<b> => </b>") + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Nodos creados: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(aAsterisco.getNodosCreados()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Nodos expandidos: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(aAsterisco.getNodosExpandidos()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Costo de la Solución: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(aAsterisco.getCostoSolucion()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Profundidad del arbol: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(aAsterisco.getProfundidad()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("<tr><td><b>Factor de Ramificación: </b></td>")  +
             QString::fromStdString("<td>") + QString::number(aAsterisco.getFactorRamificacion()) + QString::fromStdString("</td></tr>") +
             QString::fromStdString("</table>");

    ui->txt_resultados->setText("");
    ui->txt_resultados->insertHtml(lvHtml);

    QStringList listadeSolucion = QString::fromStdString(*solucion).split(";");

    queue<QString>  colaSolucion;
    for(int i=0;i<listadeSolucion.size();i++){
        colaSolucion.push(listadeSolucion.at(i));
    }

    pintarSolucion(pentorno, colaSolucion);
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
        if (ui->cmb_tipo_busqueda->currentIndex() == 1){
            busquedaCostoUniforme(this->entornoUI);
        }
        if (ui->cmb_tipo_busqueda->currentIndex() == 2){
            busquedaProfundidad(this->entornoUI);
        }
    }
    if (ui->cmb_clase_busqueda->currentIndex() == 1){
        if (ui->cmb_tipo_busqueda->currentIndex() == 0){
            busquedaAvara(this->entornoUI);
        }
        if (ui->cmb_tipo_busqueda->currentIndex() == 1){
            busquedaAAsterisco(this->entornoUI);
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
    }
    if (ui->cmb_clase_busqueda->currentIndex() == 1){
       ui->cmb_tipo_busqueda->clear();
       ui->cmb_tipo_busqueda->addItem("Busqueda avara");
       ui->cmb_tipo_busqueda->addItem("Algoritmo A*");
    }

}
