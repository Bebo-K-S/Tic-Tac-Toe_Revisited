#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <chrono>
#include <thread>

#include "game.h"

using namespace sf;

inline void runGameScene(int *scene, RenderWindow *window, Game *game)
{
    /* Loading the Inika font and if failed to do so close the program */
    Font textFont;
    if (!textFont.loadFromFile("Assets/Fonts/Gloria_Hallelujah/GloriaHallelujah-Regular.ttf"))
    {
        cout << "Error loading font" << endl;
        *scene = -1;
        return;
    }
    Font symbolFont;
    if (!symbolFont.loadFromFile("Assets/Fonts/Rock_Salt/RockSalt-Regular.ttf"))
    {
        cout << "Error loading font" << endl;
        *scene = -1;
        return;
    }

    /* Loading the background and if failed to do so close the program */
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Assets/Backgrounds/Game_Screen_Background.jpg"))
    {
        cout << "Error loading background image\n";
        *scene = -1;
        return;
    }

    /* Beginning of declaring shapes and texts to use */
    RectangleShape background(Vector2f(800, 600));
    background.setTexture(&backgroundTexture);
    background.setPosition(Vector2f(0, 0));

    /* Invisable rectangles to make it easier to recognize the clicks */
    RectangleShape ulRec;
    ulRec.setSize(Vector2f(115, 86));
    ulRec.setPosition(Vector2f(200, 190));


    /* The text variables that'll house the X or O */
    Text ul("", symbolFont, 55);
    ul.setPosition(238, 195);


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
                if (ulRec.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y)) // 230x210-350x310 upper left
                {
                    cout << "Clicked on upper box\n";
                    if (game->isValidMove(0, 0))
                    {
                        cout << "Is a valid move\n";
                        if (game->isXsTurn())
                        {
                            game->placeMove('X', 0, 0);
                            ul.setString("X");
                            game->incrementMove();
                        }
                        else
                        {
                            game->placeMove('O', 0, 0);
                            ul.setString("O");
                            game->incrementMove();
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
                /*else if () //350x210-540x310 upper mid
                {

                }
                else if () //550x210-670x310 upper left 
                {

                }
                else if () //230x310-350x460 mid left
                {

                }
                else if () //360x310-540-460 mid
                {

                }
                else if () // 545x315-660x460 mid right
                {

                }
                else if () //230x460-360x570 lower left
                {

                }
                else if () //360x460-540x570 lower mid
                {

                }
                else if () //550x460-660x560 lower right 
                {

                }*/
            }
        }

        window->clear(Color::White);

        window->draw(background);
        
        if (ul.getString() != "")
            window->draw(ul);


        window->display();
    }
}