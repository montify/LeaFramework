// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Game.h"


namespace Engine
{

	Game::Game(HINSTANCE hInstance, int cmdShow, int width, int height, LPCTSTR name)
	{
		 renderForm = std::make_shared<RenderForm>(hInstance, cmdShow, width, height, name);
		 graphicsDevice = std::make_shared<GraphicsDevice>(renderForm);

		 
		 renderForm->OnKeyDown.Subscribe("asd", [](Alex::EventArgsOnKeyDown e)
		 {
			 std::cout << e.keyCode << std::endl;
			// InputManager::GetInstance().SetKeyToTrue(e.keyCode);
		 });

		 renderForm->OnKeyUp.Subscribe("asd", [](Alex::EventArgsOnKeyUp e)
		 {
			 InputManager::GetInstance().SetKeyToFalse(e.keyCode);
		 });

		 renderForm->OnMousePosition.Subscribe("x", [](Alex::EventArgsMousePosition e)
		 {
			 std::cout << "X: " << e.x << "\ny: " << e.y << "\n";
		 });

		


	}

	void Game::Run()
	{
		Load();
		
		 renderForm->Run([this]()
		 {
			 Update();
			 Draw();
			 
			 graphicsDevice->Present(isVSync);
		 });

		// UNLOAD
	}

	Game::~Game()
	{

	}
}
