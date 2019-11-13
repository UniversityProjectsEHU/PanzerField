#include "stdafx.h"
#include "Map.h"
#include "iostream"
#include <chrono>
#include <thread>
#include "InputHandler.h"
#include "Renderer.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"

int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);

	renderer.initialize(argc, argv);
	inputHandler.initialize();
	Map map("Map1.txt");
	while (1)
			{
				//UPDATE////////////////////
				////////////////////////////
				//process queued events
				glutMainLoopEvent();
		
		
				//RENDER////////////////////
				////////////////////////////
				glutPostRedisplay();
				glutSwapBuffers();
			}
		   
			return 0;
}

