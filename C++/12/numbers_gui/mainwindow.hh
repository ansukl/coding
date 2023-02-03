/* Peli2048
 *
 * Tiedoston kuvaus:
 * Mainwindow-luokassa toteutetaan ohjelman graafinen käyttöliittymä.
 *
 * Ohjelman kirjoittaja
 * Nimi: Anna Kleemola
 * Opiskelijanumero: K431687
 * Käyttäjätunnus: ak431687
 * E-Mail: anna.kleemola@tuni.fi
 *
 * */

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>
#include <vector>
#include "gameboard.hh"

const int RECT_SIZE = 100;
const Coords LEFT = {0, -1};
const Coords UP = {-1, 0};
const Coords RIGHT = {0, 1};
const Coords DOWN = {1, 0};
const Coords DEFAULT = {0, 0};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Muuttaa GUI:ssa näkyvää sliderin antamaa arvoa
    void on_seedSlider_valueChanged(int value);
    void on_targetSlider_valueChanged(int value);

    // Toiminnallisuus on nimensä mukaista
    void on_startButton_clicked();
    void on_resetButton_clicked();


private:
    Ui::MainWindow *ui;

    // Tietorakenteet ruuduille ja labeleille
    std::vector<std::vector<QGraphicsRectItem*>> rects_;
    std::vector<std::vector<QLabel*>> labels_;

    QGraphicsScene* board_;
    GameBoard *game_;
    int seed_ = 0;
    int target_ = 2048;
    bool gameEnded_ = true;

    // Päivittää peliruudukkoon numerot ja värit
    void updateBoard();

    // Lukee käyttäjän antaman syötteen
    void keyPressEvent(QKeyEvent* e);

    // Vaihtaa annetun ruudun värin
    void changeTileColor(QGraphicsRectItem* rect, int val);

};
#endif // MAINWINDOW_HH
