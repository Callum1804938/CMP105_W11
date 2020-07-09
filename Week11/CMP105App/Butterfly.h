#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Butterfly : public GameObject
{
public:
	Butterfly();
	
	void update(float dt) override;

protected:
	Animation flap;

};

