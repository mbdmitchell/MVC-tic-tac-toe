#include "Model.h"


bool Model::thereExistsARowMatch() const {
    return std::any_of(board.cbegin(), board.cend(), thereExistsARowMatchHelper);
}

void Model::setNextPlayer() { currentPlayer = ((currentPlayer == players[0]) ? players[1] : players[0]); }

bool Model::thereExistsARowMatchHelper(const std::array<std::optional<Piece>, 3> &array) {
    const bool rowHasFreeSpace = std::any_of(array.cbegin(), array.cend(), [](const auto& optPiece) {
        return !optPiece.has_value();
    });

    if (rowHasFreeSpace) return false;

    const Piece& col1Piece = array[0].value();

    return std::all_of(array.cbegin(), array.cend(), [col1Piece](const auto& optPiece) {
        return optPiece.value() == col1Piece;
    });
}

bool Model::thereExistsAColumnMatch() const {
    auto columnMatching = [&](const size_t index) {
        return (board[index][0] == board[index][1] && board[index][1] == board[index][2]);
    };
    for (size_t index = 0; index != board.size(); ++index) {                   // TODO: investigate: != faster for iterator, faster here??
        if (columnMatching(index) && board[index][0].has_value()) {
            return true;
        }
    }
    return false;
}

bool Model::thereExistsADiagonalMatch() const {
    return (board[1][1].has_value()                                            // there's a piece in the middle
            && ((board[0][0] == board[1][1] && board[1][1] == board[2][2])     // top-left to bottom-right diagonal
                || board[0][2] == board[1][1] && board[1][1] == board[2][0])); // bottom-left to top-right diagonal
}

bool Model::isFull() const {
    for (const auto& row : board) {
        for (const auto& optPiece : row) {
            if (!optPiece.has_value()) return false;
        }
    }
    return true;
}

Model::MenuOptions Model::charToMenuOption(const char c) {
    switch (c) {
        case 'Q': return MenuOptions::QUIT;
        case 'P': return MenuOptions::PLAY_NEW_GAME;
        default: throw std::invalid_argument("Invalid character");
    }
}

Model::GameCondition Model::getGameCondition() const {
    if (thereExistsARowMatch() || thereExistsAColumnMatch() || thereExistsADiagonalMatch()) {
        if (getCurrentPlayer().getType() == Piece::Type::X) {
            return GameCondition::WIN_O;
        }
        return GameCondition::WIN_X;
    }
    if (isFull()) {
        return GameCondition::DRAW;
    }
    return GameCondition::ONGOING;
}

void Model::attemptMove(const Model::RowsCols &rowsCols) {
    if (!board[rowsCols.row][rowsCols.col].has_value()) {
        board[rowsCols.row][rowsCols.col] = Piece(currentPlayer.getType());
        setNextPlayer();
    }
    else {
        throw InvalidMove("Square Occupied");
    }
}