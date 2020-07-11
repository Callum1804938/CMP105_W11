#include "Butterfly.h"


Butterfly::Butterfly()
{
	//Glide animation 
	glide.addFrame(sf::IntRect(0, 0, 70, 65));


	//Set up flap animation
	flap.addFrame(sf::IntRect(0, 0, 70, 65));
	flap.addFrame(sf::IntRect(70, 0, 70, 65));
	flap.addFrame(sf::IntRect(140, 0, 70, 65));
	flap.addFrame(sf::IntRect(210, 0, 70, 65));
	flap.addFrame(sf::IntRect(280, 0, 70, 65));
	flap.addFrame(sf::IntRect(350, 0, 70, 65));
	flap.addFrame(sf::IntRect(420, 0, 70, 65));
	flap.addFrame(sf::IntRect(490, 0, 70, 65));
	flap.addFrame(sf::IntRect(560, 0, 70, 65));
	flap.addFrame(sf::IntRect(630, 0, 70, 65));
	flap.addFrame(sf::IntRect(700, 0, 70, 65));
	flap.addFrame(sf::IntRect(770, 0, 70, 65));
	flap.addFrame(sf::IntRect(840, 0, 70, 65));
	flap.addFrame(sf::IntRect(910, 0, 70, 65));
	flap.addFrame(sf::IntRect(910, 0, 70, 65));
	flap.setFrameSpeed(1.f / 30.f);

	currentAnimation = &glide;
	setTextureRect(currentAnimation->getCurrentFrame());


}
Butterfly::~Butterfly()
{

}

void Butterfly::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		move(sf::Vector2f(0, -velocity.y) * dt);
	}


}



void Butterfly::update(float dt)
{
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::Space))
	{
		
		currentAnimation = &flap;
		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());
		
		//input->setKeyUp(sf::Keyboard::Space);
	}
	else
	{
		currentAnimation = &glide;
		setTextureRect(currentAnimation->getCurrentFrame());
		
	}

}




