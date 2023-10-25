#include "Game.h"
int main()
{

    sf::RenderWindow window(sf::VideoMode(900, 800), "123123", sf::Style::Default);

    window.setVerticalSyncEnabled(true);
    Game game;

    game.Initialize();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        game.loop(window);
        window.display();
    }
    return 0;
}