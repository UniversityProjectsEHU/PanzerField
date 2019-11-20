#include "bullet.h"
#include "Sprite.h"
#include "Renderer.h"
#include "Time.h"
#include "CollisionHandler.h"
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */

Bullet::Bullet()
{
	timer.start();
	CollisionHandler::get()->addObjectCol(this);
}

Bullet::~Bullet()
{

}

void Bullet::tick()
{
	//We update the position each tick by adding to our position the multiplication of deltaTime * vector * velocity
	double oldX = Sprite::getPositionX();
	double oldY = Sprite::getPositionY();
	double timeElapsed = timer.getElapsedTime(true);
	double rotation = Sprite::getRotation();
	double radianes = (rotation * M_PI) / 180;
	double vectorx = cos(radianes);
	double vectory = sin(radianes);
	//double newX = Sprite::getPositionX() + (vectorx * timeElapsed*m_velx);
	//double newY = Sprite::getPositionY() + (vectory * timeElapsed*m_vely);
	double newX = Sprite::getPositionX() + (vectorx * timeElapsed*m_velx);
	double newY = Sprite::getPositionY() +(vectory * timeElapsed*m_vely);
	Sprite::setPosition(newX, newY);
	//Collisions
	std::vector<int> collisions;
	string name = Sprite::getName();
	collisions = CollisionHandler::get()->handleCollision(name);
	if (collisions[2] == 1) //Collision with tank1
	{
		Renderer::get()->clearAll();
	}
	else if (collisions[3] == 1) //Collision with tank2
	{
		Renderer::get()->clearAll();
	}
}

void Bullet::setVel(double velX, double velY)
{
	m_velx = velX;
	m_vely = velY;
}

void Bullet::draw() {
	tick();
	Sprite::draw();
}