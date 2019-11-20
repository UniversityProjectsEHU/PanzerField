#pragma once
#include <vector>
using namespace std;

class CollisionHandler
{
	static CollisionHandler* m_pCollision;
	vector <Drawable*> m_objects2D = vector<Drawable*>();


public:
	CollisionHandler();
	~CollisionHandler();


	static CollisionHandler* get(); //this method returns the only instance to the CollisionHandler. Needs to be called after the constructor
	void addObjectCol(Drawable* pObj);
	vector<int>handleCollision(string name);

};

