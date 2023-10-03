#include <memory>
#include "Controller.h"
#include "Views/ViewSimple.h"
#include "Views/ViewComplex.h"

//TODO: add noexcept's
int main() {
    Controller c {std::make_unique<ViewSimple>()};
    c.init();
}