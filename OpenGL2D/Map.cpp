#include "Map.h"
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <thread>
#include <fstream>
#include "stdafx.h"
#include <stdio.h>
#include <istream>
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include <iostream> //Text color
#include <windows.h>
//#include "../SoundManager/SoundManager.h"

Map::Map(std::string nameFile)
{
	createMap(nameFile);
}

void Map::createMap(std::string nameFile)
{
	char character;
	char line;
	char delimiter;
	double i = -1.0;
	double j = 1.0;
	ifstream inputFile(nameFile, fstream::in);
	if (inputFile.is_open())
	{
		inputFile >> m_height;
		inputFile >> delimiter;
		inputFile >> m_width;
		m_map = vector<char>(m_height*m_width);
		while (!inputFile.eof()) 
		{
			inputFile.get(character);
			if (character == '"')
			{
				while (character != '/')
				{
					
					inputFile.get(character);
					if (character == 'W') {
						createWallSprite(i, j);
						i = i + 0.1;
					}
					else if (character == '0') {
						createFieldSprite(i, j);
						i = i + 0.1;
					}
					else if (character == '/') {
						j = j - 0.1;
						i = -1;
						std::cout << '\n';
					}
				}
			}
		}

	}
	inputFile.close();
}
void Map::createWallSprite(double xaxis, double yaxis)
{
	Sprite* pSprite1 = new Sprite();
	pSprite1->setColor(150, 150, 0);
	pSprite1->setPosition(xaxis, yaxis);
	pSprite1->setRotation(0.0);
	pSprite1->setSize(0.1);
	pSprite1->setDepth(1.5);
	Renderer::get()->addObject(pSprite1);
}

void Map::createFieldSprite(double xaxis, double yaxis)
{
	Sprite* pSprite2 = new Sprite();
	pSprite2->setColor(255, 255, 255);
	pSprite2->setPosition(xaxis, yaxis);
	pSprite2->setRotation(0.0);
	pSprite2->setSize(0.1);
	pSprite2->setDepth(1.5);
	Renderer::get()->addObject(pSprite2);
}

void Map::setColor(float r, float g, float b)
{
	//When this method is called, we only store internally what this object's color will be
	//but, we need to pass the color to OpenGL every time the object is drawn
	m_r = r;
	m_g = g;
	m_b = b;
}

void Map::setPosition(double x, double y)
{
	//This method only updates internally the object's position. It still needs to be passed to OpenGL before drawing it
	m_x = x;
	m_y = y;
}

void Map::setDepth(double depth)
{
	//This method only updates internally the object's depth. It still needs to be passed to OpenGL before drawing it
	m_depth = depth;
}

void Map::setRotation(double angle)
{
	//This method only updates internally the object's rotation. It still needs to be passed to OpenGL before drawing it
	m_angle = angle;
}

void Map::setSize(double size)
{
	//This method only updates internally the object's size. It still needs to be passed to OpenGL before drawing it
	m_size = size;
}
void Map::draw()
{
	
	glColor3f(m_r, m_g, m_b);
	
	glPushMatrix();
	
	glTranslatef(m_x, m_y, m_depth);
	glScalef(m_size, m_size, 1);
	glRotatef(m_angle, 0, 0, 1);
	
	glBegin(GL_QUADS);
	glVertex3f(-1, -1, -5);
	glVertex3f(1, -1, -5);
	glVertex3f(1, 1, -5);
	glVertex3f(-1, 1, -5);
	glEnd();

	glPopMatrix();
}

Map::~Map()
{
}
