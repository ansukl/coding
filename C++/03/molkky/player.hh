#ifndef PLAYER_HH
#define PLAYER_HH

#include <string>
using namespace std;


class Player
{
public:
    Player();
    // Constructor.
    Player(string name);

    //More methods
    string get_name();
    int get_points();
    void add_points(int pts);
    bool has_won();

private:
    string name_;
    int points_;
};

#endif // PLAYER_HH
