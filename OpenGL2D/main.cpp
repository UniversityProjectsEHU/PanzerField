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


	
	char character;
	string cad;
	std::cout << "Please press a number from 1 to 6\n";
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
	case '6':
		cad = "Map6.txt";
		break;
	}
	Map map("Map2.txt");

	//We create a tank
	Tank *tank = new Tank("tankBLUE.png");

	//tank->setColor(255,0,0);
	tank->setPosition(-0.80, 0.80);
	tank->setSize(0.08);
	tank->setRotation(0);
	tank->setDepth(1.5);

	tank->setName("tank1");
	tank->setVel(0, 0);
	tank->setIsAlive(true);

	renderer.addObject(tank);
	//We create a enemy tank
	TankEnemy *tank2 = new TankEnemy("tankRED.png");

	//tank2->setColor(0, 0, 255);
	tank2->setPosition(0.80, -0.80);
	tank2->setSize(0.08);
	tank2->setRotation(180);
	tank2->setDepth(1.5);

	tank2->setName("tank2");
	tank2->setVel(0, 0);
	tank2->setIsAlive(true);

	renderer.addObject(tank2);
	
	while (1)
	{
		if (tank->getIsAlive()==false) {
			renderer.erase();
			tank->setIsAlive(true);
			tank2->setIsAlive(true);
			Sprite* spriteRED = new Sprite("tankREDwinner.png");
			spriteRED->setColor(150, 150, 0);
			spriteRED->setPosition(0, 0);
			spriteRED->setRotation(0.0);
			spriteRED->setSizeCoordinates(1, 1);
			spriteRED->setDepth(1);
			spriteRED->setName("final");
			Renderer::get()->addObject(spriteRED);
		}
		else if (tank2->getIsAlive() == false) {
			renderer.erase();
			tank->setIsAlive(true);
			tank2->setIsAlive(true);
			Sprite* spriteBlue = new Sprite("tankBLUEwinner.png");
			spriteBlue->setColor(150, 150, 0);
			spriteBlue->setPosition(0, 0);
			spriteBlue->setRotation(0.0);
			spriteBlue->setSizeCoordinates(1, 1);
			spriteBlue->setDepth(1);
			spriteBlue->setName("final");
			Renderer::get()->addObject(spriteBlue);
		}
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