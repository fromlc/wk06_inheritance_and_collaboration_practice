//------------------------------------------------------------------------------
// Player : class declaration and definition
//------------------------------------------------------------------------------
#pragma once

#include "Entity.h"

#include <iostream>
#include <string>

using std::cout;
using std::string;

//------------------------------------------------------------------------------
// Player
//------------------------------------------------------------------------------
class Stuff {
public:
    string desc;
    int points;
};

//------------------------------------------------------------------------------
// Player
//------------------------------------------------------------------------------
class Player : public Entity {
private:
    // game locations
    vector<string> vloc {
        "a dim tunnel into the gasworks",
        "a long passage with water dripping down",
        "the boiler room",
        "the core, with wires and pipes everywhere",
        "a giant steam pipe",
        "back in the bright sunshine",
    };

    // stuff player can acquire
    vector<Stuff> vobj {
        { "$100 bills scattered everywhere", AWARD_POINTS },
        { "piles of sparkling rubies, half-submerged in puddles", AWARD_POINTS },
        { "rusty pipe wrench", AWARD_POINTS },
        { "safety glasses", AWARD_POINTS },
        { "Mickey Mouse Pez dispenser", AWARD_POINTS },
    };

    // for treasure acquired
    vector<Stuff> vacquired;

public:
    Player() { }

    int getNumActions() const { return (int) vloc.size(); }

    // return the object player acquires, update player points
    string acquireStuff() { 
        int stuffIndex = rand() % vobj.size();
        Stuff s = vobj.at(stuffIndex);

        cout << s.desc << " worth " << s.points << " points\n";

        vacquired.push_back(s);
        updatePoints(s.points);

        return s.desc;
    }

    // display all player treasure acquired
    void displayStuff() {
        for (Stuff s : vacquired)
        cout << s.desc << " worth " << s.points << '\n';
    }

    // return entity action string from its vector of possible actions
    string act() {
        int index = rand() % vloc.size();
        return vloc.at(index);
    }
};

