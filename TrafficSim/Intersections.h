#pragma once
#include <vector>
#include "City/City.h"

class Intersections
{
private:
	struct Position
	{
		int x, y;
	};
public:
	class Intersection
	{
	public:
		enum class IntersectionState
		{
			ForwardAndBack,
			ForwardAndLeft,
			NA
		};
	public:

		IntersectionState CurrentState = IntersectionState::ForwardAndBack;
		Position Pos;
	};
	class Timer
	{
	private:
		//start time to compare length
		int StartTime = time(0);
		//every interval timer is true
		int Intervals = 5;
		int CurrentTime = time(0);
		//diffrence between start and current time 
		int DiffrenceInTime = 0;
	public:
		void SetIntervals(int NewInterval);
		bool CheckTime();
	};

	Texture2D OppTrafficArrows;
	Texture2D LeftTurnArrows;
	Timer timer;
public:
	Intersections();

	void ChangeInterveral(int NewInterval) { timer.SetIntervals(NewInterval); }

	std::vector<Intersection> IntersectionVector;

	void GetIntersections(std::vector<std::vector<City::Roads>> GridVector);

	Intersections::Intersection::IntersectionState GetIntersection(Vector2 Vec2);

	void ChangeArrows();

	void DrawArrows();

	void PrintIntersections();
};

