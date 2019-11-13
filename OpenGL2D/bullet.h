#pragma once
#include "Timer.h"
#include "Sprite.h"

class Sprite;

class Bullet: public Sprite
{
public:
	Bullet();
	~Bullet();

	Timer timer;
	double m_velx;
	double m_vely;
	

	void tick();
	void draw();
	void setVel(double velX, double velY);
};