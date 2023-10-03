#pragma once

#include <array>
#include "Player.h"
#include "Piece.h"
#include <optional>
#include "InvalidMove.h"

class Model {
    using Board = std::array<std::array<std::optional<Piece>, 3>, 3>;
    const std::array<Player, 2> players {
            Player{Piece::Type::X},
            Player{Piece::Type::O}
    };

    Player currentPlayer { players[0] };
    Board board;

    void setNextPlayer();
    static bool thereExistsARowMatchHelper(const std::array<std::optional<Piece>, 3>& array);
    [[nodiscard]] bool thereExistsARowMatch() const;
    [[nodiscard]] bool thereExistsAColumnMatch() const;
    [[nodiscard]] bool thereExistsADiagonalMatch() const;
    [[nodiscard]] bool isFull() const;
public:
    enum class MenuOptions {QUIT, PLAY_NEW_GAME};
    static MenuOptions charToMenuOption(char c);
    enum class GameCondition {ONGOING, DRAW, WIN_X, WIN_O};
    struct RowsCols {size_t row; size_t col;};
    [[nodiscard]] Board getBoard() const { return board; }
    [[nodiscard]] Player getCurrentPlayer() const {return currentPlayer; }
    [[nodiscard]] GameCondition getGameCondition() const;
    void attemptMove(const RowsCols& rowsCols);
};


