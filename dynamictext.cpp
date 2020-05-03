#include "graphics.hpp"
#include "dynamictext.hpp"
#include <string>
using namespace genv;

DynamicText::DynamicText(int x, int y, int sx, int sy) : Widget(x,y,sx,sy)
{
}

void DynamicText::draw()
{
    gout << move_to(_x,_y) << color(0,255,255) << box(_sx,_sy);
    gout << move_to(_x+1,_y+1) << color(0,128,128) << box(_sx-2,_sy-2);
    if(selected)
    {

        gout << move_to(_x,_y) << color(255,204,0) << box(_sx,_sy);
        gout << move_to(_x+3,_y+3) << color(0,128,128) << box(_sx-6,_sy-6);
        gout << move_to(_x+5+gout.twidth(_text),_y+20) << color(0,0,0) << text('|');
        gout << move_to(_x+5,_y+20) << color(255,204,0) << text(_text);
    }
    gout << move_to(_x+5,_y+20) << color(255,204,0) << text(_text);
}

void DynamicText::event_handler(event ev)
{
    if(ev.button == btn_left)
    {
        if(is_selected(ev.pos_x,ev.pos_y))
        {
            selected = true;
        }
        else
        {
            selected = false;
        }
    }

    if(ev.type == ev_key && selected && ev.keycode > 0 && gout.twidth(_text) < _sx -12 && ev.keycode != key_backspace)
    {
       _text += ev.keycode;
    }

    if(ev.keycode == key_backspace && _text.length() > 0 && selected)
    {
       _text.erase(_text.length()-1);
    }

}
