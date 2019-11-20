#pragma once
#include "Sprite.h"
#include "Timer.h"

class TankEnemy : public Sprite
{
public:
	TankEnemy();
	~TankEnemy();

	Timer timer;
	double m_velx;
	double m_vely;
	double m_velrotation = 0;
	double frontx;
	double fronty;



	void tick();
	void draw();
	void setVel(double velX, double velY);
	void setVelRotation(double velRotation);













	void shoot();
};
