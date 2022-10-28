#include "header.h"


class Wrapper
{
    public:
        Wrapper()
        {}
        ~Wrapper()
        {}


        void runAmongUs()
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
            t1.loadFromFile("extras/angel.png");


            sf::Sprite redAmongUs; 
            redAmongUs.setTexture(t1);
            // redAmongUs.setPosition(75,( 720 - t1.getSize().y) );
            // redAmongUs.setScale(0.01f, 0.01f);

            // player positon
            static const int PLAYER_BOTT = amongusWinHeight - t1.getSize().y; // bottom pos of player == window minus player height
            int numTimeObst = 0;
	        Position playerPos; playerPos.x = 75; // set player position relative to window
	        playerPos.y = PLAYER_BOTT; 

	        int index = 0; 
	        float frame = 0.f;
	        float frameSpeed = 0.8f; // 0.04
	        const int changeCount = 5; 

	        const int gravity = 6; // was 4
	        bool isJumping = false; 
	        bool isDown = true; // isDown tells if player has landed from jump. 
	        int jumpCount = 0; // count num of successful jumps, also determines which texture the obstacle has ! 
            //float velocity = 6;

            // position of object 
            static const int OBST_BOTT = t1.getSize().y; // get obstacle bottom (adjusted for now since obstacle is same size as player)
	        Position obstPos; 
	        obstPos.x = amongusWinWidth - 180; 
	        obstPos.y = PLAYER_BOTT ; 
	        const int obstacleSpeed = 6; 


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
			        t2.loadFromFile("extras/bingus-amongus.png");
		        }
		        else if (newSkin == 3 || newSkin == 9 || newSkin == 15) 
                {
			        t2.loadFromFile("extras/greenEnemy.png");
		        }
		        else if (newSkin == 5) 
                {
			        t2.loadFromFile("extras/redamongus.png");
		        }
		        else 
                {
			        t2.loadFromFile("extras/knife.png");
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
                if (obstPos.x >= 590)
                    numTimeObst++;
                
                if (isJumping) 
                {  // if peak of jump reached
			        playerPos.y -= gravity; // deacceleration from gravity is applied (decrement height by gravity)
		        }
		        else 
                { // if peak of jump not reached
			        playerPos.y += 4; // gravity does not act on player yet  (increment height by gravity)
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

		        obstacle1.setPosition(obstPos.x, obstPos.y - 40);   // set obstacle position
		        redAmongUs.setPosition(playerPos.x, playerPos.y - 70); // set player position

                if (isDown  && obstPos.x <= 100) 
		        { // if player overlapps obstacle on screen (collision)   
			        obstPos.x = 100; 
                    window.close();
                    scoreScreen(jumpCount);

                    // ending screen 

                }

                window.clear();
                window.draw(spaceShip);
                window.draw(redAmongUs);
                window.draw(obstacle1);
                window.display();
            }
                
        }

        void displayRules()
        {
            sf::RenderWindow window(sf::VideoMode(2880, 1324), " Jump For Your Life ! ", sf::Style::Close | sf::Style::Titlebar);

            // sets up font
            sf::Font font;
            font.loadFromFile("extras/MorningRainbow.ttf"); 

            // creates rules 
            sf::Text rules;
            rules.setFont(font);

            // rules 
            rules.setString("    Avoid being touched by \n the obstacles by jumping \n\t\t     over them!");
            rules.setCharacterSize( 165 );
            rules.setFillColor(sf::Color::Black);
            rules.setPosition(500, 300);
            // title.setOutlineColor(sf::Color::Black);
            // title.setOutlineThickness(7);

            // creates  
            sf::Text playGame;
            playGame.setFont(font);

            // rules 
            playGame.setString(" Click enter to start playing! ");
            playGame.setCharacterSize( 145 );
            playGame.setFillColor(sf::Color::Black);
            playGame.setPosition(500, 1000);



            // creating background
 	        sf::Texture texture;
 	        texture.loadFromFile("extras/mbackground.png");

 	        sf::Sprite backSprite;
 	        backSprite.setTexture(texture);

             while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                {
                    window.close();
                }

                window.clear();
                window.draw(backSprite);
                window.draw(rules);
                window.draw(playGame);
                window.display();
            }
        
        
        }

        void scoreScreen(int score)
        {
            
            sf::RenderWindow window(sf::VideoMode(2800, 1575), " Jump For Your Life ! ", sf::Style::Close | sf::Style::Titlebar);

            // sets up title font
            sf::Font font1;
            font1.loadFromFile("extras/MorningRainbow.ttf"); 

            // creates written exit 
            sf::Text wExit;
            wExit.setFont(font1);

            // text to be display  
            wExit.setString(" You died! Your Score is:");
            wExit.setCharacterSize( 140 );
            wExit.setFillColor(sf::Color::White);
            wExit.setPosition(560, 200);
            // title.setOutlineColor(sf::Color::Black);
            // title.setOutlineThickness(7);

            sf::Text dScore;
            dScore.setFont(font1);

            std::stringstream ss;
            ss << score;
            dScore.setString(ss.str().c_str());
            dScore.setCharacterSize( 600 );
            dScore.setFillColor(sf::Color::White);
            dScore.setPosition(1200, 400);

            // final written part
            sf::Text wExit2;
            wExit2.setFont(font1);

            // text to be display  
            wExit2.setString(" Click enter to exit");
            wExit2.setCharacterSize( 140 );
            wExit2.setFillColor(sf::Color::White);
            wExit2.setPosition(800, 1200);


            // creating background
 	        sf::Texture texture;
 	        texture.loadFromFile("extras/endscreen.png");

 	        sf::Sprite backSprite;
 	        backSprite.setTexture(texture);

             while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                {
                    window.close();
                }

                window.clear();
                window.draw(backSprite);
                window.draw(wExit);
                window.draw(dScore);
                window.draw(wExit2);
                window.display();

                
            }

            

        }

        void exitScreen()
        {
            sf::RenderWindow window(sf::VideoMode(2880, 1324), " Jump For Your Life ! ", sf::Style::Close | sf::Style::Titlebar);

            // sets up font
            sf::Font font;
            font.loadFromFile("extras/MorningRainbow.ttf"); 

            // creates title 
            sf::Text wexit;
            wexit.setFont(font);

            // question 
            wexit.setString(" Come back soon! ");

            wexit.setCharacterSize( 150 );
            wexit.setFillColor(sf::Color::Black);
            wexit.setPosition(860, 612);
            //title.setOutlineColor(sf::Color::Black);
            //title.setOutlineThickness(7);


            // creating background
 	        sf::Texture texture;
 	        texture.loadFromFile("extras/mbackground.png");

 	        sf::Sprite backSprite;
 	        backSprite.setTexture(texture);

            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                {
                    window.close();
                }

                window.clear();
                window.draw(backSprite);
                window.draw(wexit);
                window.display();
            }

        }

};

// void updateMovement(Sprite character)
		// {
        //     float x;
        //     float y;
		// 	if(y < 500)                  
        // 		velocityY += gravity;    
    	// 	else if(y > 500)             
        // 		y = 500;                 
		// 	velocityX += accelerationX;
    	// 	velocityY += accelerationY;
    	// 	x += velocityX;
    	// 	y += velocityY;
// } 