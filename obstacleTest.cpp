#include "header.h"

// tests sofias code with new obstacle generating functions
int main()
{
    // window size
    int amongusWinHeight = 720;
    int amongusWinWidth = 1280;

    sf::RenderWindow window(sf::VideoMode(amongusWinWidth,amongusWinHeight),"Among US");
    window.setFramerateLimit(60);

    // creating background
 	sf::Texture SS;
    SS.loadFromFile("extras/spaceBackground2.png");

 	sf::Sprite spaceShip;
 	spaceShip.setTexture(SS);

    // character sprite
    sf::Texture t1;
    t1.loadFromFile("extras/redamongus.png");


    sf::Sprite redAmongUs; 
    redAmongUs.setTexture(t1);
    // redAmongUs.setPosition(75,( 720 - t1.getSize().y) );
    // redAmongUs.setScale(0.01f, 0.01f);

// ******************************
static const int PLAYER_BOTT = amongusWinHeight - t1.getSize().y; // bottom pos of player == window minus player height

	Position playerPos; playerPos.x = 75; // set player position relative to window
	playerPos.y = PLAYER_BOTT; 

	int index = 0; 
	float frame = 0.f;
	float frameSpeed = 0.4f;
	const int changeCount = 5; 

	const int gravity = 4; // was 5
	bool isJumping = false; 
	bool isDown = true; // isDown tells if player has landed from jump. 
	int jumpCount = 0; // count num of successful jumps, also determines which texture the obstacle has ! 
//*******************************

// ******************************
static const int OBST_BOTT = t1.getSize().y; // get obstacle bottom (adjusted for now since obstacle is same size as player)
	Position obstPos; 
	obstPos.x = amongusWinWidth - 1180; 
	obstPos.y = PLAYER_BOTT; 
	const int obstacleSpeed = 4; 
// ************************************


    while (window.isOpen())
    {
        //Events
        sf::Event event;
        while(window.pollEvent(event))
		{
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
                // changes enemy based on jump sequence
                int newSkin = jumpCount + 1; 
		        sf::Texture t2;
                

		        if (newSkin % 2 == 0) 
                { 
			        t2.loadFromFile("extras/orangeKnife.png");
		        }
		        else if (newSkin == 3 || newSkin == 9 || newSkin == 15) 
                {
			        t2.loadFromFile("extras/amogusPolice.png");
		        }
		        else if (newSkin == 5) 
                {
			        t2.loadFromFile("extras/bingus-amongus.png");
		        }
		        else 
                {
			        t2.loadFromFile("extras/amogusBoba.png");
		        }

                sf::Sprite obstacle1;
                obstacle1.setTexture(t2);
                obstacle1.setPosition(1200, 720 - t1.getSize().y);
                obstacle1.setScale(1.6f,1.6f);
		    
                //if(event.type==Event::sf::KeyPressed && event.key.code==sf::Keyboard::Space)
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			    {
                    if (isDown && !isJumping)
                    {
                        //velocityY = -10;
                        isJumping = true;
                        isDown = false;
                        jumpCount++;
                    }
                }
                
               if (isJumping) {  // if peak of jump reached
			playerPos.y -= gravity; // deacceleration from gravity is applied (decrement height by gravity)
		}
		else { // if peak of jump not reached
			playerPos.y += 3; // gravity does not act on player yet  (increment height by gravity)
		}
		if (playerPos.y >= PLAYER_BOTT) { // do not go down further than player's default position
			playerPos.y = PLAYER_BOTT; // height of player == default 'bottom' position 
			isDown = true; // is touching floor
		}
		if (playerPos.y <= PLAYER_BOTT - 100) {
			isJumping = false; 
		} 
            
                //updateMovement(redAmongUs);
                //redAmongUs.setPosition(x, y);

                // move obstacles
		        if (obstPos.x <= 0) 
                { // (x == width, y == height in SFML) 
			        obstPos.x = amongusWinWidth; 
		        }
		        else 
                { 
                    obstPos.x -= obstacleSpeed;  
                } // move left 

		        obstacle1.setPosition(obstPos.x, obstPos.y);   // set obstacle position
		        redAmongUs.setPosition(playerPos.x, playerPos.y); // set player position

  


                window.clear();
                window.draw(spaceShip);
                window.draw(redAmongUs);
                window.draw(obstacle1);
                window.display();
    }
                


}