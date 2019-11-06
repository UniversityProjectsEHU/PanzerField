#pragma once

class Sprite;

class bullet: public Sprite
{
	Sprite *pSprite;
	double velx;
	double vely;

public:
	bullet();
	~bullet();

	void tick();
};

