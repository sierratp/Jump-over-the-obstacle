#include "header.h"



int main()
{
    RenderWindow window(VideoMode(2030,780),"jump tester");
    window.setFramerateLimit(60);

    // creating background
 	sf::Texture OBG;
 	OBG.loadFromFile("extras/background.png");

 	sf::Sprite oceanBG;
 	oceanBG.setTexture(OBG);


    // crab sprite
    sf::Texture ctexture;
    ctexture.loadFromFile("extras/crab.png");

    sf::Sprite crab;
    crab.setTexture(ctexture);
    crab.setPosition(-230,100);

    // diver sprite
    sf::Texture dtexture;
    dtexture.loadFromFile("extras/diver.png");

    sf::Sprite diver;
    diver.setTexture(dtexture);
    diver.setPosition(-230,100);

    // Player player1;


	while (window.isOpen())
    {
        //Eventos
        sf::Event event;
        while(window.pollEvent(event))
		{
            if (event.type == Event::Closed){
                window.close();
            }
            else if(event.type==Event::KeyPressed && event.key.code==Keyboard::Space)
			{
                velocityY = -10;
            }
        }

        // moves character 
        // if(Keyboard::isKeyPressed(Keyboard::Left))
        //     velocityX = -5;
        // else if(Keyboard::isKeyPressed(Keyboard::Right))
        //     velocityX = 5;
            
        updateMovement(diver);
        diver.setPosition(x, y);
            
        //Renderizado
        window.clear();
        window.draw(oceanBG);
        window.draw(diver);
        window.display();
    }

}
	