#pragma once
#include "Timer.h"
#include <string>
#include <vector>
#include "Drawable.h"

using namespace std;
class Map: public Drawable
{
	string nameFile;
	char line;
	vector <char> m_map;
	int m_height;
	int m_width;

	float m_r, m_g, m_b;

	double m_x = 0.0, m_y = 0.0; //position around which the quad is drawn

	double m_depth = 1.0; // the renderer draws depths in range [1.0,20.0]

	double m_sizeX = 1.0; //size of the quad
	double m_sizeY = 1.0;

	double m_angle = 0.0; //rotation angle

public:
	void createMap(string nameFile);
	void draw();
	void createWallSprite(double x, double y);
	void createDecorationSprite(double x, double y);
	void createTreeSprite(double x, double y);
	void createFieldSprite(double x, double y);
	void createBorders();
	void setColor(float r, float g, float b);
	void setPosition(double x, double y);
	void setDepth(double depth);
	void setRotation(double angle);
	void setSizeCoordinates(double sizeX, double sizeY);
	Map(string namefile);
	~Map();
};

