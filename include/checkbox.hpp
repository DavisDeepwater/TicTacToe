#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

class CheckBox : public Widget {
protected:
    bool _checked;
    bool is_x_pattern;
    void circle_pattern();
    void x_pattern();
public:
    CheckBox(int x, int y, int sx, int sy, bool is_x_pattern = false);
    virtual void draw() ;
    virtual void event_handler(genv::event ev);
    virtual bool is_checked() ;
    void check();
    void set_x_pattern(bool is_x_pattern);
    bool get_x_pattern();
};


#endif // CHECKBOX_HPP_INCLUDED
