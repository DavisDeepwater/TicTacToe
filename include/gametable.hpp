#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include "checkbox.hpp"
#include <iostream>
#include <vector>
using namespace std;
using namespace genv;


class GameTable : public Widget
{
private:
    enum Direction
    {
        horizontal,
        vertical,
        diagonal,
        antidiagonal
    };
    int checkbox_x;
    int checkbox_y;
    bool is_first_player;
    int table_size;
    vector<vector<CheckBox*>> table;
    int match_count;
    void calculate_match_count(int element_x, int element_y);
    int calculate_row(int element_x, int element_y, Direction direction);

    void init();
    void delete_table();
    void clear_draw();

protected:
    bool _checked;
public:
    const int final_count = 5;
    GameTable(int x, int y, int sx, int sy,int table_size);
    virtual void draw() ;
    virtual void event_handler(genv::event ev);
    bool is_gameover();
    void reset();
    bool is_blank();
    bool set_size(int table_size);
    bool is_firstplayer();
};


#endif // GAMEMASTER_HPP_INCLUDED
