#include <iostream>
#include <string>
#include "player.hh"

using namespace std;

Player::Player(string name):
    name_(name), points_(0) {
}

string Player::get_name() {
    return name_;
}

int Player::get_points() {
    return points_;
}

void Player::add_points(int pts) {
    if (points_ + pts <= 50) {
        points_ += pts;
    } else {
        points_ = 25;
    }
}

bool Player::has_won() {
    if (points_ == 50) {
       return true;
    } else {
       return false;
    }
}
