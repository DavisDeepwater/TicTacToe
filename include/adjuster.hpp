#ifndef ADJUSTER_HPP_INCLUDED
#define ADJUSTER_HPP_INCLUDED

class Num_adj : public Widget
{
protected:
    int _ib,_iu;
    int _count = 0;
public:
    Num_adj(int x, int y, int sx, int sy, int ib, int iu);
    virtual void draw();
    virtual void event_handler(genv::event ev);
};

#endif // ADJUSTER_HPP_INCLUDED
