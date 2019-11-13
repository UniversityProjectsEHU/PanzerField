#include "Tank.h"
#include "Sprite.h"
#include "Renderer.h"
#include "Timer.h"
#include "stdafx.h"
#include "Renderer.h"
#include "Bullet.h"
#include <iostream>
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */

Tank::Tank()
{
	timer.start();
	
}

Tank::~Tank()
{

}

void Tank::tick()
{
	//We update the position each tick by adding to our position the multiplication of deltaTime * vector * velocity
	double timeElapsed = timer.getElapsedTime(true);
	double rotation=Sprite::getRotation();
	double radianes = (rotation * M_PI) / 180;
	double vectorx = cos(radianes);
	double vectory = sin(radianes);
	double newX = Sprite::getPositionX()+(vectorx * timeElapsed*m_velx);
	double newY = Sprite::getPositionY()+(vectory * timeElapsed*m_vely);
	//Position in front of tank
	frontx = Sprite::getPositionX() + (vectorx  *0.05);
	fronty = Sprite::getPositionY() + (vectory *0.05);
	Sprite::setPosition(newX,newY);
	//We update the rotation if the velocity of rotation is not equal to zero
	if (m_velrotation != 0)
	{
		Sprite::setRotation(Sprite::getRotation() + m_velrotation);

	}
}

void Tank::setVel(double velX, double velY)
{
	m_velx = velX;
	m_vely = velY;
}

void Tank::shoot() {
	Bullet *bullet = new Bullet();
	
	
	bullet->setColor(255, 255, 255);
	bullet->setPosition(frontx, fronty);
	bullet->setSize(0.01);
	bullet->setRotation(Sprite::getRotation());
	bullet->setDepth(1.5);

	bullet->setName("bullet");
	bullet->setVel(1, 1);

	Renderer::get()->addObject(bullet);
}

void Tank::draw() {
	tick();
	Sprite::draw();
}
void Tank::setVelRotation(double velRotation)
{
	m_velrotation = velRotation;
}


