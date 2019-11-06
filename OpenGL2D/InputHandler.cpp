#include "stdafx.h"
#include "InputHandler.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include <iostream>

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
	//glutKeyboardUpFunc(__processKeyboard2); Esto es para cuando se leventa la tecla
}


void InputHandler::processKeyboard(unsigned char key, int x, int y)
{
	std::cout << key;
	//keyboard callback function
	switch (key)
	{
		
    //TODO
	    //a
	case '97': 

		break;
		//w
	case '119': 
		
		break;
		//s
	case '115': 
		
		break;
		//d
	case '100': 
		
		break;

	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}