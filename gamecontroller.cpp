#include "graphics.hpp"
#include "widget.hpp"
#include "adjuster.hpp"
#include "gamecontroller.hpp"
#include "gametable.hpp"
using namespace genv;

GameController::GameController(int X, int Y)
{
    gout.open(X,Y);
    height = Y, width = X;
    gout << refresh;
}

void GameController::start_game(int table_size)
{
    gt = new GameTable(0,0,width,height,table_size);
    run();
}

void GameController::run()
{
    int selected = -1;
    event ev;
    while(gin >> ev && ev.keycode != key_escape)
    {
        /*
        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for(unsigned int i = 0; i < v.size(); i++)
            {
                if (v[i]->is_selected(ev.pos_x,ev.pos_y))
                {

                    selected = i;
                }
            }
        }*/
/*
        if (selected!=-1 )//&& !v[selected]->is_checked())
        {
            v[selected]->event_handler(ev);
        }
        for(Widget* w : v)
        {
            w->draw();
        }
*/
        //cout << gt->is_gameover() <<endl;
        gt->event_handler(ev);
        gt->draw();

        gout << refresh;
    }
}
