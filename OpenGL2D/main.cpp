#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "stdio.h"
#include "Map.h"
#include <fstream>
#include <istream>
#include <iostream>
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Tank.h"
#include "CollisionHandler.h"
#include "TankEnemy.h"



int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	CollisionHandler collisionHandler;

	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//We create a tank
	Tank *tank = new Tank("tankBLUE.png");

	//tank->setColor(255,0,0);
	tank->setPosition(-0.80,0.80);
	tank->setSize(0.02);
	tank->setRotation(0);
	tank->setDepth(1.5);

	tank->setName("tank1");
	tank->setVel(0,0);

	renderer.addObject(tank);
	//We create a enemy tank
	TankEnemy *tank2 = new TankEnemy("tankRED.png");

	//tank2->setColor(0, 0, 255);
	tank2->setPosition(0.80, -0.80);
	tank2->setSize(0.02);
	tank2->setRotation(0);
	tank2->setDepth(1.5);

	tank2->setName("tank2");
	tank2->setVel(0, 0);

	renderer.addObject(tank2);
	char character;
	string cad;
	std::cout << "Please press a number from 1 to 5\n";
	std::cin >> character;
	switch (character) {
	case '1':
		cad = "Map1.txt";
		break;
	case '2':
		cad = "Map2.txt";
		break;
	case '3':
		cad = "Map3.txt";
		break;
	case '4':
		cad = "Map4.txt";
		break;
	case '5':
		cad = "Map5.txt";
		break;
	}
	Map map(cad);
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