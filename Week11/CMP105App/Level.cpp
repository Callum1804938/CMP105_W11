#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");

	//Adding background
	if (!backgroundTexture.loadFromFile("gfx/pixelbackground.jpg"))
	{
		std::cout << "could not load background file.";
	}
	background.setTexture(&backgroundTexture);
	background.setPosition(0, 0);


	//Butterfly Object
	if (!butterflyTexture.loadFromFile("gfx/butterfly side sprite strip.png"))
	{
		std::cout << "butterfly sprite sheet failed to load.";
	}
	
	butterfly.setPosition((window->getSize().x / 4.f) - 35.f, (window->getSize().y / 3.f));
	butterfly.setCollisionBox(sf::FloatRect(20, 20, 60, 60));
	butterfly.setTexture(&butterflyTexture);
	butterfly.setInput(input);

	//Net Object
	if (!netTexture.loadFromFile("gfx/Butterfly net.png"))
	{
		std::cout << "could not load net sprite.";
	}
	for (int i = 0; i < 6; i++)
	{
		net[i].setTexture(&netTexture);
		net[i].setCollisionBox(sf::FloatRect(12, 0, 25, 160));
	}
	net[0].setPosition((window->getSize().x) + 65.f, 300);
	net[1].setPosition((window->getSize().x) + 315.f, 50);
	net[2].setPosition((window->getSize().x) + 540.f, 200);
	net[3].setPosition((window->getSize().x) + 785.f, 500);
	net[4].setPosition((window->getSize().x) + 1020.f, 100);
	net[5].setPosition((window->getSize().x) + 1255.f, 400);


	//Loading Font file
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "failure to load font file" << std::endl;
	}
	//Game Title
	gameTitle.setFont(font);
	gameTitle.setString("A Shameless Copy");
	gameTitle.setCharacterSize(30);
	gameTitle.setFillColor(sf::Color::Black);
	gameTitle.setStyle(sf::Text::Bold);
	gameTitle.setPosition(0, 0);
	
	//Instructions
	instructions.setFont(font);
	instructions.setString("Press Enter to flap\nAvoid those nets!");
	instructions.setCharacterSize(20);
	instructions.setFillColor(sf::Color::Black);
	instructions.setPosition(0, 35);

	//Game Over
	gameOver.setFont(font);
	gameOver.setString("GAME OVER!");
	gameOver.setCharacterSize(20);
	gameOver.setFillColor(sf::Color::Red);

	//DeathScreen




	//score

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	butterfly.handleInput(dt);

	//input to close window 
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

}

// Update game objects
void Level::update(float dt)
{
	//update window size 
	sf::Vector2u pos = window->getSize();

	//update sprite sizes to fit in new window
	
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	
	deathScreen.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));

	butterfly.setSize(sf::Vector2f(window->getSize().x / 12.f, window->getSize().y / 6.75));



	for (int i = 0; i < 6; i++)
	{
		net[i].setSize(sf::Vector2f(window->getSize().x / 7.5, window->getSize().y / 4.2));
	}
	
	//Butterfly.cpp update file
	butterfly.update(dt);


	//setting boundaries for butterfly
	
	if (butterfly.getPosition().y <  - 30)
	{

		butterfly.setPosition(butterfly.getPosition().x,  - 30);
		butterfly.stepVelocity = sf::Vector2f(0, 0);
	}

	if (butterfly.getPosition().y >= (window->getSize().y - 70))
	{

		butterfly.setPosition(butterfly.getPosition().x, (window->getSize().y - 70));
		butterfly.stepVelocity = sf::Vector2f(0, 0);

	}

	//net speeds
	speed = 250.f;
	for (int i = 0; i < 6; i++)
	{
		net[i].move(-speed * dt, 0);
	}

	//creating random number between y axis boundaries to randomise the position of the different nets
	randYPos = rand() % (window->getSize().y - 170) + 30;
	//Loop the nets across the screen
	for (int i = 0; i < 6; i++)
	{
		if (net[i].getPosition().x < -160)
		{
			net[i].setPosition(window->getSize().x + 65, randYPos);
		}
	}



	//Checking collisions
	for (int i = 0; i < 6; i++)
	{
		if (Collision::checkBoundingBox(&butterfly, &net[i]))
		{
			butterfly.collisionResponse(NULL);
		}
	}

}

// Render level
void Level::render()
{
	beginDraw();
	//thing to draw go here
	
	window->draw(background);

	window->draw(butterfly);

	for (int i = 0; i < 6; i++)
	{
		window->draw(net[i]);
	}

	window->draw(gameTitle);

	window->draw(instructions);



	

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color::Black);
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}