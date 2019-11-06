#include "Tank.h"
#include "Sprite.h"
#include "Renderer.h"

Tank::Tank(float r, float g, float b, double x, double y, double depth, double size, double angle)
{
	pSprite = new Sprite();
	pSprite->setColor(r, g, b);
	pSprite->setPosition(x, y);
	pSprite->setRotation(angle);
	pSprite->setSize(size);
	pSprite->setDepth(depth);

	Renderer::get()->addObject(pSprite);


}

Tank::~Tank()
{

}

