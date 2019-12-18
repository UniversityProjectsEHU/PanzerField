#pragma once

class Drawable;
#include <vector>
#include "Sprite.h"
#include "TextureManager.h"
using namespace std;

class Renderer
{
	static Renderer* m_pRenderer;
	int m_windowWidth = 0, m_windowHeight = 0;
	int deleteposition = -1;

	vector <Drawable*> m_objects2D= vector<Drawable*>();

	void set2DMatrix();
public:
	Renderer();
	~Renderer();

	TextureManager managerTexture;
	void initialize(int argc, char** argv);
	vector<Drawable*>& getVector();
	static Renderer* get(); //this method returns the only instance to the renderer. Needs to be called after the constructor
	vector<Drawable*>getObjects(string name);
	void drawScene();
	void addObject(Drawable* pObj);
	void clearAll();
	void reshapeWindow(int x, int y);
	void erase();
	static void __drawScene();
	static void __reshapeWindow(int x, int y);
	void deleteObject(Sprite *object);
};

