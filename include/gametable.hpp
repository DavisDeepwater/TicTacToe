#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include "checkbox.hpp"
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

    bool is_first_player;
    int table_size;
    vector<vector<CheckBox*>> table;
    int match_count;
    void calculate_match_count(int element_x, int element_y);
    int calculate_row(int element_x, int element_y, Direction direction);
protected:
    bool _checked;
public:
    const int final_count = 5;
    GameTable(int x, int y, int sx, int sy,int table_size);
    virtual void draw() ;
    virtual void event_handler(genv::event ev);
    bool is_gameover();

};


#endif // GAMEMASTER_HPP_INCLUDED
