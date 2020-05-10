#include "widget.hpp"
#include "adjuster.hpp"
#include "graphics.hpp"
using namespace genv;

Num_adj::Num_adj(int x, int y, int sx, int sy, int ib, int iu) : Widget(x,y,sx,sy)
{
    _ib = ib;
    _iu = iu;
    _count = 15;
    selected = false;
}

void Num_adj::draw() const
{

    gout << move_to(_x,_y) << color(0,255,255) << box(_sx, _sy);
    gout << move_to(_x+1,_y+1) << color(0,128,128) << box(_sx-2, _sy-2);
    gout << color(0,255,255);
    gout << move_to(_x + _sx - 30, _y) << box(1,_sy);
    gout << move_to(_x + _sx -20,_y + 11) << line_to(_x + _sx - 15,_y + 6) << line_to(_x + _sx - 10,_y + 11);
    gout << move_to(_x + _sx -20,_y + 18) << line_to(_x + _sx - 15,_y + 23)<< line_to(_x + _sx - 10,_y + 18);

    if(selected)
    {
        gout << color(255,204,0) << move_to(_x,_y) << box(_sx, _sy);
        gout << move_to(_x+3,_y+3) << color(0,128,128) << box(_sx-6, _sy-6);
        gout << color(255,204,0);
        gout << move_to(_x + _sx - 30, _y)  << box(3,_sy);

        gout << move_to(_x + _sx - 10,_y + 11) << line_to(_x + _sx - 15,_y + 6) << line_to(_x  +_sx - 20,_y + 11);
        gout << move_to(_x + _sx - 11,_y + 11) << line_to(_x + _sx - 15,_y + 7) << line_to(_x + _sx - 19,_y + 11);
        gout << move_to(_x + _sx - 12,_y + 11) << line_to(_x + _sx - 15,_y + 8) << line_to(_x + _sx - 18,_y + 11);

        gout << move_to(_x + _sx - 10,_y + 18) << line_to(_x + _sx - 15,_y + 23) << line_to(_x  +_sx - 20,_y + 18);
        gout << move_to(_x + _sx - 11,_y + 18) << line_to(_x + _sx - 15,_y + 22) << line_to(_x  +_sx - 19,_y + 18);
        gout << move_to(_x + _sx - 12,_y + 18) << line_to(_x + _sx - 15,_y + 21) << line_to(_x  +_sx - 18,_y + 18);

    }
    gout << move_to(_x + 5, _y + 20) << color(255,204,0) << text(std::to_string(_count));
}

void Num_adj::event_handler(event ev)
{
    if(ev.type == ev_mouse && ev.button == btn_left)
    {
        if(is_selected(ev.pos_x, ev.pos_y))
        {
            selected = true;
            if(ev.pos_x > _x + _sx -30 && ev.pos_x < _x + _sx && ev.pos_y < _y + _sy/2 && _count < _iu)
            {
                _count++;
            }
            else if(ev.pos_x > _x + _sx -30 && ev.pos_x < _x + _sx && ev.pos_y > _y + _sy/2 && _count > _ib)
            {
                _count--;
            }
        }
        else
        {
            selected = false;
        }
    }

    if(ev.type == ev_key && selected)
    {
        if(_count < _iu && ev.keycode == key_up )
        {
            ++_count;
        }
        if(_count > _ib && ev.keycode == key_down)
        {
            --_count;
        }
        if(_count + 10 <= _iu && ev.keycode == key_pgup)
        {
            _count+=10;
        }
        if(_count - 10 >= _ib && ev.keycode == key_pgdn)
        {
            _count-=10;
        }
    }
}

int Num_adj::get_count() const
{
    return _count;
}

void Num_adj::set_count(int _count)
{
    this->_count = _count;
}
