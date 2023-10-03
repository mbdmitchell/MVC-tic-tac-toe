#pragma once

#include "ViewBase.h"
#include <iostream>

class ViewSimple : public ViewBase {
    [[nodiscard]] char optionalPieceToChar(const std::optional<Piece>& optionalPiece) const override;
    void viewIntroduction() const override;
public:
    void viewBoard(const Board& board) const override;
};

