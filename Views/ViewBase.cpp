//
// Created by Max Mitchell on 03/10/2023.
//

#include "ViewBase.h"

Model::RowsCols ViewBase::readInput() {
    size_t rowIndex, columnIndex;
    std::cout << "\nEnter row, then column. Eg. \"0 2\": ";
    std::cin >> rowIndex >> columnIndex;
    return {rowIndex, columnIndex};
}

Model::RowsCols ViewBase::getMove() {
    Model::RowsCols inputLocation = readInput();
    if (!(0 <= inputLocation.row && inputLocation.row <= 2) || !(0 <= inputLocation.col && inputLocation.col <= 2) ) {
        throw std::invalid_argument("Location number must be between 0-2");
    }
    return {inputLocation.row, inputLocation.col};
}

void ViewBase::printError(std::string_view e) {
    std::cout << "Error: " << e << ". (Try again.)" << std::endl;
}

void ViewBase::displayGameResult(const Model::GameCondition &gameCondition, const Player &playerWithCurrentTurn) {
    using namespace std::string_literals;

    switch (gameCondition) {
        case Model::GameCondition::DRAW:
            std::cout << "It's a draw\n";
            break;
        case Model::GameCondition::WIN: {
            const auto winner = (playerWithCurrentTurn.getType() == Piece::Type::O) ? "X"s : "O"s;
            std::cout << std::format("{} Wins!\n", winner);
            break;
        }
        case Model::GameCondition::ONGOING:
            std::cout << "The game is still ongoing\n";
            break;
        default:
            break;
    }
}

void ViewBase::displayEndOfGameMessage() {
    std::cout << "End of Game. Thanks for playing.";
}

Model::MenuOptions ViewBase::displayMenuOptions() {
    char option;
    std::cout << "Type desired option\n"
              << std::quoted("P") << ": Play New Game\n"
              << std::quoted("Q") << ": Quit\n"
              << "-------> ";
    std::cin >> option;
    return Model::charToMenuOption(option);
}
