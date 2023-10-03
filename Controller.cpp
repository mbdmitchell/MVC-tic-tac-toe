#include "Controller.h"

Controller::Controller(std::unique_ptr<ViewBase> v, std::unique_ptr<Model> m)
        : model{std::move(m)}
        , view{std::move(v)} {}

void Controller::invokeUserSelection() const {
    auto selection = view->displayMenuOptions();
    switch (selection) {
        case Model::MenuOptions::PLAY_NEW_GAME:
            startGame();
            break;
        case Model::MenuOptions::QUIT:
            exit(0);
    }
}

void Controller::startGame() const {
    while (model->getGameCondition() == Model::GameCondition::ONGOING) {
        try {
            model->attemptMove(view->getMove());
        }
        catch (const std::exception& e) {
            view->printError(e.what());
        }
        view->viewBoard(model->getBoard());
    }
    view->displayGameResult(model->getGameCondition());
    view->displayEndOfGameMessage();
}

void Controller::loadMenu() const {
    invokeUserSelection();
}

void Controller::init() const {
    view->viewIntroduction();
    loadMenu();
}