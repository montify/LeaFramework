// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "../stdafx.h"
#include "RenderForm.h"


namespace Engine 
{
	RenderForm::RenderForm(HINSTANCE hInstance, int cmdShow, int width, int height, LPCTSTR name)
		: hInstance(hInstance), name(name), width(width), height(height), cmdShow(cmdShow)
	{
		
		this->isRunning = true;
		
		Init();
	}

	void RenderForm::Init()
	{
		ApplicationHandle = this;

		OnMousePosition = Alex::Event<void, Alex::EventArgsMousePosition>();
		OnWindowSizeChanged = Alex::Event<void, Alex::EventArgsOnWindowSizeChanged>();
		/*OnWindowState = Alex::Event<void, Alex::EventArgs>();
		OnKeyDown = Alex::Event<void, Alex::EventArgs>();
		OnMouseClick = Alex::Event<void, Alex::EventArgs>();*/

		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = hInstance;
		wc.lpszClassName = "window";

		RegisterClass(&wc);

		hWnd = CreateWindowEx(
			0,                              // Optional window styles.
			"window",						// Window class
			name,							// Window text
			WS_OVERLAPPEDWINDOW,            // Window style					
			CW_USEDEFAULT,					// x coord
			CW_USEDEFAULT,					// y coord
			width, 							// width
			height,							// height
			nullptr,						// Parent window    
			nullptr,						// Menu
			hInstance,						// Instance handle
			nullptr							// Additional application data
		);

		if (hWnd == nullptr)
			__debugbreak();
	
		ShowWindow(hWnd, cmdShow);
	}

	void RenderForm::Run(std::function<void()> RenderCallback) const
	{
		MSG msg = {};

		while (msg.message !=  WM_QUIT)
		{
			if (!isRunning)
				break;

			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE /*| PM_NOYIELD)*/))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
				RenderCallback();
		}
	}

	RenderForm::~RenderForm()
	{
		ApplicationHandle = nullptr;
	}

	LRESULT CALLBACK RenderForm::MessageHandler(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hwnd, &ps);
				FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
				EndPaint(hwnd, &ps);
			}
			case WM_SIZE:
			{
				RECT rect;
				GetClientRect(hwnd, &rect);

				OnWindowSizeChanged.Invoke(Alex::EventArgsOnWindowSizeChanged(rect.right, rect.bottom));

				width = rect.right;
				height = rect.bottom;

			/*	if (wParam == SIZE_MAXIMIZED)
					OnWindowState.Invoke(Alex::EventArgsMousePosition());

				if (wParam == SIZE_MINIMIZED)
					OnWindowState.Invoke(Alex::EventArgsMousePosition());
					*/
				break;
			}
			case WM_KEYDOWN:
			{
				OnKeyDown.Invoke(Alex::EventArgsOnKeyDown(wParam));
				break;
			}
			case WM_KEYUP:
			{
				OnKeyUp.Invoke(Alex::EventArgsOnKeyUp(wParam));
				break;
			}
			case WM_MOUSEMOVE:
			{
				OnMousePosition.Invoke(Alex::EventArgsMousePosition(LOWORD(lParam), HIWORD(lParam)));
				break;
			}
			case WM_LBUTTONDOWN:
			{
				//OnMouseClick.Invoke(1, true);
				break;
			}
			case WM_RBUTTONDOWN:
			{
				//OnMouseClick.Invoke(2, true);
				break;
			}
			case WM_CLOSE:
			{
				PostQuitMessage(0);
				return 0;
			}
			default:
			{
				return DefWindowProc(hwnd, uMsg, wParam, lParam);
			}
		}

		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			// Check if the window is being closed.
			
			// All other messages pass to the message handler in the system class.
			default:
			{
				return ApplicationHandle->MessageHandler(hwnd, uMsg, wParam, lParam);
			}
		}
	}
}