#pragma once

#include "Piece.h"

class Player {
    Piece::Type type;
public:
    explicit Player(Piece::Type type);
    [[nodiscard]] Piece::Type getType() const;
    bool operator==(const Player& other) const;
};

