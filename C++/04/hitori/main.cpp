/* Hitori
 *
 * Kuvaus:
 *   Ohjelma toteuttaa Hitori-pelin. Pelissä on peliruudukko kooltaan
 * 5 x 5. Kukin ruutu sisältää jonkin numeroista 1-5. Vaaka- ja
 * pystyriveillä voi aluksi olla useita samoja numeroita, mutta
 * tarkoituksena on poistaa numeroita niin, että kullakin vaaka- ja
 * pystyrivillä on kutakin numeroa vain yksi tai ei yhtään. Kuitenkaan
 * vierekkäisten ruutujen numeroita ei saa poistaa, eikä mikään jäljelle
 * jäävä numero (ruutu) saa jäädä irralleen muista, eli sen ympäriltä
 * (yläpuolelta, alapuolelta, vasemmalta, oikealta) ei saa poistaa
 * kaikkia numeroita.
 *   Aluksi käyttäjältä kysytään, täytetäänkö peliruudukko satunnaisesti
 * arvottavilla luvuilla 1-5 vai käyttäjän valitsemilla 25 luvulla.
 * Ensimmäisessä vaihtoehdossa käyttäjältä kysytään satunnaisluku-
 * generaattorin siemenlukua ja jälkimmäisessä häntä pyydetään syöttämään
 * 25 lukua.
 *   Joka kierroksella käyttäjältä kysytään poistettavan numeron
 * koordinaatteja eli kahta lukua. Peli päättyy pelaajan voittoon,
 * jos peliruudukon kaikilla vaaka- ja pystyriveillä esiintyy kukin
 * numero 1-5 korkeintaan kerran. Peli päättyy pelaajan häviöön,
 * jos hän poistaa jo poistetun numeron viereisen numeron tai jos
 * jokin numero jää irralleen muista.
 *   Ohjelma tarkistaa annetut koordinaatit. Koordinaattien pitää olla
 * peliruudukon sisällä, ja niiden osoittaman ruudun pitää sisältää
 * numero, eli jo poistettua numeroa ei voi poistaa toiseen kertaan.
 *   Pelin päättyessä kerrotaan, voittiko vai hävisikö pelaaja.
 *
 * Ohjelman kirjoittaja
 * Nimi: Anna Kleemola
 * Opiskelijanumero: K431687
 * Käyttäjätunnus: ak431687
 * E-Mail: anna.kleemola@tuni.fi
 *
 *
 * */


#include <iostream>
#include <vector>
#include <cctype>
#include <random>

using namespace std;

const unsigned int BOARD_SIDE = 5;
const unsigned char EMPTY = ' ';

// Muuttaa annetun numeerisen merkkijonon vastaavaksi kokonaisluvuksi
// (kutsumalla stoi-funktiota).
// Jos annettu merkkijono ei ole numeerinen, palauttaa nollan.
//
// Converts the given numeric string to the corresponding integer
// (by calling stoi).
// If the given string is not numeric, returns zero.
unsigned int stoiWithCheck(const string& str) {
    bool is_numeric = true;
    for(unsigned int i = 0; i < str.length(); ++i)
    {
        if(not isdigit(str.at(i)))
        {
            is_numeric = false;
            break;
        }
    }
    if(is_numeric)
    {
        return stoi(str);
    }
    else
    {
        return 0;
    }
}

// Tulostaa pelilaudan rivi- ja sarakenumeroineen.
//
// Prints the game board with row and column numbers.
void print(const vector<vector<int>>& gameboard) {
    cout << "=================" << endl;
    cout << "|   | 1 2 3 4 5 |" << endl;
    cout << "-----------------" << endl;
    for(unsigned int i = 0; i < BOARD_SIDE; ++i)
    {
        cout << "| " << i + 1 << " | ";
        for(unsigned int j = 0; j < BOARD_SIDE; ++j)
        {
            if(gameboard.at(i).at(j) == 0)
            {
                cout << EMPTY << " ";
            }
            else
            {
                cout << gameboard.at(i).at(j) << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << "=================" << endl;
}

// Tarkistaa, onko pelilaudalta annetun ruudun ympärillä tyhjiä ruutuja.
bool hasEmptyAround(vector<vector<int>>& gameboard,
        unsigned int x,
        unsigned int y) {

    bool empty_around = true;

    // Tarkistetaan yläpuolella oleva ruutu, jos sellainen on olemassa.
    if (y != 0 && gameboard.at(y-1).at(x) != 0) {
        empty_around = false;
    }

    // Tarkistetaan oikealla oleva ruutu, jos sellainen on olemassa.
    if (x != BOARD_SIDE-1 && gameboard.at(y).at(x+1) != 0) {
        empty_around = false;
    }

    // Tarkistetaan vasemmalla oleva ruutu, jos sellainen on olemassa.
    if (x != 0 && gameboard.at(y).at(x-1) != 0) {
        empty_around = false;
    }

    // Tarkistetaan alapuolella oleva ruutu, jos sellainen on olemassa.
    if (y != BOARD_SIDE-1 && gameboard.at(y+1).at(x) != 0) {
        empty_around = false;
    }

    return empty_around;
}

// Tarkistaa, hävisikö pelaaja pelin.
bool hasLost(vector<vector<int>>& gameboard) {
    for (unsigned int y = 0; y < BOARD_SIDE; ++y) {
        for (unsigned int x = 0; x < BOARD_SIDE; ++x) {

            // Tarkistaa, onko tyhjän ruudun vieressä toista tyhjää ruutua.
            if (gameboard.at(y).at(x) == 0) {
                if (x+1 < BOARD_SIDE && gameboard.at(y).at(x+1) == 0) {
                    return true;
                } else if (y+1 < BOARD_SIDE && gameboard.at(y+1).at(x) == 0) {
                    return true;
                }
            } else {
                if (hasEmptyAround(gameboard, x, y)) {
                    return true;
                }
            }
        }
    } return false;
}

// Tarkistaa, voittiko pelaaja pelin.
bool hasWon(vector<vector<int>>& gameboard) {
    for (unsigned int y = 0; y < BOARD_SIDE; ++y) {
        for (unsigned int x = 0; x < BOARD_SIDE; ++x) {

            // Tarkistaa, onko samalla rivillä samoja lukuja.
            for (unsigned int z = x+1; z < BOARD_SIDE; ++z) {
                if (gameboard.at(y).at(z) == 0) {
                    continue;
                } else if (gameboard.at(y).at(z) == gameboard.at(y).at(x)) {
                    return false;
                }
            }

            // Tarkistaa, onko samalla kolumnilla samoja lukuja.
            for (unsigned int z = y+1; z < BOARD_SIDE; ++z) {
                if (gameboard.at(z).at(x) == 0) {
                    continue;
                } else if (gameboard.at(z).at(x) == gameboard.at(y).at(x)) {
                    return false;
                }
            }
        }
    } return true;
}

// Käynnistää pelin ja lopettaa sen, kun pelaaja häviää tai voittaa.
void runGame(vector<vector<int>>& gameboard) {
    string x_axis, y_axis;

    while (true) {
        cout << "Enter removable element (x, y): ";
        cin >> x_axis;

        if (x_axis == "q") {
            cout << "Quitting" << endl;
            break;
        }

        cin >> y_axis;

        unsigned int num_x = stoiWithCheck(x_axis);
        unsigned int num_y = stoiWithCheck(y_axis);

        // Tarkistetaan, löytyykö koordinaatteja pelilaudalta.
        if ((num_x < 1 || num_x > 5) || (num_y < 1 || num_y > 5)) {
            cout << "Out of board" << endl;
        } else if (gameboard.at(num_y - 1).at(num_x - 1) == 0) {
            cout << "Already removed" << endl;
        }

        // Kun koordinaatit löytyvät laudalta, ruutu tyhjennetään.
        else {
            gameboard.at(num_y - 1).at(num_x - 1) = 0;
            print(gameboard);

            if (hasLost(gameboard)) {
                cout << "You lost" << endl;
                break;
            } else if (hasWon(gameboard)) {
                cout << "You won" << endl;
                break;
            }
        }
    }
}

// Jäsentelee käyttäjän antaman merkkijonon numerovektoriksi ja palauttaa sen.
vector<int> splitInput(string& line) {
    vector<int> splitted = {};
    string::size_type i = 0;
    string part = "";

    // Käydään merkkijono merkki kerrallaan läpi.
    while (i < line.length()) {
        char c = line.at(i);

        if (c != EMPTY) {
            part += c;
        } else {
            splitted.push_back(stoiWithCheck(part));
            part = "";
        }
       i++;
    }

    splitted.push_back(stoiWithCheck(part));
    return splitted;
}

// Generoi pelilaudan käyttäjän syötteen pohjalta.
void userBoard(vector<vector<int>>& gameboard, string& input_line) {
    vector<int> input_nums = splitInput(input_line);
    int index = 0;

    for (unsigned int y = 0; y < BOARD_SIDE; ++y) {
        vector<int> row;

        for (unsigned int x = 0; x < BOARD_SIDE; ++x) {
            row.push_back(input_nums.at(index));
            index++;
        } gameboard.push_back(row);
    }
}

// Generoi pelilaudan randomoitujen numeroiden pohjalta.
void randomBoard(vector<vector<int>>& gameboard, default_random_engine& gen) {
    uniform_int_distribution<int> distr(1, 5);

    for (unsigned int y = 0; y < BOARD_SIDE; ++y) {
        vector<int> row;

        for (unsigned int x = 0; x < BOARD_SIDE; ++x) {
            unsigned int random_num = distr(gen);
            row.push_back(random_num);
        } gameboard.push_back(row);
    }
}

// Alustaa pelilaudan pelaajan syötteen mukaisesti.
void initBoard(vector<vector<int>>& gameboard) {
    string start = "";
    default_random_engine gen;

    while (true) {
        cout << "Select start (R for random, I for input): ";
        getline(cin, start);

        if (start == "r" || start == "R") {
            cout << "Enter seed value: ";
            unsigned int seed_value;
            cin >> seed_value;

            randomBoard(gameboard, gen);
            break;

        } else if (start == "i" || start == "I") {
            string input_line = "";
            cout << "Input: ";
            getline(cin, input_line);

            userBoard(gameboard, input_line);
            break;
        }
    }
}

int main() {
    vector<vector<int>> gameboard;

    initBoard(gameboard);
    print(gameboard);
    runGame(gameboard);
}
