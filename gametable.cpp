#include "gametable.hpp"
#include <algorithm>
#include <initializer_list>
#include <iostream>
using namespace genv;

GameTable::GameTable(int x, int y, int sx, int sy, int _size) : Widget(x,y,sx,sy)
{
    checkbox_x = sx/_size;
    checkbox_y = sy/_size;
    table_size = _size;
    init();
}

void GameTable::init()
{
    CheckBox* c;
    is_first_player = true;

    match_count = 0;
    for(int i = 0; i < table_size; i++)
    {
        table.push_back(std::vector<CheckBox*>());
        for(int j = 0; j < table_size; j++)
        {
            c = new CheckBox(i * checkbox_x,j * checkbox_y,checkbox_x,checkbox_y);
            table[i].push_back(c);
        }
    }
}


void GameTable::delete_table()
{
    for(int i = 0; i < table_size; i++)
    {
        for(int j = 0; j < table_size; j++)
        {
           delete table[i][j];
        }
        table[i].clear();
    }
    table.clear();
    clear_draw();
}

void GameTable::draw() const
{
    for(int i = 0; i < table_size; i++)
    {
        for(int j = 0; j < table_size; j++)
        {
            table[i][j]->draw();
        }
    }

}

void GameTable::clear_draw() const
{
    gout << color(0,0,0) << move_to(_x,_y) << box(_sx,_sy);
}

void GameTable::event_handler(event ev)
{
    if(is_gameover())
    {
        return;
    }

    for(int i = 0; i < table_size; i++)
    {
        for(int j = 0; j < table_size; j++)
        {
            if (ev.type == ev_mouse && table[i][j]->is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
            {

                if(!table[i][j]->is_checked() )
                {
                    table[i][j]->set_x_pattern(is_first_player);

                    table[i][j]->check();
                    calculate_match_count(i,j);
                    if(!is_gameover())
                    {
                        is_first_player = !is_first_player;
                    }
                }
                return;
            }
        }
    }

}

bool GameTable::set_size(int table_size)
{
    if(is_blank())
    {
        delete_table();
        checkbox_x = _sx/table_size;
        checkbox_y = _sy/table_size;
        this->table_size = table_size;
        init();
        return true;
    }
    return false;
}



void GameTable::calculate_match_count(int element_x, int element_y)
{
    int match_counter_vertical = calculate_row(element_x, element_y, Direction::vertical);
    int match_counter_antidiagonal = calculate_row(element_x, element_y, Direction::antidiagonal);
    int match_counter_diagonal = calculate_row(element_x, element_y, Direction::diagonal);
    int match_counter_horizontal = calculate_row(element_x, element_y, Direction::horizontal);
    match_count = std::max({match_counter_antidiagonal, match_counter_diagonal, match_counter_horizontal,match_counter_vertical});
}

bool GameTable::is_check_index(int x, int y) const
{
    return x>=0 && x<table_size && y>=0 && y<table_size;
}

int GameTable::calculate_row(int element_x, int element_y, Direction direction) const
{
    int match_counter_helper = 1;
    bool is_x_pattern = table[element_x][element_y]->get_x_pattern();

    bool* is_x_increase;
    bool* is_y_increase;

    is_x_increase = direction != Direction::vertical?new bool(true):nullptr;
    is_y_increase = direction == Direction::vertical || direction == Direction::diagonal?new bool(true):nullptr;
    is_y_increase = is_y_increase == nullptr && direction == antidiagonal?new bool(false):is_y_increase;

    int x = element_x;
    int y = element_y;
    int i = 0;
    int j = 0;

    while(x < table_size || y < table_size)
    {
        if( is_x_increase != nullptr)
        {
            i++;
            x = *is_x_increase?element_x+i:element_x-i;
        }

        if(is_y_increase != nullptr)
        {
            j++;
            y = *is_y_increase?element_y+j:element_y-j;
        }

        if(!is_check_index(x,y) || !table[x][y]->is_checked() || table[x][y]->get_x_pattern() != is_x_pattern)
        {
            break;
        }
        match_counter_helper++;
    }

     i = 0;
     j = 0;

    while(x > 0 || y > 0)
    {
        if( is_x_increase != nullptr)
        {
            i--;
            x = *is_x_increase?element_x+i:element_x-i;
        }

        if(is_y_increase != nullptr)
        {
            j--;
            y = *is_y_increase?element_y+j:element_y-j;
        }

        if(!is_check_index(x,y) || !table[x][y]->is_checked() || table[x][y]->get_x_pattern() != is_x_pattern)
        {
            break;
        }
        match_counter_helper++;
    }
    return match_counter_helper;
}

void GameTable::reset()
{
    is_first_player = true;
    match_count = 0;
    for(int i = 0; i < table_size; i++)
    {
        for(int j = 0; j < table_size; j++)
        {
            if(table[i][j]->is_checked() )
            {
                table[i][j]->uncheck();
            }
        }
    }
}

bool GameTable::is_blank() const
{
    for(int i = 0; i < table_size; i++)
    {
        for(int j = 0; j < table_size; j++)
        {
            if(table[i][j]->is_checked())
            {
               return false;
            }
        }
    }
    return true;
}

bool GameTable::is_full() const
{
     for(int i = 0; i < table_size; i++)
    {
        for(int j = 0; j < table_size; j++)
        {
            if(!table[i][j]->is_checked())
            {
               return false;
            }
        }
    }
    return true;
}

bool GameTable::is_firstplayer() const
{
    return is_first_player;
}

bool GameTable::is_gameover() const
{
    return match_count >= final_count;
}
