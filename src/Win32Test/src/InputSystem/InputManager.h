#pragma once

namespace Engine
{
	class InputManager
	{

	protected:
		InputManager();
		~InputManager();

	private:
		InputManager(const InputManager&) = delete;
		InputManager& operator= (const InputManager) = delete;
		std::map<UINT, bool> keys;

	public:

		static InputManager& GetInstance() 
		{
			static InputManager instance;
		
			return instance;
		}

		
		void SetKeyToTrue(UINT keyCode);
		void SetKeyToFalse(UINT keyCode);

		__forceinline bool IsKeyDown(Keys key)  { return keys[static_cast<UINT>(key)]; };
		
	};

}

