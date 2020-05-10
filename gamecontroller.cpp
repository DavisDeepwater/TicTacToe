#include "graphics.hpp"
#include "gamecontroller.hpp"
using namespace genv;


GameController::GameController(int X, int Y)
{
    gout.open(X,Y);
    height = Y, width = X;
    gout << refresh;
}

void GameController::start_game(int table_size)
{
    a = new Num_adj(width-110,110, 70, 30, 15,30);
    a->set_count(table_size);
    v.push_back(a);

    gt = new GameTable(0,0,width-(width-height),height,table_size);
    v.push_back(gt);

    b = new Button(width-150,240,100,25,"Reset",[&]()
    {
        reset_game();
    });
    v.push_back(b);

    b2 = new Button(width-150,180,100,25,"Change",[&]()
    {
        gt->set_size(a->get_count());
    });
    v.push_back(b2);

    st = new StaticText(width-140,30,"TicTacToe");
    v.push_back(st);

    st2 = new StaticText(width-160,130,"Size:");
    v.push_back(st2);

    st3 = new StaticText(width-177,80,"Winner:");
    v.push_back(st3);

    st4 = new StaticText(width-110,80,"");
    v.push_back(st4);

    b3 = new Button(width-150,300,100,25,"Exit",[&]()
    {
        is_stopped = true;
    });
    v.push_back(b3);

    run();
}

void GameController::reset_game()
{
    st4->set_text("");
    gt->reset();
}

void GameController::run() const
{
    int selected = -1;
    event ev;
    while(gin >> ev && ev.keycode != key_escape && !is_stopped )
    {

        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for(unsigned int i = 0; i < v.size(); i++)
            {
                if (v[i]->is_selected(ev.pos_x,ev.pos_y))
                {

                    if (selected!=-1)
                    {
                        v[selected]->set_selected(false);
                    }
                    selected = i;

                }
            }
        }

        if (selected!=-1 )
        {
            v[selected]->event_handler(ev);
            std::string s;
            if (typeid(*v[selected]) == typeid(GameTable) && gt->is_gameover())
            {
                s = gt->is_firstplayer()?"'x'":"'o'";
                st4->set_text(s);
            }

            if(typeid(*v[selected]) == typeid(GameTable) && gt->is_full())
            {
                s = "draw";
                st4->set_text(s);
            }

        }
        for(Widget* w : v)
        {
            w->draw();
        }

        gout << refresh;
    }
}



