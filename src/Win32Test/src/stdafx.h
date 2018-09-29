// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#pragma once
#define WIN32_LEAN_AND_MEAN

#define DEBUG

#ifdef DEBUG 
#define M_DebugLog( var, msg )  (std::cout << __FILE__ << ":" << __LINE__ << ": " << (var) << " | " << (msg) << "\n")
#else
#define M_DebugLog( var, msg )
#endif

#define SAFE_RELEASE(x) { if ((x)) { (x)->Release(); } (x) = nullptr; }

#include <vld.h>;
#include <windows.h>
#include <iostream>
#include <string>
#include <algorithm>	
#include <functional>
#include <memory>
#include <vector>
#include <map>
#include <fstream>
#include <d3d11.h>
#include <D3D11_1.h>
#include <array>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include "RenderSystem/GraphicsDevice.h"
#include "InputSystem/Keys.h"


class stdafx
{
public:
	stdafx();
	~stdafx();
};
