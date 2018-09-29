#include "../stdafx.h"
#include "InputManager.h"

namespace Engine
{
	InputManager::InputManager()
	{
		// Init map with second() = false
		for (UINT i = 0; i < 128; i++)
			keys[i] = false;

	}

	InputManager::~InputManager()
	{
	}

	void InputManager::SetKeyToTrue(UINT keyCode)
	{
		//std::cout << keyCode;
		keys[keyCode] = true;
	}

	void InputManager::SetKeyToFalse(UINT keyCode)
	{
		 keys[keyCode] = false;
	}

}

