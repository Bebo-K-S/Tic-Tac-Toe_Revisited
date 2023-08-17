
#include "homepagescene.cpp"

using namespace std;
using namespace sf;

int main()
{
    int* scene = new int(0);
    
    RenderWindow window(VideoMode(800, 600), "Tic-Tac-Toe");
    window.setVerticalSyncEnabled(true);
    
    Game game;

    while (*scene != -1)
    {
        switch (*scene)
        {
        case 0:
            runHomePageScene(scene, &window, &game);
            break;
        case 1:
            /*Go to respective scene function      */
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