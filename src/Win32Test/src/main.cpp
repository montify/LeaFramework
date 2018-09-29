// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Game01.h"

void ShowConsole()
{
	AllocConsole();
	
	FILE* pCout;
	freopen_s(&pCout, "conout$", "w", stdout);
}


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	ShowConsole();

	auto game  = new Engine::Game01(hInstance, nCmdShow, 800, 600, "FIRST XD");
	
	game->Run();

	delete game;

	
	return 0;
}

