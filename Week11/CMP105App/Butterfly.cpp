#include "Butterfly.h"

Butterfly::Butterfly()
{
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
	flap.setFrameSpeed(1.f / 10.f);
}


void Butterfly::update(float dt)
{
	flap.animate(dt);
	setTextureRect(flap.getCurrentFrame());
}
