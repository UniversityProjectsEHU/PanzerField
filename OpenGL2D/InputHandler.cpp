#include "stdafx.h"
#include "InputHandler.h"
#include "Drawable.h"
#include "Sprite.h"
#include "Renderer.h"
#include "Tank.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include <iostream>
#include <vector>

InputHandler* InputHandler::m_pInputHandler = nullptr;

InputHandler::InputHandler(Renderer& renderer): m_renderer(renderer)
{
	m_pInputHandler = this;
}


InputHandler::~InputHandler()
{
}

void InputHandler::initialize()
{
	glutKeyboardFunc(__processKeyboard);
	glutKeyboardUpFunc(__processKeyboard2);
}

//Actions when the key is down
void InputHandler::processKeyboard(unsigned char key, int x, int y)
{
	std::cout << key;
	std::vector<Drawable*> vectorObjects;
	//keyboard callback function
	switch (key)
	{
	    //a
	case 97:
		vectorObjects = m_renderer.getObjects("tank");
		for each (Drawable* var in vectorObjects)
		{
			Sprite* theObject = (Sprite*)var;
			Tank* theTank = (Tank*)theObject;
			double theRotation = theTank->getRotation();
			theTank->setRotation(theRotation + 10);
		}
		break;
		//w
	case 119: 
		vectorObjects = m_renderer.getObjects("tank");
		for each (Drawable* var in vectorObjects)
		{
			Sprite* theObject = (Sprite*)var;
			Tank* theTank = (Tank*)theObject;
			theTank->setVel(0.0001,0.0001);
		}
		break;
		//s
	case 115: 
		vectorObjects = m_renderer.getObjects("tank");
		for each (Drawable* var in vectorObjects)
		{
			Sprite* theObject = (Sprite*)var;
			Tank* theTank = (Tank*)theObject;
			theTank->setVel(-0.0001,-0.0001);
		}
		break;
		//d
	case 100: 
		vectorObjects = m_renderer.getObjects("tank");
		for each (Drawable* var in vectorObjects)
		{
			Sprite* theObject = (Sprite*)var;
			Tank* theTank = (Tank*)theObject;
			double theRotation = theTank->getRotation();
			theTank->setRotation(theRotation-10);
		}
		break;

	case 27: exit(0);
	}
}

//Actions when the key is up
void InputHandler::processKeyboard2(unsigned char key, int x, int y)
{
	std::cout << key;
	std::vector<Drawable*> vectorObjects;
	//keyboard callback function
	switch (key)
	{
	//		//a
	//case 97:
	//	vectorObjects = m_renderer.getObjects("tank");
	//	for each (Drawable* var in vectorObjects)
	//	{
	//		Sprite* theObject = (Sprite*)var;
	//		Tank* theTank = (Tank*)theObject;
	//		double theRotation = theTank->getRotation();
	//		theTank->setRotation(theRotation + 10);
	//	}
	//	break;
		//w
	case 119:
		std::cout << "bajadaaaaa";
		vectorObjects = m_renderer.getObjects("tank");
		for each (Drawable* var in vectorObjects)
		{
			Sprite* theObject = (Sprite*)var;
			Tank* theTank = (Tank*)theObject;
			theTank->setVel(0, 0);
		}
		break;
		//s
	case 115:
		vectorObjects = m_renderer.getObjects("tank");
		for each (Drawable* var in vectorObjects)
		{
			Sprite* theObject = (Sprite*)var;
			Tank* theTank = (Tank*)theObject;
			theTank->setVel(0,0);
		}
		break;
		/*//d
	case 100:
		vectorObjects = m_renderer.getObjects("tank");
		for each (Drawable* var in vectorObjects)
		{
			Sprite* theObject = (Sprite*)var;
			Tank* theTank = (Tank*)theObject;
			double theRotation = theTank->getRotation();
			theTank->setRotation(theRotation - 10);
		}
		break;*/

	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}

void InputHandler::__processKeyboard2(unsigned char key, int x, int y)
{
	if (m_pInputHandler) {
		m_pInputHandler->processKeyboard2(key, x, y);
	}
}

