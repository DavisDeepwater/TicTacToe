#include "graphics.hpp"
#include "statictext.hpp"
using namespace genv;

StaticText::StaticText(int x, int y, std::string _t) : Widget(x,y,genv::gout.twidth(_t)+5, 30), text(_t){}

void StaticText::event_handler(genv::event) {}

void StaticText::draw() const
{
    gout << move_to(_x, _y) << color(255,204,0) << genv::text(text);
}

void StaticText::clear_text() const
{
    gout << move_to(_x, _y) << color(0,0,0) << genv::text(text);
}

void StaticText::set_text(std::string _t)
{
    clear_text();
    this->text = _t;
}

