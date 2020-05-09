#include "widget.hpp"
#include "button.hpp"
#include "graphics.hpp"
using namespace genv;

Button::Button(int x, int y, int sx, int sy, std::string label,std::function<void()> pf) : Widget(x,y,sx,sy), f(pf), label(label)
{

}

void Button::draw()
{
    gout << move_to(_x,_y) << color(0,255,255) << box(_sx,_sy);
    gout << move_to(_x+1,_y+1) << color(0,128,128) << box(_sx-2,_sy-2);
    gout << color(255,204,0) << move_to(_x+_sx/2-gout.twidth(label)/2,_y+_sy/2) << text(label);
    /*
    if(selected)
    {
        gout << move_to(_x,_y) << color(255,204,0) << box(_sx,_sy);
        gout << move_to(_x+3,_y+3) << color(0,128,128) << box(_sx-6,_sy-6);
        gout << color(255,204,0) << move_to(_x+_sx/2-gout.twidth(label)/2,_y+_sy/2) << text(label);
    }*/
}

void Button::event_handler(genv::event ev)
{

    if(ev.button == btn_left)
    {
        if(is_selected(ev.pos_x,ev.pos_y))
        {
            selected = true;
            action();
        }
        else
        {
            selected = false;
        }
    }
}

void Button::action()
{
    f();
}
