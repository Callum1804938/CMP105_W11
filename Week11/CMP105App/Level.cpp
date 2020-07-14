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
	if (!backgroundTexture.loadFromFile("background/pixelbackground.jpg"))
	{
		std::cout << "could not load background file.";
	}
	background.setTexture(&backgroundTexture);
	background.setPosition(0, 0);


	//Butterfly Object
	if (!butterflyTexture.loadFromFile("butterfly/butterfly side sprite strip.png"))
	{
		std::cout << "butterfly sprite sheet failed to load.";
	}
	
	butterfly.setPosition((window->getSize().x / 4) - 35, (window->getSize().y / 3));
	butterfly.setCollisionBox(sf::FloatRect(20, 20, 60, 60));
	butterfly.setTexture(&butterflyTexture);
	butterfly.setInput(input);

	//Obsticles
	if (!netTexture.loadFromFile("butterfly net/Butterfly net.png"))
	{
		std::cout << "could not load net sprite.";
	}
	net1.setTexture(&netTexture);
	net1.setCollisionBox(sf::FloatRect(5, 0, 25, 160));
	net1.setPosition((window->getSize().x) + 65, 300);
	
	net2.setTexture(&netTexture);
	net2.setCollisionBox(sf::FloatRect(5, 0, 25, 160));
	net2.setPosition((window->getSize().x) + 315, 50);

	net3.setTexture(&netTexture);
	net3.setCollisionBox(sf::FloatRect(5, 0, 25, 160));
	net3.setPosition((window->getSize().x) + 540, 200);

	net4.setTexture(&netTexture);
	net4.setCollisionBox(sf::FloatRect(5, 0, 25, 160));
	net4.setPosition((window->getSize().x) + 785, 500);

	net5.setTexture(&netTexture);
	net5.setCollisionBox(sf::FloatRect(5, 0, 25, 160));
	net5.setPosition((window->getSize().x) + 1020, 100);

	net6.setTexture(&netTexture);
	net6.setCollisionBox(sf::FloatRect(5, 0, 25, 160));
	net6.setPosition((window->getSize().x) + 1255, 400);


	//Loading Font file
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "failure to load font file" << std::endl;
	}
	//Game Title
	game_title.setFont(font);
	game_title.setString("A Shameless Copy");
	game_title.setCharacterSize(30);
	game_title.setFillColor(sf::Color::Black);
	game_title.setStyle(sf::Text::Bold);
	game_title.setPosition(0, 0);
	
	//Instructions
	instructions.setFont(font);
	instructions.setString("Press Enter to flap\nAvoid those nets!");
	instructions.setCharacterSize(20);
	instructions.setFillColor(sf::Color::Black);
	instructions.setPosition(0, 35);

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
	butterfly.setSize(sf::Vector2f(window->getSize().x / 12, window->getSize().y / 6.75));
	net1.setSize(sf::Vector2f(window->getSize().x / 7.5, window->getSize().y / 4.2));
	net2.setSize(sf::Vector2f(window->getSize().x / 7.5, window->getSize().y / 4.2));
	net3.setSize(sf::Vector2f(window->getSize().x / 7.5, window->getSize().y / 4.2));
	net4.setSize(sf::Vector2f(window->getSize().x / 7.5, window->getSize().y / 4.2));
	net5.setSize(sf::Vector2f(window->getSize().x / 7.5, window->getSize().y / 4.2));
	net6.setSize(sf::Vector2f(window->getSize().x / 7.5, window->getSize().y / 4.2));
	
	//Butterfly.cpp update file
	butterfly.update(dt);

	//net speeds
	speed = 100.f;
	net1.move(-speed * dt, 0);
	net2.move(-speed * dt, 0);
	net3.move(-speed * dt, 0);
	net4.move(-speed * dt, 0);
	net5.move(-speed * dt, 0);
	net6.move(-speed * dt, 0);

	//creating random number between y axis boundaries to randomise the position of the different nets
	randYPos = rand() % (window->getSize().y - 170) + 30;
	//if statements to loop nets endlessly 
	if (net1.getPosition().x < -160)
	{
		net1.setPosition(window->getSize().x + 65, randYPos);
	}
	if (net2.getPosition().x < -160)
	{
		net2.setPosition(window->getSize().x + 65, randYPos);
	}
	if (net3.getPosition().x < -160)
	{
		net3.setPosition(window->getSize().x + 65, randYPos);
	}
	if (net4.getPosition().x < -160)
	{
		net4.setPosition(window->getSize().x + 65, randYPos);
	}
	if (net5.getPosition().x < -160)
	{
		net5.setPosition(window->getSize().x + 65, randYPos);
	}
	if (net6.getPosition().x < -160)
	{
		net6.setPosition(window->getSize().x + 65, randYPos);
	}
	//Checking collisions
	if (Collision::checkBoundingBox(&butterfly, &net1))
	{
		std::cout << "collision!!";
		butterfly.collisionResponse(NULL);
		net1.move(0, 0);
	}
	if (Collision::checkBoundingBox(&butterfly, &net2))
	{
		std::cout << "collision!!";
		butterfly.collisionResponse(NULL);
		speed = 0.f;
	}
	if (Collision::checkBoundingBox(&butterfly, &net3))
	{
		std::cout << "collision!!";
		butterfly.collisionResponse(NULL);
		speed = 0.f;
	}
	if (Collision::checkBoundingBox(&butterfly, &net4))
	{
		std::cout << "collision!!";
		butterfly.collisionResponse(NULL);
		speed = 0.f;
	}
	if (Collision::checkBoundingBox(&butterfly, &net5))
	{
		std::cout << "collision!!";
		butterfly.collisionResponse(NULL);
		speed = 0.f;
	}
	if (Collision::checkBoundingBox(&butterfly, &net6))
	{
		std::cout << "collision!!";
		butterfly.collisionResponse(NULL);
		speed = 0.f;
	}

}

// Render level
void Level::render()
{
	beginDraw();
	//thing to draw go here
	
	window->draw(background);

	window->draw(butterfly);

	window->draw(net1);
	window->draw(net2);
	window->draw(net3);
	window->draw(net4);
	window->draw(net5);
	window->draw(net6);

	window->draw(game_title);

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