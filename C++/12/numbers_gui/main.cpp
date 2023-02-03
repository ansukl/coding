/* Peli2048
 *
 * Kuvaus:
 * Ohjelma toteuttaa 2048-pelin, jossa käyttäjä siirtää eri
 * arvoisia numerolaattoja pelilaudalla valitsemaansa suuntaan. Keskenään
 * samanarvoiset vierekkäiset laatat summataan ja yhdistetään yhdeksi laataksi.
 * Käyttäjä pelaa peliä graafisen käyttöliittymän kautta.
 *
 * Ohjelman kirjoittaja
 * Nimi: Anna Kleemola
 * Opiskelijanumero: K431687
 * Käyttäjätunnus: ak431687
 * E-Mail: anna.kleemola@tuni.fi
 *
 * */

#include "mainwindow.hh"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
