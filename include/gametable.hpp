#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include "checkbox.hpp"
#include <vector>

class GameTable : public Widget
{
protected:
    std::vector<std::vector<CheckBox*>> table;
    bool _checked;
    bool is_first_player;
    int checkbox_x;
    int checkbox_y;
    int table_size;
    int match_count;
    const int final_count = 5;
public:
    GameTable(int x, int y, int sx, int sy,int table_size);
    virtual void draw() const;
    virtual void event_handler(genv::event ev);
    enum Direction
    {
        horizontal,
        vertical,
        diagonal,
        antidiagonal
    };

    bool set_size(int table_size);
    bool is_firstplayer() const;
    void calculate_match_count(int element_x, int element_y);
    int calculate_row(int element_x, int element_y, Direction direction) const;
    void delete_table();
    void clear_draw() const;
    bool is_gameover() const;
    bool is_blank() const;
    bool is_full() const;
    void reset();
    void init();
    bool is_check_index(int x, int y) const;
};


#endif // GAMEMASTER_HPP_INCLUDED
