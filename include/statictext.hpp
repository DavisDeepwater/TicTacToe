#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED
#include "widget.hpp"

class StaticText : public Widget{
protected:
    std::string text;
public:
    StaticText(int x, int y, std::string _t);
    virtual void draw() override;
    void event_handler(genv::event ev) override;
    bool is_selected(int mouse_x, int mouse_y);
};

#endif // STATICTEXT_HPP_INCLUDED
