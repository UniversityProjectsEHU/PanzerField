#pragma once
#include "Sprite.h"
#include "Timer.h"
//class Timer;
class Tank: public Sprite
{
public:
	Tank();
	~Tank();

	Timer timer;
	double m_velx;
	double m_vely;



	void tick();
	void setVel(double velX, double velY);













};
	