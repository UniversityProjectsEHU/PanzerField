#pragma once
#include "Timer.h"
#include "Sprite.h"

class Sprite;

class Bullet: public Sprite
{
public:
	Bullet(string filename);
	~Bullet();

	Timer timer;
	double m_velx;
	double m_vely;
	bool isalive;

	void tick();
	void draw();
	void setVel(double velX, double velY);
	void setAlive();
	bool getisAlive();
};