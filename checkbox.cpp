#include "checkbox.hpp"
#include "graphics.hpp"
using namespace genv;

CheckBox::CheckBox(int x, int y, int sx, int sy) : Widget(x,y,sx,sy)
{
    _checked=false;
}

void CheckBox::draw()
{
    gout << move_to(_x, _y) << color(0,255,255) << box(_sx, _sy);
    gout << move_to(_x+1, _y+1) << color(0,128,128) << box(_sx-2, _sy-2);
    if (_checked)
    {
        gout << color(0,0,255);

        float r = _sx/2 -4;

        for(int i = -r ; i < r; i++)
        {
            for(int j = -r; j < r; j++)
            {
                if(i*i + j*j < r*r )
                {
                    gout << move_to(i + _x+_sx/2 ,j + _y + _sy/2) << dot;
                }
            }
        }

        gout << color(0,128,128);

         r = _sx/2 -8;

        for(int i = -r ; i < r; i++)
        {
            for(int j = -r; j < r; j++)
            {
                if(i*i + j*j < r*r )
                {
                    gout << move_to(i + _x+_sx/2 ,j + _y + _sy/2) << dot;
                }
            }
        }

/*
        gout << color(255,204,0);
        gout << move_to(_x+3, _y+4) << line(_sx-8, _sy-8);
        gout << move_to(_x+4, _y+4) << line(_sx-8, _sy-8);
        gout << move_to(_x+5, _y+4) << line(_sx-8, _sy-8);
        gout << move_to(_x+_sx-3, _y+4) << line(-_sx+8, _sy-8);
        gout << move_to(_x+_sx-4, _y+4) << line(-_sx+8, _sy-8);
        gout << move_to(_x+_sx-5, _y+4) << line(-_sx+8, _sy-8);*/
    }
}

void CheckBox::event_handler(event ev)
{

    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' '))
    {
        _checked = !_checked;
    }
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
    {
        _checked = !_checked;
    }
}
bool CheckBox::is_checked()
{
    return _checked;
}
