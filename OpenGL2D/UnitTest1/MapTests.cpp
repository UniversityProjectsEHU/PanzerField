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
	TEST_CLASS(MapTests)
	{
	public:
		Renderer renderer;
		CollisionHandler collisionHandler;
		TEST_METHOD(createWallTest)
		{
			Map* map = new Map("Map1.txt");
			map->createWallSprite(1.0, 1.0); 
			Sprite* pSpr = new Sprite("cajaMadera.png");
			pSpr->setColor(150, 150, 0);
			pSpr->setPosition(1.0, 1.0);
			pSpr->setRotation(0.0);
			pSpr->setSizeCoordinates(0.05, 0.05);
			pSpr->setDepth(1.5);
			pSpr->setName("wall");
			vector <Drawable*> m_objects2D = renderer.get()->getObjects(("wall"));
			Assert::AreEqual(pSpr->getBlue(),((Sprite*)m_objects2D.front())->getBlue());
			Assert::AreEqual(pSpr->getRed(), ((Sprite*)m_objects2D.front())->getRed());
			Assert::AreEqual(pSpr->getGreen(), ((Sprite*)m_objects2D.front())->getGreen());
			Assert::AreEqual(pSpr->getPositionX(), ((Sprite*)m_objects2D.front())->getPositionX());
			Assert::AreEqual(pSpr->getPositionY(), ((Sprite*)m_objects2D.front())->getPositionY());
		}

		TEST_METHOD(createDecorationTest)
		{
			Map* map = new Map("Map1.txt");
			map->createDecorationSprite(1.0, 1.0);
			Sprite* pSpr = new Sprite("palos1.png");
			pSpr->setColor(150, 150, 0);
			pSpr->setPosition(1.0, 1.0);
			pSpr->setRotation(0.0);
			pSpr->setSizeCoordinates(0.05, 0.05);
			pSpr->setDepth(1.5);
			pSpr->setName("decoration");
			vector <Drawable*> m_objects2D = renderer.get()->getObjects(("decoration"));
			Assert::AreEqual(pSpr->getBlue(), ((Sprite*)m_objects2D.front())->getBlue());
			Assert::AreEqual(pSpr->getRed(), ((Sprite*)m_objects2D.front())->getRed());
			Assert::AreEqual(pSpr->getGreen(), ((Sprite*)m_objects2D.front())->getGreen());
			Assert::AreEqual(pSpr->getPositionX(), ((Sprite*)m_objects2D.front())->getPositionX());
			Assert::AreEqual(pSpr->getPositionY(), ((Sprite*)m_objects2D.front())->getPositionY());
		}

		TEST_METHOD(createTreeTest)
		{
			Map* map = new Map("Map1.txt");
			map->createTreeSprite(1.0, 1.0);
			Sprite* pSpr = new Sprite("arbol2.png");
			pSpr->setColor(150, 150, 0);
			pSpr->setPosition(1.0, 1.0);
			pSpr->setRotation(0.0);
			pSpr->setSizeCoordinates(0.05, 0.05);
			pSpr->setDepth(1.5);
			pSpr->setName("wall");
			vector <Drawable*> m_objects2D = renderer.get()->getObjects(("wall"));
			Assert::AreEqual(pSpr->getBlue(), ((Sprite*)m_objects2D.front())->getBlue());
			Assert::AreEqual(pSpr->getRed(), ((Sprite*)m_objects2D.front())->getRed());
			Assert::AreEqual(pSpr->getGreen(), ((Sprite*)m_objects2D.front())->getGreen());
			Assert::AreEqual(pSpr->getPositionX(), ((Sprite*)m_objects2D.front())->getPositionX());
			Assert::AreEqual(pSpr->getPositionY(), ((Sprite*)m_objects2D.front())->getPositionY());
		}

		TEST_METHOD(createBordersTest)
		{
			Map* map = new Map("Map1.txt");
			map->createBorders();
			Sprite* pSpr = new Sprite("hierba.png");
			pSpr->setColor(150, 150, 0);
			pSpr->setPosition(0, 0);
			pSpr->setRotation(0.0);
			pSpr->setSizeCoordinates(10, 10);
			pSpr->setDepth(1);
			pSpr->setName("background");
			vector <Drawable*> m_objects2D = renderer.get()->getObjects("background");
			Assert::AreEqual(pSpr->getBlue(), ((Sprite*)m_objects2D.front())->getBlue());
			Assert::AreEqual(pSpr->getRed(), ((Sprite*)m_objects2D.front())->getRed());
			Assert::AreEqual(pSpr->getGreen(), ((Sprite*)m_objects2D.front())->getGreen());
			Assert::AreEqual(pSpr->getPositionX(), ((Sprite*)m_objects2D.front())->getPositionX());
			Assert::AreEqual(pSpr->getPositionY(), ((Sprite*)m_objects2D.front())->getPositionY());
			Sprite* pSpr3 = new Sprite("fondoAgua.png");
			pSpr3->setColor(150, 150, 0);
			pSpr3->setPosition(-1, 1);
			pSpr3->setRotation(0.0);
			pSpr3->setSizeCoordinates(2, 0.1);
			pSpr3->setDepth(1.5);
			pSpr3->setName("border");
			m_objects2D = renderer.get()->getObjects("border");
			for (size_t i = 0; i < m_objects2D.size(); i++)
			{
				if (i = 0)
				{
					Sprite* pSpr3 = new Sprite("fondoAgua.png");
					pSpr3->setColor(150, 150, 0);
					pSpr3->setPosition(-1, 1);
					pSpr3->setRotation(0.0);
					pSpr3->setSizeCoordinates(2, 0.1);
					pSpr3->setDepth(1.5);
					pSpr3->setName("border");
					Assert::AreEqual(pSpr3->getBlue(), ((Sprite*)m_objects2D[i])->getBlue());
					Assert::AreEqual(pSpr3->getRed(), ((Sprite*)m_objects2D[i])->getRed());
					Assert::AreEqual(pSpr3->getGreen(), ((Sprite*)m_objects2D[i])->getGreen());
					Assert::AreEqual(pSpr3->getPositionX(), ((Sprite*)m_objects2D[i])->getPositionX());
					Assert::AreEqual(pSpr3->getPositionY(), ((Sprite*)m_objects2D[i])->getPositionY());
					Assert::AreEqual(pSpr3->getName(), ((Sprite*)m_objects2D[i])->getName());
				}
				if (i = 1)
				{
					Sprite* pSpr4 = new Sprite("fondoAgua.png");
					pSpr4->setColor(150, 150, 0);
					pSpr4->setPosition(1, 1);
					pSpr4->setRotation(0.0);
					pSpr4->setSizeCoordinates(0.1, 2);
					pSpr4->setDepth(1.5);
					pSpr4->setName("border");
					Assert::AreEqual(pSpr4->getBlue(), ((Sprite*)m_objects2D[i])->getBlue());
					Assert::AreEqual(pSpr4->getRed(), ((Sprite*)m_objects2D[i])->getRed());
					Assert::AreEqual(pSpr4->getGreen(), ((Sprite*)m_objects2D[i])->getGreen());
					Assert::AreEqual(pSpr4->getPositionX(), ((Sprite*)m_objects2D[i])->getPositionX());
					Assert::AreEqual(pSpr4->getPositionY(), ((Sprite*)m_objects2D[i])->getPositionY());
					Assert::AreEqual(pSpr4->getName(), ((Sprite*)m_objects2D[i])->getName());

				}
				if (i = 2)
				{
					Sprite* pSpr5 = new Sprite("fondoAgua.png");
					pSpr5->setColor(150, 150, 0);
					pSpr5->setPosition(-1, 1);
					pSpr5->setRotation(0.0);
					pSpr5->setSizeCoordinates(2, 0.1);
					pSpr5->setDepth(1.5);
					pSpr5->setName("border");
					Assert::AreEqual(pSpr5->getBlue(), ((Sprite*)m_objects2D[i])->getBlue());
					Assert::AreEqual(pSpr5->getRed(), ((Sprite*)m_objects2D[i])->getRed());
					Assert::AreEqual(pSpr5->getGreen(), ((Sprite*)m_objects2D[i])->getGreen());
					Assert::AreEqual(pSpr5->getPositionX(), ((Sprite*)m_objects2D[i])->getPositionX());
					Assert::AreEqual(pSpr5->getPositionY(), ((Sprite*)m_objects2D[i])->getPositionY());
					Assert::AreEqual(pSpr5->getName(), ((Sprite*)m_objects2D[i])->getName());
				}
				if (i = 3)
				{
					Sprite* pSpr6 = new Sprite("fondoAgua.png");
					pSpr6->setColor(150, 150, 0);
					pSpr6->setPosition(-1, -1);
					pSpr6->setRotation(0.0);
					pSpr6->setSizeCoordinates(2, 0.1);
					pSpr6->setDepth(1.5);
					pSpr6->setName("border");
					Assert::AreEqual(pSpr6->getBlue(), ((Sprite*)m_objects2D[i])->getBlue());
					Assert::AreEqual(pSpr6->getRed(), ((Sprite*)m_objects2D[i])->getRed());
					Assert::AreEqual(pSpr6->getGreen(), ((Sprite*)m_objects2D[i])->getGreen());
					Assert::AreEqual(pSpr6->getPositionX(), ((Sprite*)m_objects2D[i])->getPositionX());
					Assert::AreEqual(pSpr6->getPositionY(), ((Sprite*)m_objects2D[i])->getPositionY());
					Assert::AreEqual(pSpr6->getName(), ((Sprite*)m_objects2D[i])->getName());
				}
			}
		}
		
	};
}
	

