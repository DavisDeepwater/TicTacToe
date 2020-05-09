#include "gamecontroller.hpp"

int main()
{
    GameController* gm = new GameController(800,600);
    gm->start_game(15);

    return 0;
}
