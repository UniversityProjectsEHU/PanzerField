#include "Tank.h"
#include "Sprite.h"
#include "Renderer.h"
#include "Timer.h"
#include "stdafx.h"
#include <iostream>

Tank::Tank()
{
	timer.start();
	
}

Tank::~Tank()
{

}

void Tank::tick()
{
	//We update the position each tick by adding to our position the multiplication of deltaTime * vector
	double timeElapsed = timer.getElapsedTime();
	double rotation=Sprite::getRotation();
	double vectorx = cos(rotation);
	double vectory = sin(rotation);
	double newX = Sprite::getPositionX()+(vectorx * timeElapsed*m_velx);
	double newY = Sprite::getPositionY()+(vectory * timeElapsed*m_vely);
	Sprite::setPosition(newX,newY);
	std::cout << newX<<newY;
	m_velx = 0;
	m_vely = 0;
}

void Tank::setVel(double velX, double velY)
{
	m_velx = velX;
	m_vely = velY;
}


