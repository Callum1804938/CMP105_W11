#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;


	// initialise game objects

	//Adding music
	audio->addMusic("sfx/mysticalWoods.ogg", "mystical");
	audio->addSound("sfx/wing flaps.ogg", "flap");
	audio->addSound("sfx/caught.ogg", "caught");
	audio->addSound("sfx/boundaryDeath.wav", "boundary");

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

	//Score 
	
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
	//input to pause game
	if (input->isKeyDown(sf::Keyboard::P))
	{
		audio->stopAllMusic();
		gameState->setCurrentState(State::PAUSE);
		input->setKeyUp(sf::Keyboard::P);
	
	}
	//Adding jump sound to space key
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		audio->playSoundbyName("flap");
		

	}
}

// Update game objects
void Level::update(float dt)
{
	//update window size 
	sf::Vector2u pos = window->getSize();

	//update sprite sizes to fit in new window
	
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));

	butterfly.setSize(sf::Vector2f(window->getSize().x / 12.f, window->getSize().y / 6.75));

	for (int i = 0; i < 6; i++)
	{
		net[i].setSize(sf::Vector2f(window->getSize().x / 7.5, window->getSize().y / 4.2));
	}
	
	//Butterfly.cpp update file
	butterfly.update(dt);
	//setting boundaries for butterfly to cause death
	
	if (butterfly.getPosition().y < -60)
	{
		audio->playSoundbyName("boundary");
		gameState->setCurrentState(State::DEATH);
		audio->stopAllMusic();
		
	}

	if (butterfly.getPosition().y >= (window->getSize().y - 70))
	{
		audio->playSoundbyName("boundary");
		gameState->setCurrentState(State::DEATH);
		audio->stopAllMusic();

	}


	//net speeds
	speed = window-> getSize().x/5.f;//formula to ensure speed moved at correct speed if window changes size
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


	//Checking butterfly-net collisions
	for (int i = 0; i < 6; i++)
	{
		if (Collision::checkBoundingBox(&butterfly, &net[i]))
		{
			audio->playSoundbyName("caught");
			gameState->setCurrentState(State::DEATH);
			audio->stopAllMusic();
			
		}
	}
	//Adding music to game
	if (audio->getMusic()->getStatus() == sf::SoundSource::Stopped && gameState->getCurrentState() != State::PAUSE)
	{
		audio->playMusicbyName("mystical");
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

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to black.
void Level::beginDraw()
{
	switch (gameState->getCurrentState())
	{
	case(State::LEVEL):
		window->clear(sf::Color::Black);
		break;
	}
}
// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}