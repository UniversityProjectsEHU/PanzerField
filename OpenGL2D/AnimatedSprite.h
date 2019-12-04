#pragma once
#include "Sprite.h"
class AnimatedSprite :
	public Sprite
{
	double animationPoint = 0.0;
	string m_dirimg;

	float m_r, m_g, m_b;

	double m_x = 0.0, m_y = 0.0; //position around which the quad is drawn

	double m_depth = 1.0; // the renderer draws depths in range [1.0,20.0]

	double m_size = 1.0; //size of the quad

	double m_angle = 0.0; //rotation angle
public:
	AnimatedSprite(const char* textureFilename, int numImagesX, int numImagesY, bool loop);
	virtual ~AnimatedSprite();

	virtual void draw(double dt);
};

