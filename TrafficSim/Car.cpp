#include "Car.h"

void Car::Draw()
{
	if (Direction == FORWARD)
	{
		DrawTextureEx(CarSprite, { (float)Pos.x, (float)Pos.y }, 0, 0.05, WHITE);
		//9 and 5 are offsets for front of car
		DrawCircle(Pos.x + 9, Pos.y + 5 - this->BallDistance, 5, PURPLE);
	}
	if (Direction == BACKWARD)
	{
		DrawTextureEx(CarSprite, { (float)Pos.x, (float)Pos.y }, 0, 0.05, WHITE);
		//9 and 30 are offsets for front of car
		DrawCircle(Pos.x + 9, Pos.y + 30 + this->BallDistance, 5, PURPLE);
	}
	if (Direction == RIGHT)
	{
		DrawTextureEx(CarSprite, { (float)Pos.x, (float)Pos.y }, 0, 0.05, WHITE);
		//30 and 10 are offsets for front of car
		DrawCircle(Pos.x + 30 + this->BallDistance, Pos.y + 10, 5, PURPLE);
	}
	if (Direction == LEFT)
	{
		DrawTextureEx(CarSprite, { (float)Pos.x, (float)Pos.y }, 0, 0.05, WHITE);
		//10 is offset for front of car
		DrawCircle(Pos.x - this->BallDistance, Pos.y + 10, 5, PURPLE);
	}
}

bool Car::CheckIntersection(Intersections intersections)
{
	int IntX = int(BallPos.x / 100);
	int IntY = int(BallPos.y / 100);

	Intersections::Intersection::IntersectionState State = intersections.GetIntersection({ float(IntX), float(IntY) });

	if (State == Intersections::Intersection::IntersectionState::NA)
		return false;

	if (State == Intersections::Intersection::IntersectionState::ForwardAndBack)
	{
		if (this->Direction == Car::Facing::FORWARD || this->Direction == Car::Facing::BACKWARD)
		{
			return false;
		}
		if (this->Direction == Car::Facing::LEFT || this->Direction == Car::Facing::RIGHT)
		{
			return true;
		}
	}

	if (State == Intersections::Intersection::IntersectionState::ForwardAndLeft)
	{
		if (this->Direction == Car::Facing::RIGHT || this->Direction == Car::Facing::LEFT)
		{
			return false;
		}
		if (this->Direction == Car::Facing::FORWARD || this->Direction == Car::Facing::BACKWARD)
		{
			return true;
		}
	}
}

void Car::AutoMove(float BallDistance, float Speed, Intersections intersections)
{
	this->BallDistance = BallDistance;
	

	if (!CheckIntersection(intersections))
	{
		switch (Direction)
		{
		case Car::FORWARD:
			BallPos = { Pos.x + 9, Pos.y + 5 - this->BallDistance };
			Pos.y -= Speed * GetFrameTime() * 10;
			break;
		case Car::BACKWARD:
			BallPos = { Pos.x + 9, Pos.y + 30 + this->BallDistance };
			Pos.y += Speed * GetFrameTime() * 10;
			break;
		case Car::RIGHT:
			BallPos = { Pos.x + 30 + this->BallDistance, Pos.y + 10 };
			Pos.x += Speed * GetFrameTime() * 10;
			break;
		case Car::LEFT:
			BallPos = { Pos.x - this->BallDistance, Pos.y + 10 };
			Pos.x -= Speed * GetFrameTime() * 10;
			break;
		}
	}
	
}

void Car::GetInput()
{
	if (IsKeyDown(KEY_W))
	{
		Pos.y -= 100 * GetFrameTime();
		CarSprite = ForwardCarSprite;
		Direction = FORWARD;
	}
	if (IsKeyDown(KEY_A))
	{
		Pos.x -= 100 * GetFrameTime();
		CarSprite = LeftSideCarSprite;
		Direction = LEFT;
	}
	if (IsKeyDown(KEY_S))
	{
		Pos.y += 100 * GetFrameTime();
		CarSprite = BackwardCarSprite;
		Direction = BACKWARD;
	}
	if (IsKeyDown(KEY_D))
	{
		Pos.x += 100 * GetFrameTime();
		CarSprite = RightSideCarSprite;
		Direction = RIGHT;
	}
}

Car::Car()
{
	ForwardCarSprite = LoadTexture("img\\car.png");
	BackwardCarSprite = LoadTexture("img\\car2.png");
	LeftSideCarSprite = LoadTexture("img\\car4.png");
	RightSideCarSprite = LoadTexture("img\\car3.png");

	CarSprite = BackwardCarSprite;

	Pos.x = 100;
	Pos.y = 0;
}