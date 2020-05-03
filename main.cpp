#include "graphics.hpp"
#include "widget.hpp"
#include "adjuster.hpp"
#include "statictext.hpp"
#include "dynamictext.hpp"
#include "checkbox.hpp"
#include <iostream>
#include <vector>
using namespace genv;
using namespace std;

struct Application;

/*
struct CValtoztatoGomb : Button
{
    CValtoztatoGomb(int x, int y, int sx, int sy, string label, Application* papp);
    Application* app;
    virtual void action() override;
};*/

struct Application
{
    vector<Widget*> v;
    CheckBox* c;
    /*
    StaticText* s1;
    DynamicText* d;
    Num_adj* n;
    Selector* s;
    CValtoztatoGomb * b;
    FunctionPointerButton* b2;
    StdFunctionButton* b3;*/


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

        /*


                b = new CValtoztatoGomb(10,10,100,30,"gomb",this);
                v.push_back(b);

                b2 = new FunctionPointerButton(400,200,100,30,"fvpbutton",sc_valtozzon,this);
                v.push_back(b2);

                b3 = new StdFunctionButton(400,300,100,30,"stdfunc",[&](){c->toggle();});
                v.push_back(b3);

                s1 = new StaticText(100,100,"Hello world");
                v.push_back(s1);

                d = new DynamicText(300,100,100,30);
                v.push_back(d);

                n = new Num_adj(150,10,100,30,-100,55);
                v.push_back(n);

                vector<string> ss;
                ss.push_back("egy");
                ss.push_back("ketto");
                ss.push_back("harom");
                ss.push_back("negy");
                ss.push_back("ot");
                ss.push_back("hat");
                ss.push_back("het");
                ss.push_back("nyolc");
                ss.push_back("kilenc");
                ss.push_back("tiz");
                Selector* s = new Selector(100,300,140,200,ss);
                v.push_back(s);
        */
        gout << refresh;
    }
   /*
    static void sc_valtozzon(void* param)
    {
        Application * app = reinterpret_cast<Application*>(param);
        app->c_valtozzon();
    }

    void c_valtozzon()
    {
        c->toggle();
    }
*/
    void run()
    {
        int selected = -1;
        event ev;
        while(gin >> ev)
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

            if (selected!=-1)
            {
                v[selected]->event_handler(ev);
            }

            for(Widget* w : v)
            {
                w->draw();
            }
            gout << refresh;
        }
    }
};

/*
CValtoztatoGomb::CValtoztatoGomb(int x, int y, int sx, int sy, string label, Application* papp):Button(x,y,sx,sy,label),app(papp)
{

}

void CValtoztatoGomb::action()
{
    app->c_valtozzon();
}*/

int main()
{
    Application app;
    //Application::sc_valtozzon(&app);
    //app.c_valtozzon();
    app.run();

    return 0;
}
