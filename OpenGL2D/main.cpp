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
#include "../SoundManager/SoundManager.h" //relative path to the main header




int main(int argc, char** argv)
{

	Renderer renderer;
	InputHandler inputHandler(renderer);
	CollisionHandler collisionHandler;

	renderer.initialize(argc, argv);
	inputHandler.initialize();

	//SoundManager
	SoundManager soundManager;
	SoundManager* pSoundManager = SoundManager::getInstance();
	pSoundManager->load("../snd/hell2.wav");
	pSoundManager->load("../snd/explosion.wav");
	pSoundManager->play("../snd/hell2.wav", 0.5, 0, 0, 0, 0, 0, 0);

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
	//

	//We create a tank
	Tank *tank = new Tank("tankBLUE.png");

	//tank->setColor(255,0,0);
	

	tank->setName("tank1");
	tank->setVel(0, 0);
	tank->setIsAlive(true);

	


	//We create a enemy tank
	TankEnemy *tank2 = new TankEnemy("tankRED.png");

	//tank2->setColor(0, 0, 255);
	

	tank2->setName("tank2");
	tank2->setVel(0, 0);
	tank2->setIsAlive(true);

	

	renderer.addObject(mainmenu);
	

	while (!inputHandler.finished)
	{
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
				renderer.addObject(level2);
				break;
			case 3:
				renderer.erase();
				renderer.addObject(level3);
				break;
			case 4:
				renderer.erase();
				renderer.addObject(level4);
				break;
			case 5:
				renderer.erase();
				renderer.addObject(level5);
				break;
			case 6:
				renderer.erase();
				renderer.addObject(level6);
				break;
			case 0:
				renderer.erase();
				renderer.addObject(mainmenu);
				break;
			}
		}
		renderer.erase();

		//Create the map BEFORE the tanks
		string lv = std::to_string(inputHandler.level);
		string mapstring = string("Map") + lv + ".txt";
		Map map(mapstring);

		//We define tank parameters and add the bullet together with the tank to the renderer

		//TANK1:
		tank->setPosition(-0.80, 0.80);
		tank->setSize(0.08);
		tank->setRotation(0);
		tank->setDepth(1.5);
		renderer.addObject(tank);
		tank->addBullet2Renderer();

		//TANK2:
		tank2->setPosition(0.80, -0.80);
		tank2->setSize(0.08);
		tank2->setRotation(180);
		tank2->setDepth(1.5);
		renderer.addObject(tank2);
		tank2->addBullet2Renderer();

		inputHandler.game = true;



		while (inputHandler.game)
		{
			if (tank->getIsAlive() == false) {
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
				inputHandler.finished = true;
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
				inputHandler.finished = true;
			}
			//UPDATE////////////////////
			////////////////////////////
			//process queued events
			glutMainLoopEvent();
			//RENDER////////////////////
			////////////////////////////
			glutPostRedisplay();
			glutSwapBuffers();
		}

		//return 0;
	}
	

}