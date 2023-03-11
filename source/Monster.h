//------------------------------------------------------------------------------
// Monster : class declaration and definition
//------------------------------------------------------------------------------
#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int MONSTER_MAX = 7;

//------------------------------------------------------------------------------
// Monster
//------------------------------------------------------------------------------
class Monster : public Entity {
private:
    vector<string> vm {
        "swarming spiders",
        "biting bats",
        "sparking live wire",
        "rats the size of poodles",
        "glow worms",
    };

public:
    Monster() { }

    // return random number of points for each monster encountered
    int getRandomPoints() {
        int randomPoints = rand() % MONSTER_MAX + 1;
        updatePoints(randomPoints);
        return randomPoints;
    }

    // return entity action string from its vector of possible actions
    string act() {
        int index = rand() % vm.size();
        return vm.at(index);
    }
};

