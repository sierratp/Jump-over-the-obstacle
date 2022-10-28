
#include "header.h"
#include "menu.h"

#include "wrapper.h"



int main(void)
{
    int pageNumber;

    sf::RenderWindow window(sf::VideoMode(2880, 1324), " Jump For Your Life ! ", sf::Style::Close | sf::Style::Titlebar);

    // sets up font
    sf::Font font;
    font.loadFromFile("extras/MorningRainbow.ttf"); 

    // creates title 
    sf::Text title;
    title.setFont(font);

    // question 
    title.setString(" Jump for Your Life! ");

    title.setCharacterSize( 150 );
    title.setFillColor(sf::Color::Black);
    title.setPosition(860, 50);
    //title.setOutlineColor(sf::Color::Black);
    //title.setOutlineThickness(7);


    // creating background
 	sf::Texture texture;
 	texture.loadFromFile("extras/mbackground.png");

 	sf::Sprite backSprite;
 	backSprite.setTexture(texture);

    // size of menu background
    Menu menu(2880,1324);

    // objects created
    Wrapper app;

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyReleased)
            {
                // move up
                if (event.key.code == sf::Keyboard::Up)
                {
                    menu.moveUp();
                    break;
                }
                // move down
                if (event.key.code == sf::Keyboard::Down)
                {
                    menu.moveDown();
                    break;
                }
                // changes page based on choice
                if (event.key.code == sf::Keyboard::Return)
                {

                    // among us theme
                    if (menu.mainMenuPressed() == 0)
                    {
                        window.close();
                        pageNumber = 0;
                    }
                    // rules
                    if (menu.mainMenuPressed() == 1)
                    {
                        window.close();
                        pageNumber = 1;
                    }
                    // exit 
                    if (menu.mainMenuPressed() == 2)
                    {
                        window.close();
                        pageNumber = 2;
                    } 

                           
                }


            }

        }

        window.clear();
        window.draw(backSprite);
        window.draw(title);
        menu.draw(window);
        window.display();
    
    }

    //pageNumber = dMenu.displayMenu();

    // ************** among us theme ****************
    if (pageNumber == 0)
    {
        app.runAmongUs();
    }

    // rules 
    if (pageNumber == 1)
    {
        app.displayRules();
        app.runAmongUs();

    }

    // exit
    if (pageNumber == 2)
    {
        app.exitScreen();
    }


    
  
    

}

