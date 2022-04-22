#pragma once
#include <vector>
#include <iostream>
#include <raylib.h>

class City
{
public:
	enum Roads
	{
		GRASS,
		ROAD,
		INTERSECTION
	};
	std::vector<std::vector<Roads>> Grid;

	City();

	void DrawCity();

};

