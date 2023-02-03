/* Suunnistus
 *
 * Kuvaus:
 * Ohjelma lukee tiedoston, joka sisältää tietoa suunnistuskartan koosta,
 * kartalla olevista rasteista ja reiteistä, jotka koostuvat rasteista.
 * Käyttäjä voi komennoilla tulostaa kartan, reittien nimet, tietyllä reitillä
 * sijaitsevien rastien nimet, kaikkien rastien nimet ja niiden tunnukset ja
 * tietyn reitin pituuden.
 *
 * Ohjelman kirjoittaja
 * Nimi: Anna Kleemola
 * Opiskelijanumero: K431687
 * Käyttäjätunnus: ak431687
 * E-Mail: anna.kleemola@tuni.fi
 *
 * */

#include "orienteeringmap.hh"
#include "parser.hh"
#include "cli.hh"
#include <iostream>

int main()
{
    std::shared_ptr<OrienteeringMap> routes(new OrienteeringMap);
    std::cout << "Input> ";
    std::string input;
    getline(std::cin, input);
    if( not read_input_from_file(input, routes) )
    {
        return EXIT_FAILURE;
    }
    Cli cli(routes);
    while( cli.exec_prompt() ){ }
    return EXIT_SUCCESS;
}


