#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "plansza.h"
#include "GameManager.h"
#include "Intro.h"
#include "Score.h"
#include "bitwa.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    sf::RenderWindow app(sf::VideoMode(800, 800), "SFML window");
    plansza p;
    Intro intro;
    Score score;
    bitwa b(3,3);
    srand(time(NULL));

    GameManager gm(intro, score, p, b);

    while (app.isOpen())
    {
        // Process events
        sf::Event event;

        //gm.handleEvent(event);

        gm.handleEvent2(event);

        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
            //b.handleEvent(event);
            gm.handleEvent(event);

        }
        // Clear screen
        app.clear();

        // Draw the sprite
        //b.draw(app);
        gm.draw(app);

        // Update the window
        app.display();

    }
    return 0;
}