#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

class CheckBox : public Widget {
protected:
    bool _checked;
    bool is_x_pattern;
public:
    CheckBox(int x, int y, int sx, int sy, bool is_x_pattern = false);
    virtual void draw() const;
    virtual void event_handler(genv::event ev);
    bool is_checked() const;
    void check();
    void uncheck();
    void circle_pattern() const;
    void x_pattern() const;
    void set_x_pattern(bool is_x_pattern);
    bool get_x_pattern() const;
    virtual ~CheckBox() {};
};


#endif // CHECKBOX_HPP_INCLUDED
