#include "Intersections.h"

bool Intersections::Timer::CheckTime()
{
	CurrentTime = time(0);
	DiffrenceInTime = CurrentTime - StartTime;

	if (DiffrenceInTime >= Intervals)
	{
		StartTime = time(0);
		return true;
	}
	return false;
}
void Intersections::Timer::SetIntervals(int NewInterval)
{
	this->Intervals = NewInterval;
}

Intersections::Intersections()
{
	LeftTurnArrows = LoadTexture("img\\TrafficSymbols\\LeftTurn.png");
	OppTrafficArrows = LoadTexture("img\\TrafficSymbols\\OppDirections.png");
}

Intersections::Intersection::IntersectionState Intersections::GetIntersection(Vector2 Vec2)
{
	for (int i = 0; i < IntersectionVector.size(); i++)
	{
		if (IntersectionVector[i].Pos.x == Vec2.x && IntersectionVector[i].Pos.y == Vec2.y)
		{
			return IntersectionVector[i].CurrentState;
		}
	}
	return Intersections::Intersection::IntersectionState::NA;
}

void Intersections::ChangeArrows()
{
	if (timer.CheckTime())
	{
		for (int i = 0; i < IntersectionVector.size(); i++)
		{
			if (IntersectionVector[i].CurrentState == Intersection::IntersectionState::ForwardAndBack)
			{
				IntersectionVector[i].CurrentState = Intersection::IntersectionState::ForwardAndLeft;
			}
			else
			{
				IntersectionVector[i].CurrentState = Intersection::IntersectionState::ForwardAndBack;
			}
		}
	}
}

void Intersections::DrawArrows()
{
	for (int i = 0; i < IntersectionVector.size(); i++)
	{
		if (IntersectionVector[i].CurrentState == Intersection::IntersectionState::ForwardAndBack)
		{
			DrawTexture(OppTrafficArrows, IntersectionVector[i].Pos.x * 100, IntersectionVector[i].Pos.y * 100, WHITE);
		}
		else
		{
			DrawTexture(LeftTurnArrows, IntersectionVector[i].Pos.x * 100, IntersectionVector[i].Pos.y * 100, WHITE);
		}
	}
}

void Intersections::GetIntersections(std::vector<std::vector<City::Roads>> GridVector)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (GridVector[j][i] == City::INTERSECTION)
			{
				Intersection Temp;
				Temp.Pos = { i,j };
				IntersectionVector.push_back(Temp);
			}
		}
	}
}

void Intersections::PrintIntersections()
{
	for (int i = 0; i < IntersectionVector.size(); i++)
	{
		std::cout << IntersectionVector[i].Pos.x << " " << IntersectionVector[i].Pos.y << "\n";
	}
}