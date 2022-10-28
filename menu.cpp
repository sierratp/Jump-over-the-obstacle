#include "header.h"
#include "menu.h"

#define Max_main_menu 3

Menu::Menu(float width, float height)
{
   font.loadFromFile("extras/MorningRainbow.ttf");

   // among us 
   mainMenu[0].setFont(font); 
   mainMenu[0].setColor(sf::Color(174,158,255));
   mainMenu[0].setString("Among Us");
   mainMenu[0].setCharacterSize( 500 );
   mainMenu[0].setPosition(sf::Vector2f(width / 2 - 200, height / (Max_main_menu + 1)));

   // rules
   mainMenu[1].setFont(font); 
   mainMenu[1].setColor(sf::Color::Black);
   mainMenu[1].setString("Rules");
   mainMenu[1].setCharacterSize( 500 );
   mainMenu[1].setPosition(sf::Vector2f(width / 2 - 200, height / (Max_main_menu + 1) * 2 ));

    // exit
   mainMenu[2].setFont(font); 
   mainMenu[2].setColor(sf::Color::Black);
   mainMenu[2].setString("Exit");
   mainMenu[2].setCharacterSize( 500 );
   mainMenu[2].setPosition(sf::Vector2f(width / 2 - 200, height / (Max_main_menu + 1) * 3));


   mainMenuSelected = 0;
}


Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 3; i++)
    {
        window.draw(mainMenu[i]);
    }

}

void Menu::moveDown()
{
    if (mainMenuSelected + 1 <= Max_main_menu)
    {
        mainMenu[mainMenuSelected].setColor(sf::Color::Black);

        mainMenuSelected++;

        if (mainMenuSelected == 3)
        {
            mainMenuSelected = 0;
        }

        mainMenu[mainMenuSelected].setColor(sf::Color(174,158,255));
    }
}

void Menu::moveUp()
{
    if (mainMenuSelected -1 >= -1)
    {
        mainMenu[mainMenuSelected].setColor(sf::Color::Black);

        mainMenuSelected--;

        if (mainMenuSelected == -1)
        {
            mainMenuSelected = 2;
        }

        mainMenu[mainMenuSelected].setColor(sf::Color(174,158,255));
    }

}

int Menu::mainMenuPressed()
{
    return mainMenuSelected;
}
