#ifndef LABERINTO_H
#define LABERINTO_H

#include <QMainWindow>

namespace Ui {
class laberinto;
}

class laberinto : public QMainWindow
{
    Q_OBJECT

public:
    explicit laberinto(QWidget *parent = 0);
    ~laberinto();
    int tablero[5][5];
    int tamanoTablero;
    void pintarLaberinto();

private slots:
    void on_pushButton_clicked();

private:
    Ui::laberinto *ui;
};

#endif // LABERINTO_H
