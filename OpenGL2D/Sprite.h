#pragma once

#include "Drawable.h"
#include <string>
using namespace std;
class Sprite: public Drawable
{
	string m_filename;

	float m_r, m_g, m_b;
	
	double m_x= 0.0, m_y= 0.0; //position around which the quad is drawn

	double m_depth = 1.0; // the renderer draws depths in range [1.0,20.0]

	double m_sizeX = 1.0; //size of the quad
	double m_sizeY = 1.0; //size of the quad

	double m_angle= 0.0; //rotation angle

	string m_name;
public:
	Sprite(string filename);
	~Sprite();

	virtual void draw();
	void setColor(float r, float g, float b);
	void setPosition(double x, double y);
	void setDepth(double depth);
	void setRotation(double angle);
	void setSize(double size);
	void setSizeCoordinates(double sizeX, double sizeY);
	double getPositionX();
	double getPositionY();
    double getRotation();
	float getRed();
	float getGreen();
	float getBlue();
	double getSize();
	double getSizeX();
	double getSizeY();
	double getDepth();
	
	string getName();
	void setName(string name);
	
};

