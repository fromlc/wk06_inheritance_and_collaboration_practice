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
//  - jot down notes, ask more questions
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
    vector<string> obj {
        "$100 bills scattered everywhere",
        "piles of sparkling rubies, half-submerged in puddles",
        "rusty pipe wrench",
        "safety glasses",
        "Mickey Mouse Pez dispenser",
    };
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
char getCmd(string&);
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

    cout << "Welcome to Gasworks Park! Enter at your peril...\n\n";
}

//------------------------------------------------------------------------------
// play the game
//------------------------------------------------------------------------------
void gameLoop() {

    // visit each location
    for (string loc : g::vloc) {

        // dummy command for now - all actions are random
        char cmd = getCmd(loc);

//        // player takes random action, gets points
//        cout << g::player.act() << '\n';
//        // random monster takes random action, player loses points
//        cout << g::monster.act() << '\n';
//        // display outcome
//        int points = g::player.getPoints();
//        cout << "Points so far: " << points << '\n';
    }

}

//------------------------------------------------------------------------------
// returns one-character user command
//------------------------------------------------------------------------------
char getCmd(string& loc) {
    char cmd;
    cout << "\nYou're in " << loc << ". Which way? ";
    cin >> cmd;
    return cmd;
}

//------------------------------------------------------------------------------
// cleanup tasks
//------------------------------------------------------------------------------
void endGame() {

    cout << "\nTotal points: \n";
    cout << "Goodbye!\n";
}