#include "raylib.h"
#include "raymath.h"

#include "imgui.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"
#include <iostream>
#include "app.hpp"

bool Quit = false;
bool ImGuiDemoOpen = false;

int main(int argc, char* argv[])
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1280 / 2;
	int screenHeight = 720 / 2;

	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
	InitWindow(screenWidth, screenHeight, "raylib-Extras [ImGui] example - ImGui Demo");
	SetTargetFPS(144);
	rlImGuiSetup(true);
	ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;

	App app = App();

	while (!WindowShouldClose() && !Quit)
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		rlImGuiBegin();

		app.draw();

		rlImGuiEnd();
		EndDrawing();
	}
	rlImGuiShutdown();

	CloseWindow();
	return 0;
}
