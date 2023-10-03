#include "Player.h"

Player::Player(Piece::Type type) : type{type} { }

Piece::Type Player::getType() const {return type; }

// TODO: in C++20 isn't this `bool Player::operator==(const Player &other) const = default` or something?
bool Player::operator==(const Player &other) const {
    return type == other.getType();
}