// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#pragma once
#include "../EventSystem\Event.h"
#include "../EventSystem\EventArgsMousePosition.h"
#include "../EventSystem\EventArgsOnWindowSizeChanged.h"
#include "../EventSystem\EventArgsOnKeyDown.h"
#include "../EventSystem\EventArgsOnKeyUp.h"
namespace Engine
{
	class RenderForm 
	{
	private:
		HWND hWnd;
		HINSTANCE hInstance;
		LPCTSTR name;
		int width;
		int height;
		int cmdShow;
	public:
		bool isRunning;

	private:
		void Init();
	public:
		RenderForm(HINSTANCE hInstance, int cmdShow, int width, int height, LPCTSTR name);
		~RenderForm();
		
		LRESULT CALLBACK MessageHandler(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		void Run(std::function<void()> RenderCallback) const;

// Events
		Alex::Event<void, Alex::EventArgsMousePosition> OnMousePosition;
		Alex::Event<void, Alex::EventArgsOnWindowSizeChanged> OnWindowSizeChanged;
		Alex::Event<void, Alex::EventArgsOnKeyDown> OnKeyDown;
		Alex::Event<void, Alex::EventArgsOnKeyUp> OnKeyUp;
		/*	
		Alex::Event<void, Alex::EventArgs> OnWindowState;
		Alex::Event<void, Alex::EventArgs> OnKeyUp;
		Alex::Event<void, Alex::EventArgs> OnMouseClick;
		*/

// GETTERS - SETTERS
		HWND GetHandle() const { return hWnd; }
		int GetWidth() const  { return width; }
		int GetHeight() const { return height; }
	};

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static RenderForm* ApplicationHandle = 0;
}