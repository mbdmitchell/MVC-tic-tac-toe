#include "Piece.h"

Piece::Piece(Piece::Type t) : type{t} {}

Piece::Type Piece::getType() const {return type; }

Piece::operator char() const { return (type == Type::X) ? 'X' : 'O'; }

// TODO: in C++20 isn't this `bool Piece::operator==(const Piece &other) const = default` or something?
bool Piece::operator==(const Piece &other) const { return type == other.getType(); }

