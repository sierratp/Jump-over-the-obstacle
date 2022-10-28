#include "header.h"

class Test
{
    public:
        Test() {}
        ~Test() {}

        void testSprites()
        {
            sf::RenderWindow window(sf::VideoMode(2030,780),"test sprites");
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
            crab.setPosition(200,360);
            crab.setScale(0.3f, 0.3f);

            // diver sprite
            sf::Texture dtexture;
            dtexture.loadFromFile("extras/diver.png");

            sf::Sprite diver;
            diver.setTexture(dtexture);
            diver.setPosition(1000,160);
            diver.setScale(0.7f, 0.7f);

            while (window.isOpen())
            {
                //Eventos
                sf::Event event;
                while(window.pollEvent(event))
		        {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                window.clear();
                window.draw(oceanBG);
                window.draw(crab);
                window.draw(diver);
                window.display();
            
            }

        }

        void testjump()
        {
            sf::RenderWindow window(sf::VideoMode(600,600)," test jump ");
             window.setFramerateLimit(60);

            // character sprite
            sf::Texture t1;
            t1.loadFromFile("extras/redamongus.png");

            sf::Sprite redAmongUs; 
            redAmongUs.setTexture(t1);
            // redAmongUs.setPosition(75,( 720 - t1.getSize().y) );
            // redAmongUs.setScale(0.01f, 0.01f);

            // ******************************
            static const int PLAYER_BOTT = 600 - t1.getSize().y; // bottom pos of player == window minus player height

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
                
                if (isJumping) 
                {  // if peak of jump reached
			        playerPos.y -= gravity; // deacceleration from gravity is applied (decrement height by gravity)
		        }
		        else 
                { // if peak of jump not reached
			        playerPos.y += 3; // gravity does not act on player yet  (increment height by gravity)
		        }
		        if (playerPos.y >= PLAYER_BOTT) 
                { // do not go down further than player's default position
			        playerPos.y = PLAYER_BOTT; // height of player == default 'bottom' position 
			        isDown = true; // is touching floor
		        }
		        if (playerPos.y <= PLAYER_BOTT - 100) 
                {
			        isJumping = false; 
		        } 
        
		        redAmongUs.setPosition(playerPos.x, playerPos.y); // set player position

                window.clear();
                window.draw(redAmongUs);
                window.display();
            }
                
        }

        void testObstacle()
        {
             
            sf::RenderWindow window(sf::VideoMode(600,600),"test obstacle");
            window.setFramerateLimit(60);


            static const int OBST_BOTT = 400; // get obstacle bottom (adjusted for now since obstacle is same size as player)
	        Position obstPos; 
	        obstPos.x = 300; 
	        obstPos.y = 400; 
	        const int obstacleSpeed = 4; 

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
                
		        sf::Texture t2;
                t2.loadFromFile("extras/knife.png");

                sf::Sprite obstacle1;
                obstacle1.setTexture(t2);

                // move obstacles
		        if (obstPos.x <= 0) 
                { // (x == width, y == height in SFML) 
			        obstPos.x = 600; 
		        }
		        else 
                { 
                    obstPos.x -= obstacleSpeed;  
                } // move left 

		        obstacle1.setPosition(obstPos.x, obstPos.y);   // set obstacle position

                window.clear();
                window.draw(obstacle1);
                window.display();
            }   
               
        }



};