#include "laberinto.h"
#include "ui_laberinto.h"
#include <QDir>
#include <QDebug>
#include <QTime>
laberinto::laberinto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::laberinto)
{
    ui->setupUi(this);




    QByteArray dirActual;
    dirActual.append(QDir::currentPath());

    QByteArray rutaCompletaATexto;
    rutaCompletaATexto.append(dirActual);
    rutaCompletaATexto.append("/"); //Si usas Windows debes utilizar "\"
    rutaCompletaATexto.append("laberinto.txt");

    QFile file(rutaCompletaATexto);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
      qDebug()<<"No se encuentra el archivo de texto!";
    }else{
        QString todoeltexto;
        //Creamos la variable que contiene todo el archivo.
        todoeltexto.append(file.readAll());//el metodo readAll ejeculalo solo una vez por función.

        qDebug() << "Contenido del Texto: " << todoeltexto;
        //Creamos una variable de Lista partiendo la variable todoeltexto por comas.
        QStringList listadeContenido = todoeltexto.split("\n");

        int lvTamanoTablero = listadeContenido.at(0).toInt();

        //Seteamos la cantidad de columnas segun la cantidades de comas.
        ui->tablaLaberinto->setColumnCount(lvTamanoTablero);
        qDebug()<<"Cantidad de columnas: "<<lvTamanoTablero;
        listadeContenido.removeAt(0);
        listadeContenido.removeLast();
        tamanoTablero = lvTamanoTablero;


        //->setItem(ctr, currCol++, mediaCell);



        //Iniciamos Bucle for
        for(int i=0;i<listadeContenido.size();i++){

            //Insertamos una nueva fila a la tabla
            ui->tablaLaberinto->insertRow(i);

            //Creamos la variable que contiene los datos de una columna.
            QString todaunaColumna;
            //Añadimos a una columna sus datos
            todaunaColumna.append(listadeContenido.at(i));

            //Creamos una variable de Lista partiendo la variable todaunacolumna por el signo |.
            QStringList listadeceldas  = todaunaColumna.split(" ");

            qDebug()<<"Fila Numero "<< i << listadeContenido.at(i);
            for(int j=0;j<listadeceldas.size();j++){
                qDebug()<<"Dato de Fila Numero "<< j << " " << listadeceldas.at(j);

                tablero[i][j]=listadeceldas.at(j).toInt();
            }

        }
        pintarLaberinto();

    }

}

laberinto::~laberinto()
{
    delete ui;
}

void laberinto::on_pushButton_clicked()
{

    // mover recibe un arreglo.
    for(int j=1;j<tamanoTablero-1;j++){
            tablero[0][j]=0;
            tablero[0][j-1]=2;

            ui->tablaLaberinto->item(0,0)->tableWidget()->clear();
            pintarLaberinto();
            QTime dieTime = QTime::currentTime().addSecs(1);
            while (QTime::currentTime() < dieTime)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

       }

}

void laberinto::pintarLaberinto()
{


    QString rutaImagen = "/home/fabian/build-buscandoNemo-Desktop_Qt_5_6_0_GCC_64bit-Debug/";
    for(int i=0;i<tamanoTablero;i++){
        for(int j=0;j<tamanoTablero;j++){
            QTableWidgetItem *mediaCell = new QTableWidgetItem();
            QString rutaTmpImagen;

            if (tablero[i][j] == 0)
            {
                rutaTmpImagen = rutaImagen + "robot.jpg";
            }
            if (tablero[i][j] == 1)
            {
                rutaTmpImagen = rutaImagen + "roca.jpg";
            }
            if (tablero[i][j] == 2)
            {
                rutaTmpImagen = rutaImagen + "blanco.jpg";
            }
            if (tablero[i][j] == 3)
            {
                rutaTmpImagen = rutaImagen + "tiburon.jpg";
            }
            if (tablero[i][j] == 4)
            {
                rutaTmpImagen = rutaImagen + "tortuga.jpg";
            }
            if (tablero[i][j] == 5)
            {
                rutaTmpImagen = rutaImagen + "doli.jpg";
            }
            if (tablero[i][j] == 6)
            {
                rutaTmpImagen = rutaImagen + "marlin.jpg";
            }
            if (tablero[i][j] == 7)
            {
                rutaTmpImagen = rutaImagen + "nemo.jpg";
            }
            if (tablero[i][j] == 8)
            {
                rutaTmpImagen = rutaImagen + "arpon.jpg";
            }
            if (rutaTmpImagen == "")
            {
                rutaTmpImagen = rutaImagen + "blanco.jpg";
            }
             mediaCell->setData(Qt::DecorationRole, QPixmap(rutaTmpImagen).scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));

             ui->tablaLaberinto->setItem(i,j,mediaCell);
             ui->tablaLaberinto->setRowHeight(i,70);
             ui->tablaLaberinto->setColumnWidth(j,70);
        }
    }
}

