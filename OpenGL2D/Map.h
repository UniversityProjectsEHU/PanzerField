#pragma once
#include "Timer.h"
#include <string>
#include <vector>
#include "Drawable.h"

using namespace std;
class Map
{
	string nameFile;
	char line;
	vector <char> m_map;
	int m_height;
	int m_width;
public:
	void createMap(string nameFile);
	Map(string namefile);
	~Map();
};

