//------------------------------------------------------------------------------
// gasworks.cpp
// 
// Gasworks game for one player
// - make your way through the derelict gasworks
// - gather stuff to score points
// - here be monsters that attack, harass, and take points away
// 
// This code is incomplete, since it's intended as a practice exercise. 
// 
// Add the code needed to create random interactions
// between a player and monster in the gasworks.
//------------------------------------------------------------------------------
// Step 1: Review the existing code to identify what's missing and what's there
//
// Here:
//  - some instructions are provided
//  - some classes are provided
//  - act() function calls are commented out
//  
//------------------------------------------------------------------------------
// Step 2: Get clarification
//  - ask questions about what the code is supposed to do
//  - jot down notes, these will generate more questions
//  - ask more questions until you have a clear approach to solving the problem
// 
//------------------------------------------------------------------------------
// Step 3: Determine how you can use the existing code
//
// Here:
//  - can you use the Entity class to simplify Player and Monster?
//  - what data and functions could be common to Player and Monster?
//
//      - both Player and Monster need to do random acts
//      - could you accomplish this with a common act() function?
//      - both Player and Monster could use a points member variable
// 
//------------------------------------------------------------------------------

#include "Player.h"
#include "Monster.h"

#include <cstdlib>
#include <iostream>
#include <vector>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::string;
using std::vector;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
namespace g {
    // user commands
    char cmds[] = { 'e', 'w', 'n', 's', 'u', 'd' };
    // participants
    Player player;
    Monster monster;
}

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void initGame();
void gameLoop();
char getCmd();
void endGame();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    initGame();
    gameLoop();
    endGame();
}

//------------------------------------------------------------------------------
// app banner, seed random number generator for all entities
//------------------------------------------------------------------------------
void initGame() {
    srand((unsigned int)time(0));

    cout << "\nYou're lost in the old Gasworks! Beware the monsters...\n\n";
}

//------------------------------------------------------------------------------
// play the game
//------------------------------------------------------------------------------
void gameLoop() {

    // visit each location, returned in reference parameter
    string loc;
    while (getCmd() != 'q') {

        // player takes random action, gets points
        cout << g::player.act() << '\n';
        // player acquires treasure
        g::player.acquireStuff();

        // random monster takes random action, player loses points
        int monsterPoints = g::monster.getRandomPoints();
        cout << g::monster.act() << "! You lose " 
            << monsterPoints << " points\n";

        // take away monster points
        g::player.updatePoints(-monsterPoints);

        // display outcome
        cout << "Points so far: " << g::player.getPoints() << "\n\n";

    }
}

//------------------------------------------------------------------------------
// returns one-character user command
//------------------------------------------------------------------------------
char getCmd() {
    char cmd;
    cout << "\nWhich way (q quits) ? ";
    cin >> cmd;
    return tolower(cmd);
}

//------------------------------------------------------------------------------
// cleanup tasks
//------------------------------------------------------------------------------
void endGame() {


    cout << "You found treasure!\n";

    // #TODO remove duplicates
    g::player.displayStuff();

    cout << "You bested monsters in battle!\n";

    // #TODO display which monsters were bested

    cout << "You scored " << g::player.getPoints() << " points!\n";

    cout << "\nGoodbye!\n\n";
}