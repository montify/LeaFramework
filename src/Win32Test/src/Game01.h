// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#pragma once
#include "Game.h"
#include "RenderSystem/VertexPostitionColor.h"
#include "RenderSystem/Color.h"
#include "RenderSystem/ConstantBuffer.h"

namespace Engine
{
	class Game01 : public Game
	{
	public:
		Game01(HINSTANCE hInstance, int cmdShow, int width, int height, LPCTSTR name);
		~Game01();
		void Load() override;
		void Update() override;
		void Draw()  override;

	private:
		VertexPositionColor vertices[6];

		std::unique_ptr<VertexBuffer> m_vertexBuffer;
		std::unique_ptr<ConstantBuffer> m_constantBuffer;
		ID3D11VertexShader* vertexShader = nullptr;
		ID3D11PixelShader* pixelShader = nullptr;
		ID3D11InputLayout* inputLayout = nullptr;
		
	};
}

