#pragma once

#include "ViewBase.h"
#include <iostream>

class ViewComplex : public ViewBase {
    using Board = std::array<std::array<std::optional<Piece>, 3>, 3>;
    [[nodiscard]] char optionalPieceToChar(const std::optional<Piece>& optionalPiece) const override;
    void viewIntroduction() const override;
public:
    void viewBoard(const Board& board) const override;
};

