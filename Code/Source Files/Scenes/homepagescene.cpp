#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <chrono>
#include <thread>

#include "game.h"

using namespace sf;

inline void runHomePageScene(int* scene, RenderWindow* window, Game* game)
{
    /* Loading the Inika font and if failed to close the program */
    Font font;
    if (!font.loadFromFile("Assets/Fonts/Gloria_Hallelujah/GloriaHallelujah-Regular.ttf"))
    {
        cout << "Error loading font" << endl;
        *scene = -1;
        return;
    }

    /* Loading the background and if failed to close the program */
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Assets/Backgrounds/Home_Screen_Background.jpg"))
    {
        cout << "Error loading background image\n";
        *scene = -1;
        return;
    }

    /* Loading the sound buffers and if failed to close the program*/
    SoundBuffer chalkeraseBuffer;
    if (!chalkeraseBuffer.loadFromFile("Assets/Sound/Chalk_Eraser.wav"))
    {
        cout << "Error loading buffer sound\n";
        *scene = -1;
        return;
    }


    /* Beginning of declaring shapes and texts to use */
    RectangleShape background(Vector2f(800, 600));
    background.setTexture(&backgroundTexture);
    background.setPosition(Vector2f(0, 0));

    Text startGameText("Start Game", font, 40);
    startGameText.setPosition(280, 374);

    Sound chalkerase;
    chalkerase.setBuffer(chalkeraseBuffer);
    

    /* The beginning of the display what'll be in the window */
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

            if (event.type == Event::MouseButtonPressed)
            {
                if (startGameText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
                {
                    chalkerase.play();
                    this_thread::sleep_for(chrono::milliseconds(375));
                    *scene = 1;
                    return;
                }
            }
        }

        startGameText.setFillColor(Color(0xF6, 0xF1, 0xF1));
        if (startGameText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
        {
            startGameText.setFillColor(Color(0xAF, 0xD3, 0xE2));
        }

        window->clear(Color::White);

        window->draw(background);
        window->draw(startGameText);

        window->display();
    }
}