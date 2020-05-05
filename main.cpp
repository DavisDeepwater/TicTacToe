#include "graphics.hpp"
#include "widget.hpp"
#include "adjuster.hpp"
#include "statictext.hpp"
#include "dynamictext.hpp"
#include "checkbox.hpp"
#include "gametable.hpp"
#include <iostream>
#include <vector>
using namespace genv;
using namespace std;

struct Application;

struct Application
{
    vector<CheckBox*> v;
    CheckBox* c;
    GameTable* gt;


public:
    Application()
    {
        gout.open(600,600);
        gout << color(20,0,70) << move_to(0,0) << box(600,600);

        for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j < 15; j++)
            {
                c = new CheckBox(i*40,j*40,40,40);
                v.push_back(c);
            }
        }

        gt = new GameTable(0,0,600,600,15);

        gout << refresh;
    }

    void run()
    {
        //int selected = -1;
        //bool is_x_pattern = false;
        event ev;
        while(gin >> ev)
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
            }

            if (selected!=-1 && !v[selected]->is_checked())
            {
                is_x_pattern = !is_x_pattern;
                v[selected]->set_x_pattern(is_x_pattern);
                v[selected]->event_handler(ev);
            }

            for(Widget* w : v)
            {
                w->draw();
            }
            */
            gt->event_handler(ev);
            gt->draw();

            gout << refresh;
        }
    }
};


int main()
{
    Application app;
    app.run();

    return 0;
}
