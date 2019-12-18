#include "stdafx.h"
#include "CppUnitTest.h"
#include "../bullet.h"
#include "../Sprite.h"
#include "../Renderer.h"
#include "../Timer.h"
#include "../CollisionHandler.h"
#include "../Map.h"
#include "../TextureManager.h"
#include "../Tank.h"
#include <vector>
#include <math.h>
#include "../InputHandler.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PanzerFieldTests
{
	TEST_CLASS(CollisionHandlerTests)
	{
	public:
		Renderer renderer;
		CollisionHandler collisionHandler;
		TEST_METHOD(handleCollisionTest)
		{
			std::vector<int> vectorCollisions = { 0, 0, 0, 0 };
			Sprite* pSprite = new Sprite("cajaMadera.png");
			pSprite->setColor(150, 150, 0);
			pSprite->setPosition(1.0, 1.0);
			pSprite->setRotation(0.0);
			pSprite->setSizeCoordinates(0.05, 0.05);
			pSprite->setDepth(1.5);
			pSprite->setName("wall");
			CollisionHandler::get()->addObjectCol(pSprite);
			Tank *tank = new Tank("tankBLUEv2.png");
			tank->setPosition(1.0, 1.0);
			tank->setSize(0.08);
			tank->setRotation(0);
			tank->setDepth(1.5);
			tank->setName("tank1");
			tank->setVel(0, 0);
			renderer.addObject(tank);
			CollisionHandler::get()->addObjectCol(tank);
			vector <Drawable*> m_objects2D = renderer.get()->getVector();


		}
	};
}



