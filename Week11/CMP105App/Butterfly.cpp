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
	flap.setFrameSpeed(1.f / 35.f);
	//default animation is the glide frame
	currentAnimation = &glide;
	setTextureRect(currentAnimation->getCurrentFrame());

	//scale for the gravity 
	scale = 100.0f;
	//creating gravity 
	gravity = sf::Vector2f(0, 9.8f) * scale;
	//scale for the jump
	jumpVector = sf::Vector2f(0, -3.0f) * scale;
	//by default butterfly is not flapping
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
			//when space is pressed replaces gravity value with jump value
			stepVelocity = jumpVector;
		
		}
	}
}




void Butterfly::update(float dt)
{
	//******All gravity stuff******

	//Apply gravity force, increasing velocity
	stepVelocity += gravity * dt;
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	setPosition(getPosition() + pos);



	//******Setting animation to keyboard input******
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




