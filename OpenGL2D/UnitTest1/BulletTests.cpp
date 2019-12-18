#include "stdafx.h"
#include "CppUnitTest.h"
#include "../bullet.h"
#include "../Sprite.h"
#include "../Renderer.h"
#include "../Timer.h"
#include "../CollisionHandler.h"
#include "../Map.h"
#include "../TextureManager.h"
#include <vector>
#include <math.h>
#include "../InputHandler.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PanzerFieldTests
{		
	TEST_CLASS(BulletTests)
	{
	public:
		Renderer renderer;
		CollisionHandler collisionHandler;
		Bullet* bullet = new Bullet("bala2.png");
		//CollisionHandler* cH = new CollisionHandler();
		bool isAlive = true;
		TEST_METHOD(tickTest)
		{
			Bullet* bullet = new Bullet("bala2.png");
			bullet->setAlive();
			std::vector<int> collisions;
			string name = bullet->getName();
			collisions = CollisionHandler::get()->handleCollision(name);
			if (collisions[0] == 1)
			{
				isAlive = false;
			}
			Assert::IsFalse(isAlive);
		}

	};
}
