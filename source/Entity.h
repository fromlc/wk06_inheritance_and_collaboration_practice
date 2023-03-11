//------------------------------------------------------------------------------
// Entity : class declaration and definition
//------------------------------------------------------------------------------
#pragma once

#include <cstdlib>      // rand(), srand()
#include <string>
#include <vector>

using std::string;
using std::vector;

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

    virtual string act() = 0;
};

