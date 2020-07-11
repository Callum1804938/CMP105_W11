#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Vector.h"
#include "Framework/Input.h"

class Butterfly : public GameObject , public Vector , public Input
{
public:
	Butterfly();
	~Butterfly();

	
 
	//choose animation
	void update(float dt) override;
	// register input and change position
	void handleInput(float dt);
	
	//sf::RenderWindow* window;

protected:

	Animation glide;
	Animation flap;
	Animation* currentAnimation;

	//Hitbox

	
	

};

