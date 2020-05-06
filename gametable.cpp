#include "gametable.hpp"
#include <algorithm>
#include <initializer_list>
#include <iostream>
using namespace genv;

GameTable::GameTable(int x, int y, int sx, int sy, int _size) : Widget(x,y,sx,sy)
{
    CheckBox* c;
    is_first_player = true;
    int checkbox_x = sx/_size;
    int checkbox_y = sy/_size;
    table_size = _size;
    match_count = 0;
    for(int i = 0; i < _size; i++)
    {
        table.push_back(vector<CheckBox*>());
        for(int j = 0; j < _size; j++)
        {
            c = new CheckBox(i * checkbox_x,j * checkbox_y,checkbox_x,checkbox_y);
            table[i].push_back(c);
        }
    }
}

void GameTable::draw()
{
    for(int i = 0; i < table_size; i++)
    {
        for(int j = 0; j < table_size; j++)
        {
            table[i][j]->draw();
        }
    }
}

void GameTable::event_handler(event ev)
{

    for(int i = 0; i < table_size; i++)
    {
        for(int j = 0; j < table_size; j++)
        {
            if (ev.type == ev_mouse && table[i][j]->is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
            {

                if(!table[i][j]->is_checked() )
                {
                    table[i][j]->set_x_pattern(is_first_player);
                    is_first_player = !is_first_player;
                    table[i][j]->check();
                    calculate_match_count(i,j);
                }

                return;
            }
        }
    }

}



void GameTable::calculate_match_count(int element_x, int element_y)
{
    int match_counter_vertical = calculate_row(element_x, element_y, Direction::vertical);
    int match_counter_horizontal = calculate_row(element_x, element_y, Direction::horizontal);
    int match_counter_diagonal = calculate_row(element_x, element_y, Direction::diagonal);
    int match_counter_antidiagonal = calculate_row(element_x, element_y, Direction::antidiagonal);

    match_count = std::max({match_counter_antidiagonal, match_counter_diagonal, match_counter_horizontal,match_counter_vertical});



}

int GameTable::calculate_row(int element_x, int element_y, Direction direction)
{
    int match_counter_helper = 1;
    bool is_x_pattern = table[element_x][element_y]->get_x_pattern();

    bool* is_x_increase;
    bool* is_y_increase;

    is_x_increase = direction == Direction::horizontal || direction == Direction::diagonal?new bool(true):nullptr;
    is_y_increase = direction == Direction::vertical || direction == Direction::diagonal?new bool(true):nullptr;
    is_y_increase = is_y_increase == nullptr && direction == antidiagonal?new bool(false):is_y_increase;


    int x = element_x;
    int y = element_y;

    for(int i = element_x + 1; i < table_size; i++)
    {
        if( is_x_increase != nullptr)
        {
            x = *is_x_increase?i:table_size-i;
        }

        if(is_y_increase != nullptr)
        {
            y = *is_y_increase?abs(i-element_y):table_size-i;
        }


        if(!table[x][y]->is_checked() || table[x][y]->get_x_pattern() != is_x_pattern)
        {
            break;
        }
        match_counter_helper++;
    }

    for(int i = element_x - 1; i > 0; i--)
    {
        if( is_x_increase != nullptr)
        {
            x = *is_x_increase?i:table_size-i;
        }

        if(is_y_increase != nullptr)
        {
            y = *is_y_increase?abs(i-element_y):table_size-i;
        }

        if( !table[x][y]->is_checked() || table[x][y]->get_x_pattern() != is_x_pattern)
        {
            break;
        }
        match_counter_helper++;
    }
    return match_counter_helper;
}

bool GameTable::is_gameover()
{
    return match_count >= final_count;
}
