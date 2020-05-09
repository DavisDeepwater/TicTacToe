#ifndef GAMECONTROLLER_HPP_INCLUDED
#define GAMECONTROLLER_HPP_INCLUDED

#include "widget.hpp"
#include "statictext.hpp"
#include "dynamictext.hpp"
#include "checkbox.hpp"
#include "adjuster.hpp"
#include "statictext.hpp"
#include "gametable.hpp"
#include "button.hpp"
#include <iostream>
#include <vector>
using namespace genv;
using namespace std;

/*
class GameController;

class TableSize : Button
{
    public:
    TableSize(int x, int y, int sx, int sy, string label, GameController* pgc);
    GameController* gc;
    virtual void action() override;
    void c_valtozzon();
};*/

class GameController
{
    int height, width;
    vector<Widget*> v;
    GameTable* gt;
    Num_adj* a;
    StaticText* st;
    StaticText* st2;
    StaticText* st3;
    Button* b;
    Button* b2;
    Button* b3;
    StaticText* st4;
    bool is_stopped;

    void run();

public:
    GameController(int X, int Y);
    void start_game(int table_size);
    void reset_game();


};


#endif // GAMECONTROLLER_HPP_INCLUDED
