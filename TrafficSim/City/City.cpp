#include "City.h"

City::City()
{
	Grid.push_back({ Roads::GRASS, Roads::ROAD, Roads::GRASS, Roads::GRASS, Roads::ROAD, Roads::GRASS });                 //#||##||#
	Grid.push_back({ Roads::ROAD, Roads::INTERSECTION,Roads::ROAD,Roads::ROAD,Roads::INTERSECTION,Roads::ROAD });         //--------
	Grid.push_back({ Roads::GRASS, Roads::ROAD, Roads::GRASS, Roads::GRASS, Roads::ROAD, Roads::GRASS });                 //#||##||#
	Grid.push_back({ Roads::ROAD, Roads::INTERSECTION,Roads::ROAD,Roads::ROAD,Roads::INTERSECTION,Roads::ROAD });         //--------
	Grid.push_back({ Roads::GRASS, Roads::ROAD, Roads::GRASS, Roads::GRASS, Roads::ROAD, Roads::GRASS });                 //#||##||#
}

void City::DrawCity()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			switch (Grid[j][i])
			{
			case(Roads::GRASS):
				DrawRectangle(i * 100, j * 100, 100, 100, GREEN);
				break;
			case(Roads::ROAD):
				DrawRectangle(i * 100, j * 100, 100, 100, GRAY);
				break;
			case(Roads::INTERSECTION):                    //black-ish color
				DrawRectangle(i * 100, j * 100, 100, 100, Color{ 0,0,0,220 } );
				break;
			}
		}
	}
}