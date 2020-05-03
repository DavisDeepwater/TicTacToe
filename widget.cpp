#include "widget.hpp"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy) : _x(x), _y(y), _sx(sx), _sy(sy){
}

bool Widget::is_selected(int ex, int ey)
{
     if(ex>_x && ex<_x+_sx && ey>_y && ey<_y+_sy)
     {
         return true;
     }
     else return false;
}

void Widget::set_selected(bool selected)
{
    this->selected = selected;
}

