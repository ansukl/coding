/* Pelitilasto
 *
 * Kuvaus:
 * Ohjelma toteuttaa pelitilaston, joka sisältää pelin nimen, pelin pelaajien
 * nimet ja pelaajien pelikohtaiset pisteet. Käyttäjä voi komennoilla tulostaa
 * pelitilastosta kaikkien pelien tai pelaajien nimet, yksittäisen pelin
 * pelaajat ja heidän pisteensä ja yksittäisen pelaajan pelaamat pelit.
 * Käyttäjä voi lisäksi lisätä pelitilastoon pelejä, pelaajia ja pelaajien
 * pisteitä ja poistaa pelaajia tilastosta.
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
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Määritellään oma tietotyyppi.
typedef map<string, vector<pair<string, int>>> GameStorage;

// Casual split func, if delim char is between "'s, ignores it.
vector<string> split( const string& str, char delim = ';' )
{
    vector<string> result = {""};
    bool inside_quatation = false;
    for ( auto current_char : str )
    {
        if ( current_char == '"' )
        {
            inside_quatation = not inside_quatation;
        }
        else if ( current_char == delim and not inside_quatation )
        {
            result.push_back("");
        }
        else
        {
            result.back().push_back(current_char);
        }
    }
    if ( result.back() == "" )
    {
        result.pop_back();
    }
    return result;
}


// Lukee käyttäjän nimeämän tiedoston sisällön ja tallentaa sen map-
// tietorakenteeseen. Funktio saa parametreina tiedoston nimen ja
// map-rakenteen, johon pelitilasto tallennetaan, ja palauttaa bool-arvon sen
// mukaan, onnistuiko tiedoston avaus ja lukeminen odotetulla tavalla.
bool readFile(string filename, GameStorage &game_storage)
{
    ifstream file_object(filename);
    if (not file_object) {
        cout << "Error! File could not be read." << endl;
        return false;
    }

    string row = "";

    while (getline(file_object, row)) {

        // Erottelee ja tallentaa tiedoston riviltä tiedot vektoriin.
        vector<string> splitted_row = split(row, ';');

        // Tarkistaa, onko tiedoston rakenne vääränlainen eli ei sisällä kolmea
        // tietokenttää.
        if (splitted_row.size() != 3) {
            cout << "Error: Invalid format in file." << endl;
            return false;
        }

        // Tallennetaan muuttujiin pelin ja pelaajien nimet ja pisteet.
        string game_name = splitted_row.at(0);
        string player_name = splitted_row.at(1);
        int points = stoi(splitted_row.at(2));

        // Alustetaan pair-tietorakenne ja tallennetaan siihen pelaajan nimi ja
        // pisteet.
        pair<string, int> player_points;
        player_points.first = player_name;
        player_points.second = points;

        // Tallennetaan map-rakenteeseen avaimeksi pelin nimi ja arvoksi edellä
        // muodostettu pair.
        if (game_storage.find(game_name) == game_storage.end()) {
            game_storage[game_name];
        }
        game_storage[game_name].push_back(player_points);

    } file_object.close();

    return true;
}


// Tarkistaa, löytyykö annettua pelaajan nimeä vektorista, johon on tallennettu
// map-tietorakenteesta löytyvät pelaajanimet. Funktio saa parametreina
// pelaajien nimet sisältävän vektorin ja pelaajan nimen, ja palauttaa bool-
// arvon, joka kertoo löytyikö nimeä vektorista.
bool playerFound(vector<string> player_names, string playername)
{
    // Iteroidaan pelaajavektori läpi ja etsitään pelaaja.
    for (string &name : player_names) {
        if (name == playername) {
            return true;
        }
    } return false;
}


// Tulostaa tietyn pelin pelaajien nimet ja pisteet pisteiden mukaan nousevassa
// järjestyksessä. Funktio saa parametreina map-rakenteen, johon pelitilasto on
// tallennettu, ja halutun pelin nimen. Funktio ei palauta mitään.
void gameScores(GameStorage game_storage,string gamename)
{
    // Tallennetaan vektorimuuttujaan map-rakenteen arvona olevat pairit.
    vector<pair<string, int>> players_scores = game_storage.at(gamename);

    vector<pair<int, string>> score_first;
    pair<int, string> new_pair;

    // Tehdään uusi pair, johon tallennetaan vanhan pairin tiedot käänteisessä
    // järjestyksessä. Jokainen uusi pair tallennetaan vektoriin.
    for (auto &pair : players_scores) {
        new_pair = make_pair(pair.second, pair.first);
        score_first.push_back(new_pair);
    }

    // Tarkistetaan, onko uusi vektori tyhjä.
    if (score_first.size() == 0) {
        return;
    }

    sort(score_first.begin(), score_first.end());

    // Tulostetaan uuden vektorin sisältö niin, että niiden pelaajien nimet,
    // joilla on samat pisteet, tulostetaan samalle riville pilkulla erotettuna.
    for (unsigned int i = 0; i < score_first.size(); i++) {
        if (i == 0) {
            cout << score_first[i].first << " : " <<
                    score_first[i].second;
        }

        else if (i != 0 && score_first[i-1].first == score_first[i].first) {
            cout << ", " << score_first[i].second;
        }
        else if (i != 0 && score_first[i-1].first != score_first[i].first) {
            cout << endl;
            cout << score_first[i].first << " : " <<
                    score_first[i].second;
        }
    } cout << endl;
}


// Tulostaa nimetyn pelaajan pelaamat pelit aakkosjärjestyksessä
// (ASCII-koodijärjestyksessä). Funktio saa parametreinä map-rakenteen, johon
// pelitilasto on tallennettu, ja pelaajan nimen. Funktio ei palauta mitään.
void playerGames(GameStorage game_storage, string playername)
{
    vector<string> game_names;

    // Jos pelaajan nimi löytyy map-rakenteen sisällä olevasta pairista,
    // kyseisen pairin avain eli pelin nimi tallennetaan vektoriin.
    for (auto &info : game_storage) {
        for (auto &pair : info.second) {
            if (pair.first == playername) {
                game_names.push_back(info.first);
            }
        }
    }

    sort(game_names.begin(), game_names.end());
    for (string &name : game_names) {
        cout << name << endl;
    }
}


// Lisää pelin pelitilastoon. Funktio saa parametreinä map-rakenteen, johon
// pelitilasto on tallennettu, ja lisättävän pelin nimen. Funktio ei palauta
// mitään.
void addGame(GameStorage &game_storage, string gamename)
{
    if (game_storage.find(gamename) == game_storage.end()) {
        game_storage[gamename];
        cout << "Game was added." << endl;
    } else {
        cout << "Error: Already exists." << endl;
    }
}


// Lisää pelaajan pelitilastoon. Funktio saa parametreinä map-rakenteen, johon
// pelitilasto on tallennettu, pelin nimen, johon pelaaja lisätään, lisättävän
// pelaajan nimen ja pelaajan pisteet. Funktio ei palauta mitään.
void addPlayer(GameStorage &game_storage, string gamename,
               string playername, string points)
{
    int num_points = stoi(points);
    pair<string, int> player_points = make_pair(playername, num_points);

    if (game_storage.find(gamename) == game_storage.end()) {
        cout << "Error: Game could not be found." << endl;
    } else {
      bool found = false;

      // Etsitään pelaajan nimeä pelitilastosta ja tallennetaan uudet pisteet,
      // jos nimi löytyy.
      for (auto &infopair : game_storage[gamename]) {
          if (infopair.first == playername) {
              infopair.second = num_points;
              found = true;
              break;
          }
      }

      // Jos pelaajan nimeä ei löytynyt ja bool-muuttujan arvo on edelleen
      // false, lisätään pelaaja ja pisteet pairina map-rakenteeseen.
      if (!found) {
          game_storage[gamename].push_back(player_points);
      }
      cout << "Player was added." << endl;
    }
}


// Poistaa pelaajan pelitilastosta kaikkien pelaajan pelaamien pelien osalta.
// Funktio saa parametreinä  map-rakenteen, johon pelitilasto on tallennettu,
// ja poistettavan pelaajan nimen. Funktio ei palauta mitään.
void removePlayer(GameStorage &game_storage, string playername)
{
    // Iteroidaan pelien tiedot.
    for (auto &info : game_storage) {
        int index = 0;

        // Iteroidaan peliä pelanneiden pelaajien tiedot.
        for (auto &pair : info.second) {
            if (pair.first == playername) {

                // Poistetaan pelaaja tietorakenteesta oikean indeksin kohdalta.
                info.second.erase(info.second.begin()+index);
                break;
            } index++;
        }
    } cout << "Player was removed from all games." << endl;
}


int main()
{
    GameStorage game_storage;

    string filename = "";
    cout << "Give a name for input file: ";
    getline(std::cin, filename);

    if (!readFile(filename, game_storage)) {
        return EXIT_FAILURE;
    }

    // Luodaan vektorimuuttuja, johon tallennetaan pelaajien nimet.
    vector<string> player_names;

    for (auto &info : game_storage) {
        for (auto &pair : info.second) {
            player_names.push_back(pair.first);
        }
    }

    // Järjestetään pelaajien nimet aakkosjärjestykseen ja poistetaan
    // duplikaatit.
    sort(player_names.begin(), player_names.end());
    player_names.erase(unique(player_names.begin(), player_names.end()),
                       player_names.end());

    while (true) {
        string line;
        cout << "games> ";
        getline(cin, line);
        vector<string> parts = split(line, ' ');

        string command = parts.at(0);
        string command_upper = "";

        // Tallennetaan command_upper -muuttujaan käyttäjän antama komento
        // isoilla kirjaimilla.
        for (unsigned int i = 0; i < command.length(); i++) {
            command_upper += toupper(command[i]);
        }

        if (command_upper == "ALL_GAMES") {
            cout << "All games in alphabetical order:" << endl;
            for (auto &info : game_storage) {
                cout << info.first << endl;
            }
        }

        else if (command_upper == "GAME") {

            // Tarkistetaan, onko komennossa ainakin yksi parametri.
            if (parts.size() < 2) {
                cout << "Error: Invalid input." << endl;
                continue;
            }

            // Jos annettua pelin nimeä ei löydy tilastosta, tulostetaan virhe-
            // viesti.
            else if (game_storage.find(parts.at(1)) == game_storage.end()) {
                cout << "Error: Game could not be found." << endl;
                continue;
            }
            cout << "Game " << parts.at(1) << " has these scores and players, "
                    "listed in ascending order:" << endl;
            gameScores(game_storage, parts.at(1));
        }

        else if (command_upper == "ALL_PLAYERS") {
            cout << "All players in alphabetical order:" << endl;

            // Iteroidaan läpi ylempänä luotu vektori pelaajien nimistä.
            for (string &name : player_names) {
                cout << name << endl;
            }
        }

        else if (command_upper == "PLAYER") {

            // Tarkistetaan, onko komennossa ainakin yksi parametri.
            if (parts.size() < 2) {
                cout << "Error: Invalid input." << endl;
                continue;
            }

            // Tarkistetaan, löytyykö pelaajan nimeä vektorista.
            else if (!playerFound(player_names, parts.at(1))){
                cout << "Error: Player could not be found." << endl;
                continue;
            }
            cout << "Player " << parts.at(1) << " playes the following "
                                                "games:" << endl;
            playerGames(game_storage, parts.at(1));
        }

        else if (command_upper == "ADD_GAME") {

            // Tarkistetaan, onko komennossa ainakin yksi parametri.
            if (parts.size() < 2) {
                cout << "Error: Invalid input." << endl;
                continue;
            }
            addGame(game_storage, parts.at(1));
        }

        else if (command_upper == "ADD_PLAYER") {

            // Tarkistetaan, onko komennossa ainakin kolme parametria.
            if (parts.size() < 4) {
                cout << "Error: Invalid input." << endl;
                continue;
            }

            // Tarkistetaan, löytyykö pelin nimeä tilastosta.
            else if (game_storage.find(parts.at(1)) == game_storage.end()) {
                cout << "Error: Game could not be found." << endl;
                continue;
            }

            addPlayer(game_storage, parts.at(1), parts.at(2), parts.at(3));

            // Jos lisättävän pelaajan nimi ei ole vielä pelaajien nimet
            // sisältävässä vektorissa, lisätään se sinne ja järjestetään
            // vektori uudestaan.
            if (!playerFound(player_names, parts.at(2))) {
                player_names.push_back(parts.at(2));
                sort(player_names.begin(), player_names.end());
            }
        }

        else if (command_upper == "REMOVE") {

            // Tarkistetaan, onko komennossa ainakin yksi parametri.
            if (parts.size() < 2) {
                cout << "Error: Invalid input." << endl;
                continue;
            }

            // Tarkistetaan, löytyykö pelaajan nimeä vektorista.
            else if (!playerFound(player_names, parts.at(1))){
                cout << "Error: Player could not be found." << endl;
                continue;
            }

            removePlayer(game_storage, parts.at(1));

            // Poistetaan pelaajan nimi myös pelaajien nimet sisältävästä
            // vektorista.
            int index = 0;
            for (auto &name : player_names) {
                if (name == parts.at(1)) {
                    player_names.erase(player_names.begin()+index);
                } index++;
            }
        }

        else if (command_upper == "QUIT") {
            return EXIT_SUCCESS;
        }

        else {
            cout << "Error: Invalid input." << endl;
            continue;
        }
    }


    return EXIT_SUCCESS;
}
