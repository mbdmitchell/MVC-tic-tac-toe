#pragma once

#include <array>
#include <optional>
#include "Piece.h"
#include "../format"
#include "Model.h"
#include <iostream>
#include <iomanip>

class ViewBase {
public:
    using Board = std::array<std::array<std::optional<Piece>, 3>, 3>;
    //struct RowsCols {size_t row; size_t col;};
private:
    [[nodiscard]] static Model::RowsCols readInput();

public:
    virtual void viewBoard(const Board& board) const = 0;
    [[nodiscard]] virtual char optionalPieceToChar(const std::optional<Piece>& optionalPiece) const = 0;
    virtual void viewIntroduction() const = 0;
    [[nodiscard]] static Model::RowsCols getMove();
    static void printError(std::string_view e);
    static void displayGameResult(const Model::GameCondition& gameCondition);
    static void displayEndOfGameMessage();
    static Model::MenuOptions displayMenuOptions();
    virtual ~ViewBase() = default;

};


