#pragma once
#include "Sprite.h"
#include "Timer.h"
class Bullet;

class Tank: public Sprite
{
public:
	Tank(string filename);
	~Tank();

	string m_filename;
	Timer timer;
	double m_velx;
	double m_vely;
	double m_velrotation=0;
	double frontx;
	double fronty;
	Bullet *bullet;
	bool isAlive;
	


	void tick();
	void draw();
	void setVel(double velX, double velY);
	void setVelRotation(double velRotation);
	bool getIsAlive();
	void setIsAlive(bool live);













	void shoot();
};
	