#include "checkbox.hpp"
#include "graphics.hpp"
using namespace genv;

CheckBox::CheckBox(int x, int y, int sx, int sy, bool is_x_pattern) : Widget(x,y,sx,sy)
{
    _checked=false;
    this->is_x_pattern = is_x_pattern;
}

void CheckBox::circle_pattern() const
{
    gout << color(0,0,255);

            float r = _sx/2 -4;

            for(int i = -r ; i < r; i++)
            {
                for(int j = -r; j < r; j++)
                {
                    if(i*i + j*j < r*r )
                    {
                        gout << move_to(i + _x+_sx/2,j + _y + _sy/2) << dot;
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
                        gout << move_to(i + _x+_sx/2,j + _y + _sy/2) << dot;
                    }
                }
            }
}


void CheckBox::x_pattern() const
{
        gout << color(255,204,0);
        gout << move_to(_x+3, _y+4) << line(_sx-8, _sy-8);
        gout << move_to(_x+4, _y+4) << line(_sx-8, _sy-8);
        gout << move_to(_x+5, _y+4) << line(_sx-8, _sy-8);
        gout << move_to(_x+_sx-3, _y+4) << line(-_sx+8, _sy-8);
        gout << move_to(_x+_sx-4, _y+4) << line(-_sx+8, _sy-8);
        gout << move_to(_x+_sx-5, _y+4) << line(-_sx+8, _sy-8);
}

void CheckBox::draw() const
{
        gout << move_to(_x, _y) << color(0,255,255) << box(_sx, _sy);
        gout << move_to(_x+1, _y+1) << color(0,128,128) << box(_sx-2, _sy-2);
        if (_checked)
        {
            if(is_x_pattern)
            {
                x_pattern();
            }
            else
            {
                circle_pattern();
            }
            //is_x_pattern?x_pattern():circle_pattern();
        }



}

void CheckBox::set_x_pattern(bool is_x_pattern)
{
    this->is_x_pattern = is_x_pattern;
}

bool CheckBox::get_x_pattern() const
{
    return is_x_pattern;
}

void CheckBox::event_handler(event ev)
{
    if (ev.type == ev_mouse && ev.button==btn_left && is_selected(ev.pos_x, ev.pos_y))
    {
        _checked = true;
    }
}

void CheckBox::check()
{
    _checked = true;
}

void CheckBox::uncheck()
{
    _checked = false;
}

bool CheckBox::is_checked() const
{
    return _checked;
}
