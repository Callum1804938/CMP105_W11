#pragma once
#include "Framework/GameObject.h"
#include"Framework/Vector.h"



class Net : public GameObject , public Vector
{
public:
	Net();
	~Net();

	void netUpdate(float dt);

protected:
	





};

