#pragma once

class Piece {
public:
    enum class Type {X, O};
    explicit Piece(Type t);
    [[nodiscard]] Type getType() const;
    explicit operator char() const;
    bool operator==(const Piece& other) const;
private:
    Type type;
};

