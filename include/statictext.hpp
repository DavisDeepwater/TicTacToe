#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED
#include "widget.hpp"

class StaticText : public Widget{
protected:
    std::string text;
public:
    StaticText(int x, int y, std::string _t);
    virtual void draw() const;
    void event_handler(genv::event ev);
    void set_text(std::string _t);
    void clear_text() const;
};

#endif // STATICTEXT_HPP_INCLUDED
