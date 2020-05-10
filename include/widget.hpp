#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include "graphics.hpp"

class Widget
{
protected:
    int _x, _y, _sx, _sy;
    bool selected;
public:
    Widget(int x, int y, int sx, int sy);
    bool is_selected(int ex, int ey) const;
    virtual void draw() const = 0;
    virtual void event_handler(genv::event ev) = 0;
    void set_selected(bool selected);
};

#endif // WIDGET_HPP_INCLUDED
