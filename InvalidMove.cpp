#include "InvalidMove.h"

InvalidMove::InvalidMove(std::string_view msg) : msg{msg.data()} {}

const char *InvalidMove::what() const noexcept { return msg.c_str(); }
