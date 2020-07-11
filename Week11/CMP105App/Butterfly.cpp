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
	//defalut animation is the glide frame
	currentAnimation = &glide;
	setTextureRect(currentAnimation->getCurrentFrame());

	//Gravity stuff
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;


}
Butterfly::~Butterfly()
{

}

void Butterfly::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}
}


void Butterfly::update(float dt)
{
	//all gravity stuff

		//Apply gravity force, increasing velocity
	//Move shape by new velocity

	stepVelocity += gravity * dt;
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	setPosition(getPosition() + pos);

	if (getPosition().y >= 500)
	{
		isJumping = false;
		setPosition(getPosition().x, 500);
		stepVelocity = sf::Vector2f(0, 0);

	}
	



	//all animation stuff
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::Space))
	{
		
		currentAnimation = &flap;
		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());
		
	
	}
	else
	{
		currentAnimation = &glide;
		setTextureRect(currentAnimation->getCurrentFrame());
		
	}

}




