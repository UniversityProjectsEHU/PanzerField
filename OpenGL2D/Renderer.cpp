#include "stdafx.h"
#include "Renderer.h"
#include "Drawable.h"

#include "../3rd-party/freeglut3/include/GL/freeglut.h"

#include "Sprite.h"

Renderer* Renderer::m_pRenderer = nullptr;

Renderer::Renderer()
{
	m_pRenderer = this;
}


Renderer::~Renderer()
{
	for (int i = 0; i < m_objects2D.size(); i++)
		delete m_objects2D[i];
}

Renderer* Renderer::get()
{
	return m_pRenderer;
}

vector<Drawable*> Renderer::getObjects(string name)
{
	std::vector<Drawable*> vectorDraw;
	for each (Drawable* var in m_objects2D)
	{
		Sprite *theObject = (Sprite*)var;
		string theName = theObject->getName();
		if (theName == name) {
			vectorDraw.push_back(var);
		}
	}
	return vectorDraw;
}


void Renderer::initialize(int argc, char** argv)
{
	//INIT GLUT/////////////////////
	////////////////////////////////
	//init window and OpenGL context
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutCreateWindow(argv[0]);

	glewInit();
	
	//OpenGL global initializations
	glEnable(GL_DEPTH_TEST);

	//callback functions
	glutDisplayFunc(__drawScene);
	glutReshapeFunc(__reshapeWindow);
}

vector<Drawable> Renderer::getVector()
{
	return vector<Drawable>();
}

void Renderer::set2DMatrix()
{
	//set projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);

	//set modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void Renderer::reshapeWindow(int w, int h)
{
	//Reshape callback function
	m_windowHeight = h;
	m_windowWidth = w;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Renderer::erase()
{
	m_objects2D.clear();
}

void Renderer::addObject(Drawable* pObj)
{
	m_objects2D.push_back(pObj);
}

void Renderer::clearAll() 
{
	exit(1);
	
}

void Renderer::drawScene()
{
	//clean the backbuffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//set the 2d modelview matrix
	set2DMatrix();

	for (auto it = m_objects2D.begin(); it != m_objects2D.end(); ++it)
	{
		(*it)->draw();
	}
	if (deleteposition != -1)
	{
		//We erase the object after we draw the entire vector
		m_objects2D.erase(m_objects2D.begin() + deleteposition);
		deleteposition = -1;
	}
}


//Nevermind these static functions: auxiliary stuff to fit openGL's callbacks
void Renderer::__drawScene()
{
	if (m_pRenderer)
		m_pRenderer->drawScene();
}
void Renderer::__reshapeWindow(int x, int y)
{
	if (m_pRenderer)
		m_pRenderer->reshapeWindow(x, y);
}

void Renderer::deleteObject(Sprite *object)
{

	
	int cont = 0;
	//std::vector<Drawable*>::iterator it = m_objects2D.begin();
	for each (Drawable* var in m_objects2D)
	{		
		Sprite *theObject = (Sprite*)var;
		string theName = theObject->getName();
		if (theObject == object) {
			//object->~Sprite();
			deleteposition = cont;
		}
		cont++;
	}
}
