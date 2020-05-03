#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

class CheckBox : public Widget {
protected:
    bool _checked;
public:
    CheckBox(int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void event_handler(genv::event ev);
    virtual bool is_checked() ;
    void toggle()
    {
        _checked = !_checked;
    }
};


#endif // CHECKBOX_HPP_INCLUDED
