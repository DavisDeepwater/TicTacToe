#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED


#include "graphics.hpp"
#include "widget.hpp"


#include <functional>

class Button : public Widget
{
    std::function<void()> f;
protected:
    std::string label;
public:
    Button(int x, int y, int sx, int sy, std::string label,std::function<void()> pf);
    virtual void draw();
    virtual void event_handler(genv::event ev);
    virtual void action();
};

#endif // BUTTON_HPP_INCLUDED
