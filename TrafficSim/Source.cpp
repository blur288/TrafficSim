#include <iostream>
#include <raylib.h>
#include <vector>
#include "City/City.h"
#include "Intersections.h"
#include "Car.h"
#include "rllmGui/rlImGui.h"
#include "rllmGui/imgui.h"

int main()
{
	//flags for imgui window
	static ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;

	City Road;

	InitWindow(600, 500, "Traffic");
	SetupRLImGui(true);

	Car Test = Car();
	Intersections intersections = Intersections();
	intersections.GetIntersections(Road.Grid);

	//imgui vars
	int Intervals = 10;
	float CheckerBallSpace = 0;
	bool Show = 0;
	float Speed = 1;
	bool AutoMove = 0;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		BeginRLImGui();

		ClearBackground(RAYWHITE);

		

		//Draw city grid
		Road.DrawCity();
		//check for change arrows
		intersections.ChangeArrows();
		//draw arrows
		intersections.DrawArrows();
		//draw car and get input
		Test.Draw();

		if (Show)
		{
			ImGui::Begin("Controls", &Show, ImGuiWindowFlags_NoResize);
			ImGui::SetWindowSize({ 300,300 });
			ImGui::SliderInt("Intervals", &Intervals, 1, 20);
			intersections.ChangeInterveral(Intervals);
			ImGui::SliderFloat("Ball Space", &CheckerBallSpace, 0, 30);
			ImGui::SliderFloat("Speed", &Speed, 1, 5);
			ImGui::Checkbox("Auto Move", &AutoMove);

			ImGui::End();
		}
		Test.AutoMove(CheckerBallSpace, Speed, intersections);
		if (!AutoMove)
			Test.GetInput();

		if (IsKeyPressed(KEY_E))
		{
			Show = !Show;
		}

		EndRLImGui();
		EndDrawing();
	}
}