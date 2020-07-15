#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
#include "Framework/GameState.h"
#include "Framework/Vector.h"
#include "Framework/Input.h"

class Butterfly : public GameObject , public Vector , public Input , public Animation
{
public:
	Butterfly();
	~Butterfly();

	
 
	//choose animation
	void update(float dt) override;
	// register input and change position
	void handleInput(float dt);
	

	sf::Vector2f stepVelocity;
protected:
	
	float scale;
	bool isJumping;
	sf::Vector2f gravity;

	sf::Vector2f jumpVector;




	Animation glide;
	Animation flap;
	Animation* currentAnimation;

	

	
	

};

