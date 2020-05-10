#ifndef GAMECONTROLLER_HPP_INCLUDED
#define GAMECONTROLLER_HPP_INCLUDED

#include "widget.hpp"
#include "statictext.hpp"
#include "checkbox.hpp"
#include "adjuster.hpp"
#include "gametable.hpp"
#include "button.hpp"

class GameController
{
private:
    int height, width;
    std::vector<Widget*> v;
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

public:
    GameController(int X, int Y);
    void start_game(int table_size);
    void reset_game();
    void run() const;
};


#endif // GAMECONTROLLER_HPP_INCLUDED
