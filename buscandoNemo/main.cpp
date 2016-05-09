#include "laberinto.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    laberinto w;
    w.show();

    return a.exec();


}
