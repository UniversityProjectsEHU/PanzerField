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
	bool menu = true;
	bool game = false;
	Renderer renderer;
	InputHandler inputHandler(renderer);
	CollisionHandler collisionHandler;

	renderer.initialize(argc, argv);
	inputHandler.initialize();


	

	//Main menu
	Sprite *mainmenu = new Sprite("mainmenu.png");
	mainmenu->setName("menu");

	Sprite *level1 = new Sprite("menulevel1.png");
	level1->setName("menu");
	Sprite *level2 = new Sprite("menulevel2.png");
	level2->setName("menu");
	Sprite *level3 = new Sprite("menulevel3.png");
	level3->setName("menu");
	Sprite *level4 = new Sprite("menulevel4.png");
	level4->setName("menu");
	Sprite *level5 = new Sprite("menulevel5.png");
	level5->setName("menu");
	Sprite *level6 = new Sprite("menulevel6.png");
	level6->setName("menu");

	renderer.addObject(mainmenu);
	

	
	while (inputHandler.menu)
	{
		
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();
		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
		
		switch (inputHandler.level)
		{
		case 1:
			renderer.erase();
			renderer.addObject(level1);
			break;
		case 2:
			renderer.erase();
			renderer.addObject(level1);
			break;
		case 3:
			renderer.erase();
			renderer.addObject(level1);
			break;
		case 4:
			renderer.erase();
			renderer.addObject(level1);
			break;
		case 5:
			renderer.erase();
			renderer.addObject(level1);
			break;
		case 6:
			renderer.erase();
			renderer.addObject(level1);
			break;
		
		}
	}
	renderer.erase();
	//We create a tank
	Tank *tank = new Tank("tankBLUEv2.png");

	//tank->setColor(255,0,0);
	tank->setPosition(-0.80, 0.80);
	tank->setSize(0.08);
	tank->setRotation(0);
	tank->setDepth(1.5);

	tank->setName("tank1");
	tank->setVel(0, 0);
	renderer.addObject(tank);


	//We create a enemy tank
	TankEnemy *tank2 = new TankEnemy("tankREDv2.png");

	//tank2->setColor(0, 0, 255);
	tank2->setPosition(0.80, -0.80);
	tank2->setSize(0.08);
	tank2->setRotation(180);
	tank2->setDepth(1.5);

	tank2->setName("tank2");
	tank2->setVel(0, 0);
	renderer.addObject(tank2);
	game = true;
	string lv=std::to_string(inputHandler.level);
	string mapstring = string("Map") + lv + ".txt";
	Map map(mapstring);
	
	
	while (game)
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