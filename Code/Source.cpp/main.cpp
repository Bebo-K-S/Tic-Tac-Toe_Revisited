#include "gamescene.cpp"

using namespace std;
using namespace sf;

int main()
{
    int* scene = new int(0);
    Game game;
    RenderWindow window(VideoMode(800, 600), "Tic-Tac-Toe");
    window.setVerticalSyncEnabled(true);

    while (*scene != -1)
    {
        switch (*scene)
        {
        case 0:
            runGameScene(scene, &window, &game);
            break;
        case 1:
            /*Go to respective scene function*/
            break;
            /*
              .
              .
              .
              .
            */
        }
    }

    return 0;
}