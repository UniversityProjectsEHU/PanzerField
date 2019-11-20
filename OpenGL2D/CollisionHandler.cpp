#include "CollisionHandler.h"
#include "Drawable.h"
#include "Sprite.h"
#include <math.h>
#include "Drawable.h"

CollisionHandler* CollisionHandler::m_pCollision= nullptr;


CollisionHandler::CollisionHandler()
{
	m_pCollision = this;
}


CollisionHandler::~CollisionHandler()
{
}

CollisionHandler * CollisionHandler::get()
{
	return m_pCollision;
}



void CollisionHandler::addObjectCol(Drawable* pObj)
{
	m_objects2D.push_back(pObj);
}

vector<int> CollisionHandler::handleCollision(string name)
{
	std::vector<int> vectorCollisions = {0, 0, 0, 0};

	for each (Drawable* var in m_objects2D)
	{

		Sprite *theObject1 = (Sprite*)var;
		string namecollision = theObject1->getName();
		if (namecollision == name)
		{
			double x = theObject1->getPositionX();
			double y = theObject1->getPositionY();
			double size1 = theObject1->getSize();
			for each (Drawable* var in m_objects2D)
			{
				Sprite *theObject2 = (Sprite*)var;
				string pointobject = theObject2->getName();
				if (namecollision != pointobject) {
					//We calculate if there´s a collision
					if (vectorCollisions[0] != 1)
					{
						if (pointobject == "wall")
						{
							double pointx = theObject2->getPositionX();
							double pointy = theObject2->getPositionY();
							double size2 = theObject2->getSize();
							double modulocollision = sqrt(pow(pointx - x, 2) + pow(pointy - y, 2));
							if (modulocollision < (size1  + size2 ))
							{
								vectorCollisions[0] = 1;
							}

						}
					}
				
					if (pointobject == "bullet")
					{
						double pointx = theObject2->getPositionX();
						double pointy = theObject2->getPositionY();
						double size2 = theObject2->getSize();
						double modulocollision = sqrt(pow(pointx - x, 2) + pow(pointy - y, 2));
						if (modulocollision < (size1 / 2 + size2 / 2))
						{
							vectorCollisions[1] = 1;
						}

					}
					if (pointobject == "tank1")
					{
						double pointx = theObject2->getPositionX();
						double pointy = theObject2->getPositionY();
						double size2 = theObject2->getSize();
						double modulocollision = sqrt(pow(pointx - x, 2) + pow(pointy - y, 2));
						if (modulocollision < (size1 / 2 + size2 / 2))
						{
							vectorCollisions[2] = 1;
						}

					}
					if (pointobject == "tank2")
					{
						double pointx = theObject2->getPositionX();
						double pointy = theObject2->getPositionY();
						double size2 = theObject2->getSize();
						double modulocollision = sqrt(pow(pointx - x, 2) + pow(pointy - y, 2));
						if (modulocollision < (size1 / 2 + size2 / 2))
						{
							vectorCollisions[3] = 1;
						}

					}

				}


			}
		}
		
	}
	return vectorCollisions;
}
