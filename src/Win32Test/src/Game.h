// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#pragma once
#include "RenderSystem/RenderForm.h"
#include "RenderSystem/GraphicsDevice.h"
#include "Inputsystem/InputManager.h"

namespace Engine
{
	class Game
	{
	public:
		Game(HINSTANCE hInstance, int cmdShow, int width, int height, LPCTSTR name);
		~Game();
		void Run();
		virtual void Load() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
	protected:
		std::shared_ptr<RenderForm> renderForm;
		std::shared_ptr<GraphicsDevice> graphicsDevice;	
		bool isVSync = true;
		bool isRunning = true;
		__forceinline void ShutDown() { renderForm->isRunning = false; }
	};

}