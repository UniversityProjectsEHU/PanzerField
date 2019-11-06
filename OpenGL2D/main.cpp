#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"



int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//test objects
	/*Sprite *pSprite1= new Sprite();
	pSprite1->setColor(255, 0, 0);
	pSprite1->setPosition(0.25, 0.25);
	pSprite1->setRotation(0.0);
	pSprite1->setSize(0.2);
	pSprite1->setDepth(1.5);
	renderer.addObject(pSprite1);

	Sprite *pSprite2= new Sprite();
	pSprite2->setColor(0, 255, 0);
	pSprite2->setPosition(0.5, 0.5);
	pSprite2->setRotation(45.0);
	pSprite2->setSize(0.2);
	pSprite2->setDepth(1.3);
	renderer.addObject(pSprite2);*/

	//CREEPER

	//OJOH
	Sprite *pSprite1 = new Sprite();
	pSprite1->setColor(0, 0.5, 0);
	pSprite1->setPosition(-0.25, 0.4);
	pSprite1->setRotation(0);
	pSprite1->setSize(0.1);
	pSprite1->setDepth(1.3);
	renderer.addObject(pSprite1);
	//OJOH2
	Sprite *pSprite3 = new Sprite();
	pSprite3->setColor(0, 0.5, 0);
	pSprite3->setPosition(0.25, 0.4);
	pSprite3->setRotation(0);
	pSprite3->setSize(0.1);
	pSprite3->setDepth(1.3);
	renderer.addObject(pSprite3);
	//BOCA
	Sprite *pSprite4 = new Sprite();
	pSprite4->setColor(150, 0, 0);
	pSprite4->setPosition(0, 0.8);
	pSprite4->setRotation(0);
	pSprite4->setSize(0.4);
	pSprite4->setDepth(1.3);
	renderer.addObject(pSprite4);
	//CABESA
	Sprite *pSprite2 = new Sprite();
	pSprite2->setColor(0, 255, 0);
	pSprite2->setPosition(0, 0.2);
	pSprite2->setRotation(0);
	pSprite2->setSize(0.5);
	pSprite2->setDepth(1.3);
	renderer.addObject(pSprite2);


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