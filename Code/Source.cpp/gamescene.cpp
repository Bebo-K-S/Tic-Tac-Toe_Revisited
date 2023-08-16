#include <SFML/Graphics.hpp>
#include "game.h"

using namespace std;
using namespace sf;

inline void runGameScene(int *scene, RenderWindow *window, Game *game)
{
    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                *scene = -1;
                window->close();
            }
        }

        window->clear(Color::White);

        window->display();
    }
}