#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Tank.h"



int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();

	//We create a tank
	Tank *tank = new Tank();

	tank->setColor(255,0,0);
	tank->setPosition(0,0);
	tank->setSize(0.02);
	tank->setRotation(0);
	tank->setDepth(1.5);

	tank->setName("tank");
	tank->setVel(0,0);

	renderer.addObject(tank);


	while (1)
	{
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();

	/*	std::vector<Drawable> vectorObjects = renderer.getVector();
		for each (Drawable var in vectorObjects)
		{
			Sprite theObject = (Sprite)var;
		}
		tank->tick();*/

		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
	}
   
	return 0;

}