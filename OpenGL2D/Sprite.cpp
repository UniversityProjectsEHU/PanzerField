#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}

void Sprite::setColor(float r, float g, float b)
{
	//When this method is called, we only store internally what this object's color will be
	//but, we need to pass the color to OpenGL every time the object is drawn
	m_r = r;
	m_g = g;
	m_b = b;
}

void Sprite::setPosition(double x, double y)
{
	//This method only updates internally the object's position. It still needs to be passed to OpenGL before drawing it
	m_x = x;
	m_y = y;
}

void Sprite::setDepth(double depth)
{
	//This method only updates internally the object's depth. It still needs to be passed to OpenGL before drawing it
	m_depth = depth;
}

void Sprite::setRotation(double angle)
{
	//This method only updates internally the object's rotation. It still needs to be passed to OpenGL before drawing it
	m_angle = angle;
}

void Sprite::setSize(double size)
{
	//This method only updates internally the object's size. It still needs to be passed to OpenGL before drawing it
	m_size=size;
}

double Sprite::getPositionX()
{
	return m_x;
}

double Sprite::getPositionY()
{
	return m_y;
}

double Sprite::getRotation()
{
	return m_angle;
}

float Sprite::getRed()
{
	return m_r;
}

float Sprite::getGreen()
{
	return m_g;
}

float Sprite::getBlue()
{
	return m_b;
}

double Sprite::getSize()
{
	return m_size;
}
double Sprite::getDepth()
{
	return m_depth;
}
void Sprite::setName(string name)
{
	m_name = name;
}
string Sprite::getName()
{
	return m_name;
}

void Sprite::draw()
{
	//TODO:

	//1. Pass the object's color to OpenGL
	glColor3f(m_r, m_g, m_b);
	//2. Save the current transformation matrix
	glPushMatrix();
	//3. Set the transformation matrix of the quad using position, size and angle
	glTranslatef(m_x,m_y,m_depth);
	glScalef(m_size, m_size, 1);
	glRotatef(m_angle, 0, 0, 1);
	//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
	glBegin(GL_TRIANGLES);
	glVertex3f(-1, -1, -5);
	glVertex3f(1, 0, -5);
	glVertex3f(-1, 1, -5);
	glEnd();
	//5. Restore the transformation matrix
	glPopMatrix();
}