#include "gamecontroller.hpp"

int main()
{
    GameController* gm = new GameController(600,600);
    gm->start_game(27);

    return 0;
}
