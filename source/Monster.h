//------------------------------------------------------------------------------
// Monster : class declaration and definition
//------------------------------------------------------------------------------
#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

//------------------------------------------------------------------------------
// Monster
//------------------------------------------------------------------------------
class Monster {
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
};

