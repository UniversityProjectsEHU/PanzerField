#include "Map.h"
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <thread>
#include <fstream>
#include "stdafx.h"
#include <stdio.h>
#include <istream>
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include <iostream> //Text color
#include <windows.h>

//#include "../SoundManager/SoundManager.h"



Map::Map(std::string nameFile)
{
	createMap(nameFile);
}

void Map::createMap(std::string nameFile)
{
	char character;
	char line;
	char delimiter;
	Sprite *sp1 = new Sprite();
	ifstream inputFile(nameFile, fstream::in);
	if (inputFile.is_open())
	{
		inputFile >> m_height;
		inputFile >> delimiter;
		inputFile >> m_width;
		m_map = vector<char>(m_height*m_width);
		while (!inputFile.eof()) 
		{
			inputFile.get(character);
			if (character == '"')
			{
				while (character != '/')
				{
					inputFile.get(character);
					if (character == 'W')
						std::cout << "../Images/Wall.png";
					else if(character == '0')
						std::cout << "..Images/Grass.png";
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100000));
	}
	inputFile.close();
}

Map::~Map()
{
}
