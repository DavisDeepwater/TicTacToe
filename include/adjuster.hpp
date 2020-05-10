#ifndef ADJUSTER_HPP_INCLUDED
#define ADJUSTER_HPP_INCLUDED

class Num_adj : public Widget
{
protected:
    int _ib,_iu;
    int _count;
public:
    Num_adj(int x, int y, int sx, int sy, int ib, int iu);
    virtual void draw() const;
    virtual void event_handler(genv::event ev);
    int get_count() const;
    void set_count(int _count);
};

#endif // ADJUSTER_HPP_INCLUDED
