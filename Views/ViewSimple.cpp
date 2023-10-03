#include "ViewSimple.h"

char ViewSimple::optionalPieceToChar(const std::optional<Piece> &optionalPiece) const {
    if (!optionalPiece.has_value()) {
        return '.';
    } else {
        return (optionalPiece.value().getType() == Piece::Type::X) ? 'X' : 'O';
    }
}

void ViewSimple::viewIntroduction() const {
    std::cout << "Welcome to Tic-Tac-Toe\n";
    std::cout << std::endl;
}

void ViewSimple::viewBoard(const ViewBase::Board &board) const {
    for (const auto& row : board) {
        for (const auto& piece : row) {
            std::cout << optionalPieceToChar(piece) << ' ';
        }
        std::cout << std::endl;
    }
}