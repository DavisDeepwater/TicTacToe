#ifndef GAMECONTROLLER_HPP_INCLUDED
#define GAMECONTROLLER_HPP_INCLUDED

#include "statictext.hpp"
#include "dynamictext.hpp"
#include "checkbox.hpp"
#include "gametable.hpp"
#include <iostream>
#include <vector>
using namespace genv;
using namespace std;
class GameController
{
    int height, width;
    GameTable* gt;
    void run();


public:
    GameController(int X, int Y);
    void start_game(int table_size);

};


#endif // GAMECONTROLLER_HPP_INCLUDED
