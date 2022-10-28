#pragma once
#include "header.h"

#define Max_main_menu 3

class Menu
{
    public: 
        // constructor / destructor
        Menu(float width, float height);
        ~Menu();

        // other member functions 
        //int sum(int x, int y);

        void draw(sf::RenderWindow &window);
        void moveUp();
        void moveDown();
        int mainMenuPressed();
        //int displayMenu();

    private:
        int mainMenuSelected;
        sf::Font font;
        sf::Text mainMenu[Max_main_menu];


};


Menu::Menu(float width, float height)
{
   font.loadFromFile("extras/MorningRainbow.ttf");

   // among us 
   mainMenu[0].setFont(font); 
   mainMenu[0].setColor(sf::Color(174,158,255));
   mainMenu[0].setString("Among Us");
   mainMenu[0].setCharacterSize(70);
   mainMenu[0].setPosition(sf::Vector2f(width / 2 - 100, height / (Max_main_menu + 1)));

   // rules
   mainMenu[1].setFont(font); 
   mainMenu[1].setColor(sf::Color::Black);
   mainMenu[1].setString("Rules");
   mainMenu[1].setCharacterSize(70);
   mainMenu[1].setPosition(sf::Vector2f(width / 2 - 100, height / (Max_main_menu + 1) * 2 ));

    // exit
   mainMenu[2].setFont(font); 
   mainMenu[2].setColor(sf::Color::Black);
   mainMenu[2].setString("Exit");
   mainMenu[2].setCharacterSize(70);
   mainMenu[2].setPosition(sf::Vector2f(width / 2 - 100, height / (Max_main_menu + 1) * 3));


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

// int Menu::displayMenu()
// {
//     Menu menu;
//     int pageNumber;
//     sf::RenderWindow window(sf::VideoMode(2880, 1324), " Jump For Your Life ! ", sf::Style::Close | sf::Style::Titlebar);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
            
//             if (event.type == sf::Event::KeyReleased)
//             {
//                 // move up
//                 if (event.key.code == sf::Keyboard::Up)
//                 {
//                     menu.moveUp();
//                     break;
//                 }
//                 // move down
//                 if (event.key.code == sf::Keyboard::Down)
//                 {
//                     menu.moveDown();
//                     break;
//                 }
//                 // changes page based on choice
//                 if (event.key.code == sf::Keyboard::Return)
//                 {

//                     // among us theme
//                     if (menu.mainMenuPressed() == 0)
//                     {
//                         window.close();
//                         pageNumber = 0;
//                     }
//                     // rules
//                     if (menu.mainMenuPressed() == 1)
//                     {
//                         window.close();
//                         pageNumber = 1;
//                     }
//                     // exit 
//                     if (menu.mainMenuPressed() == 2)
//                     {
//                         window.close();
//                         pageNumber = 2;
//                     }           
//                 }


//             }

//         }

//         menu.draw(window);

    
//     }
// }