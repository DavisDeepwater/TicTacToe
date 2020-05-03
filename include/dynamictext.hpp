#ifndef DYNAMICTEXT_HPP_INCLUDED
#define DYNAMICTEXT_HPP_INCLUDED
#include "widget.hpp"

class DynamicText : public Widget{
protected:
    std::string _text;
public:
    DynamicText(int x, int y, int sx, int sy);
    virtual void draw();
    virtual void event_handler(genv::event ev);
};


#endif // DYNAMICTEXT_HPP_INCLUDED
