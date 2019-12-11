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
#include "CollisionHandler.h"
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
		createBorders(); 
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
					else if (character == 'T') {
						createTreeSprite(i, j);
						i = i + 0.1;
					}
					if (character == 'D') {
						createDecorationSprite(i, j);
						i = i + 0.1;
					}
					else if (character == '0') {
						//createFieldSprite(i, j);
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
	Sprite* pSprite1 = new Sprite("cajaMadera.png");
	pSprite1->setColor(150, 150, 0);
	pSprite1->setPosition(xaxis, yaxis);
	pSprite1->setRotation(0.0);
	pSprite1->setSizeCoordinates(0.05,0.05);
	pSprite1->setDepth(1.5);
	pSprite1->setName("wall");
	Renderer::get()->addObject(pSprite1);
	CollisionHandler::get()->addObjectCol(pSprite1);
}

void Map::createDecorationSprite(double xaxis, double yaxis)
{
	Sprite* pSprite1 = new Sprite("palos1.png");
	pSprite1->setColor(150, 150, 0);
	pSprite1->setPosition(xaxis, yaxis);
	pSprite1->setRotation(0.0);
	pSprite1->setSizeCoordinates(0.05, 0.05);
	pSprite1->setDepth(1.5);
	pSprite1->setName("decoration");
	Renderer::get()->addObject(pSprite1);
	CollisionHandler::get()->addObjectCol(pSprite1);
}

void Map::createTreeSprite(double xaxis, double yaxis)
{
	Sprite* pSprite1 = new Sprite("arbol2.png");
	pSprite1->setColor(150, 150, 0);
	pSprite1->setPosition(xaxis, yaxis);
	pSprite1->setRotation(0.0);
	pSprite1->setSizeCoordinates(0.05, 0.05);
	pSprite1->setDepth(1.5);
	pSprite1->setName("wall");
	Renderer::get()->addObject(pSprite1);
	CollisionHandler::get()->addObjectCol(pSprite1);
}

void Map::createFieldSprite(double xaxis, double yaxis)
{
	Sprite* pSprite2 = new Sprite("6arboles.png");
	pSprite2->setColor(255, 255, 255);
	pSprite2->setPosition(xaxis, yaxis);
	pSprite2->setRotation(0.0);
	pSprite2->setSizeCoordinates(0.1,0.1);
	pSprite2->setDepth(1.5);
	Renderer::get()->addObject(pSprite2);
}

void Map::createBorders()
{
	//Background
	Sprite* pSprite7 = new Sprite("hierba3.png");
	pSprite7->setColor(150, 150, 0);
	pSprite7->setPosition(0, 0);
	pSprite7->setRotation(0.0);
	pSprite7->setSizeCoordinates(1, 1);
	pSprite7->setDepth(1);
	pSprite7->setName("background");
	Renderer::get()->addObject(pSprite7);
	CollisionHandler::get()->addObjectCol(pSprite7);

	//North border
	Sprite* pSprite3 = new Sprite("aguaRectangular2.png");
	pSprite3->setColor(150, 150, 0);
	pSprite3->setPosition(-1,1);
	pSprite3->setRotation(0.0);
	pSprite3->setSizeCoordinates(2, 0.1);
	pSprite3->setDepth(1.5);
	pSprite3->setName("border");
	Renderer::get()->addObject(pSprite3);
	CollisionHandler::get()->addObjectCol(pSprite3);

	//East border
	Sprite* pSprite4 = new Sprite("aguaRectangular1.png");
	pSprite4->setColor(150, 150, 0);
	pSprite4->setPosition(1, 1);
	pSprite4->setRotation(0.0);
	pSprite4->setSizeCoordinates(0.1, 2);
	pSprite4->setDepth(1.5);
	pSprite4->setName("border");
	Renderer::get()->addObject(pSprite4);
	CollisionHandler::get()->addObjectCol(pSprite4);

	//West border
	Sprite* pSprite5 = new Sprite("aguaRectangular1.png");
	pSprite5->setColor(150, 150, 0);
	pSprite5->setPosition(-1, 1);
	pSprite5->setRotation(0.0);
	pSprite5->setSizeCoordinates(0.1, 2);
	pSprite5->setDepth(1.5);
	pSprite5->setName("border");
	Renderer::get()->addObject(pSprite5);
	CollisionHandler::get()->addObjectCol(pSprite5);

	//South border
	Sprite* pSprite6 = new Sprite("aguaRectangular2.png");
	pSprite6->setColor(150, 150, 0);
	pSprite6->setPosition(-1, -1);
	pSprite6->setRotation(0.0);
	pSprite6->setSizeCoordinates(2, 0.1);
	pSprite6->setDepth(1.5);
	pSprite6->setName("border");
	Renderer::get()->addObject(pSprite6);
	CollisionHandler::get()->addObjectCol(pSprite6);
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

void Map::setSizeCoordinates(double sizeX, double sizeY)
{
	//This method only updates internally the object's size. It still needs to be passed to OpenGL before drawing it
	m_sizeX = sizeX;
	m_sizeY = sizeY;
}
void Map::draw()
{
	
	glColor3f(m_r, m_g, m_b);
	
	glPushMatrix();
	
	glTranslatef(m_x, m_y, m_depth);
	glScalef(m_sizeX, m_sizeY, 1);
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
