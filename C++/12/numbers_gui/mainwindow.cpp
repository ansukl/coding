#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QGraphicsProxyWidget>
#include <cmath>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Luodaan uusi peliruudukko
    board_ = new QGraphicsScene(this);

    this->setStyleSheet("background-color: rgb(255, 255, 204);");

    // Asetetaan luotu peliruudukko halutun kokoisena graafiseen
    // käyttöliittymään
    ui->graphicsView->setScene(board_);
    ui->graphicsView->setFixedSize(RECT_SIZE*SIZE+50, RECT_SIZE*SIZE+50);

    ui->graphicsView->setStyleSheet("background-color: rgb(255, 250, 240);");
    ui->startButton->setStyleSheet("background-color: rgb(153, 255, 153);");
    ui->resetButton->setStyleSheet("background-color: rgb(255, 153, 153);");

    for (int y = 0; y < SIZE; y++) {

        // Luodaan uudet vektorit peliruudukkoon sijoitettaville labeleille ja
        // ruuduille
        std::vector<QLabel*> label_row;
        std::vector<QGraphicsRectItem*> rect_row;

        for (int x = 0; x < SIZE; x++) {
            // Lisätään peliruudukkoon yksi ruutu edellisen ruudun perään
            QGraphicsRectItem *rect = board_->addRect(x*RECT_SIZE, y*RECT_SIZE,
                                                      RECT_SIZE, RECT_SIZE);

            // Luodaan uusi proxy, jonka avulla "kiinnitetään" label tiettyyn
            // ruutuun
            QGraphicsProxyWidget *proxy_widget = new QGraphicsProxyWidget(rect);
            QLabel *label = new QLabel();

            QFont font("Optima", 30);

            label->setFont(font);
            label->setMinimumSize(80, 15);
            label->setAlignment(Qt::AlignCenter);
            label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

            // Tallennetaan labelit ja ruudut omiin vektoreihin tulevaa
            // käsittelyä varten
            label_row.push_back(label);
            rect_row.push_back(rect);

            // Astetaan label ruudun keskelle
            proxy_widget->setWidget(label);
            proxy_widget->setPos(
                        rect->boundingRect().center()-label->rect().center());
        }

        labels_.push_back(label_row);
        rects_.push_back(rect_row);
    }   

    game_ = new GameBoard();
    game_->init_empty();

    // Asetetaan Reset-nappi pois päältä, jotta sitä ei voi klikata ennen pelin
    // alkua
    ui->resetButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game_;
}


void MainWindow::on_seedSlider_valueChanged(int value)
{
    // Tallennetaan käyttäjän antama siemenarvo ja asetetaan se GUI:ssa näkyviin
    seed_ = value;
    ui->seedValueLabel->setNum(seed_);
}


void MainWindow::on_targetSlider_valueChanged(int value)
{
    // Tallennetaan käyttäjän antama kahden potenssi ja asetetaan laskettu arvo
    // GUI:ssa näkyviin
    target_ = std::pow(2, value);
    ui->targetValueLabel->setNum(target_);
}


void MainWindow::on_startButton_clicked()
{
    // Asetetaan bool-muuttujaan tieto siitä, että peli on käynnissä
    gameEnded_ = false;

    // Asetetaan slidereita/nappeja pois päältä tai päälle, jotta niitä ei voi
    // käyttää väärässä kohtaa peliä
    ui->seedSlider->setDisabled(true);
    ui->targetSlider->setDisabled(true);
    ui->startButton->setDisabled(true);
    ui->resetButton->setEnabled(true);

    game_->fill(seed_);

    // Asetetaan luvut näkyville peliruudukkoon
    updateBoard();
}

void MainWindow::on_resetButton_clicked()
{
    // Asetetaan bool-muuttujaan tieto siitä, että peli loppui
    gameEnded_ = true;

    // Resetoidaan käyttöliittymän taustaväri varmuuden vuoksi, jos edellinen
    // peli on voitettu tai hävitty
    this->setStyleSheet("background-color: rgb(255, 255, 204);");

    // Poistetaan kaikki numerot ja värit peliruudukosta ja resetoidaan pelin
    // sisäinen tietorakenne
    game_->reset_tiles();
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            labels_.at(y).at(x)->clear();
            changeTileColor(rects_.at(y).at(x), 0);
        }
    }

    // Asetetaan slidereita/nappeja pois päältä tai päälle, jotta niitä ei voi
    // käyttää väärässä kohtaa peliä
    ui->seedSlider->setEnabled(true);
    ui->targetSlider->setEnabled(true);
    ui->startButton->setEnabled(true);
    ui->resetButton->setDisabled(true);

    // Tyhjennetään mahdollinen ilmoitus voitosta/häviöstä
    ui->outcomeLabel->clear();

    // Asetetaan tavoiteluku-slider oletusarvoon 2048 (2^11)
    ui->targetSlider->setValue(11);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    //Tarkistetaan ennen näppäinkomentojen lukemista, onko peli käynnissä
    if (gameEnded_) {
        return;
    }

    Coords dir = DEFAULT;

    // Tallennetaan dir-muuttujaan käyttäjän näppäimistöllä valitsema suunta
    if (event->key() == Qt::Key_W) {
        dir = UP;
    }
    else if (event->key() == Qt::Key_S) {
        dir = DOWN;
    }
    else if (event->key() == Qt::Key_A) {
        dir = LEFT;
    }
    else if (event->key() == Qt::Key_D) {
        dir = RIGHT;
    }

    // Jos käyttäjä on painanut WASD, siirretään numerolaattoja peliruudukossa
    if (dir != DEFAULT) {
        bool has_won = game_->move(dir, target_);

        if (has_won) {
            this->setStyleSheet("background-color: rgb(204, 255, 204);");
            ui->outcomeLabel->setText("You won!");
            gameEnded_ = true;
        }

        // Tarkistetaan, onko peliruudukko täynnä (häviö)
        else if (game_->is_full()) {
            this->setStyleSheet("background-color: rgb(255, 204, 204);");
            ui->outcomeLabel->setText("You lost!");
            gameEnded_ = true;
        }

        // Lisätään peliruudukkoon uusi numero, jos peli ei ole päättynyt
        if (!gameEnded_) {
            game_->new_value();
        }

        updateBoard();
    }
}

void MainWindow::updateBoard()
{
    // Käydään läpi jokainen ruutu ja asetetaan GUI:ssa näkyviin sisäisestä
    // tietorakenteesta saatu numero ja numeroa vastaava väri
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            Coords yx = std::make_pair(y, x);
            int val = game_->get_value(yx);

            // Piilotetaan label, jos sen arvo on 0
            if (val == 0) {
                labels_.at(y).at(x)->hide();
            } else {
                labels_.at(y).at(x)->show();
            }

            changeTileColor(rects_.at(y).at(x), val);
            labels_.at(y).at(x)->setNum(val);
        }
    }
}

void MainWindow::changeTileColor(QGraphicsRectItem *rect, int val)
{
    QBrush colorBrush;

    // Määritellään eri numeroarvoja vastaavat värit
    switch(val) {
        case 0: colorBrush = Qt::transparent; break;
        case 2: colorBrush = QBrush(QColor(245,245,220)); break;
        case 4: colorBrush = QBrush(QColor(255,250,205)); break;
        case 8: colorBrush = QBrush(QColor(255,235,205)); break;
        case 16: colorBrush = QBrush(QColor(255,222,173)); break;
        case 32: colorBrush = QBrush(QColor(255,160,122)); break;
        case 64: colorBrush = QBrush(QColor(255,140,0)); break;
        case 128: colorBrush = QBrush(QColor(240,128,128)); break;
        case 256: colorBrush = QBrush(QColor(250,128,114)); break;
        case 512: colorBrush = QBrush(QColor(255,127,80)); break;
        case 1024: colorBrush = QBrush(QColor(255,99,71)); break;
        case 2048: colorBrush = QBrush(QColor(255,215,0)); break;
        default: colorBrush = QBrush(QColor(255,69,0));
    }

    // Asetetaan ruudun väri
    rect->setBrush(colorBrush);
}
