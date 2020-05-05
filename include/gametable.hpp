#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include "checkbox.hpp"
#include <vector>
using namespace std;
using namespace genv;

class GameTable : public Widget {
private:
    bool is_first_player;
    int table_size;
    vector<vector<CheckBox*>> table;
protected:
    bool _checked;
public:
    GameTable(int x, int y, int sx, int sy,int table_size);
    virtual void draw() ;
    virtual void event_handler(genv::event ev);
    //virtual bool is_checked() ;
};


#endif // GAMEMASTER_HPP_INCLUDED
