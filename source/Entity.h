//------------------------------------------------------------------------------
// Entity : class declaration and definition
//------------------------------------------------------------------------------
#pragma once

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int AWARD_POINTS = 10;

//------------------------------------------------------------------------------
// Entity
//------------------------------------------------------------------------------
class Entity {
private:
    int points;

public:
    Entity() : points(0) { }

    int getPoints() const { return points; }
    
    // add passed point value, positive or negative
    void updatePoints(int _points) { points += _points; }

    // more member functions needed...
};

