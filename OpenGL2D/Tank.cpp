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
	bullet->setPosition(Sprite::getPositionX(), Sprite::getPositionY());
	bullet->setSize(0.02);
	bullet->setRotation(Sprite::getRotation());
	bullet->setDepth(1.5);

	bullet->setName("bullet");
	bullet->setVel(0.0001, 0.0001);

	Renderer::get()->addObject(bullet);
}

void Tank::draw() {
	tick();
	//1. Pass the object's color to OpenGL
	glColor3f(Sprite::getRed(), Sprite::getGreen(),Sprite::getBlue());
	//2. Save the current transformation matrix
	glPushMatrix();
	//3. Set the transformation matrix of the quad using position, size and angle
	glTranslatef(Sprite::getPositionX(), Sprite::getPositionY(), Sprite::getDepth());
	glScalef(Sprite::getSize(), Sprite::getSize(), 1);
	glRotatef(Sprite::getRotation(), 0, 0, 1);
	//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
	glBegin(GL_POLYGON);
	glVertex3f(-1, -1, -5);
	glVertex3f(1, -1, -5);
	glVertex3f(2, 0, -5);
	glVertex3f(1, 1, -5);
	glVertex3f(-1, 1, -5);
	glEnd();
	//5. Restore the transformation matrix
	glPopMatrix();
}
void Tank::setVelRotation(double velRotation)
{
	m_velrotation = velRotation;
}

