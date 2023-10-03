#pragma once

#include "Model.h"
#include "Views/ViewBase.h"
#include "Views/ViewSimple.h"

class Controller {
    std::unique_ptr<Model> model;
    std::unique_ptr<ViewBase> view;
    void invokeUserSelection() const;
    void startGame() const;
    void loadMenu() const;
public:
    explicit Controller(std::unique_ptr<ViewBase> v = std::make_unique<ViewSimple>()
            , std::unique_ptr<Model> m = std::make_unique<Model>());

    void init() const;
};





