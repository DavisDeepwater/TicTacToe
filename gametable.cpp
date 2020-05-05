#include "gametable.hpp"
using namespace genv;

GameTable::GameTable(int x, int y, int sx, int sy, int _size) : Widget(x,y,sx,sy)
{
    CheckBox* c;
    is_first_player = true;
    int checkbox_x = sx/_size;
    int checkbox_y = sy/_size;
    table_size = _size;
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
                }

                return;
            }
        }
    }

}
