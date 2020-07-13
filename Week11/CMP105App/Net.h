#pragma once
#include "Framework/GameObject.h"
#include"Framework/Vector.h"

class Net : public GameObject , public Vector
{
public:
	Net();
	~Net();

	void update(float dt) override;

protected:




};

