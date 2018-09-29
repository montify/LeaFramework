// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Game01.h"



namespace Engine
{
	Game01::Game01(HINSTANCE hInstance, int cmdShow, int width, int height, LPCTSTR name)
		: Game(hInstance, cmdShow, width , height, name)
	{
		
	}

	void Game01::Load()
	{
		vertices[0].Position = DirectX::XMFLOAT3(-0.5f, -0.5f, 1);
		vertices[0].Color = DirectX::XMFLOAT4(1,0,0,1);
			
		vertices[1].Position = DirectX::XMFLOAT3(-0.5, 0.5f, 0);
		vertices[1].Color = DirectX::XMFLOAT4(0, 1, 0, 1);

		vertices[2].Position = DirectX::XMFLOAT3(0.5f, -0.5f, 0);
		vertices[2].Color = DirectX::XMFLOAT4(0, 0, 1, 1);
		

		vertices[3].Position = DirectX::XMFLOAT3(0.5f, -0.5f, 0);
		vertices[3].Color = DirectX::XMFLOAT4(0, 0, 1, 1);

		vertices[4].Position = DirectX::XMFLOAT3(-0.5, 0.5f, 0);
		vertices[4].Color = DirectX::XMFLOAT4(0, 1, 0, 1);

		vertices[5].Position = DirectX::XMFLOAT3(0.5f, 0.5f, 0);
		vertices[5].Color = DirectX::XMFLOAT4(0, 0, 1, 1);
		
	

		// CUSTOM VB
	    m_vertexBuffer = std::make_unique<VertexBuffer>();
		m_vertexBuffer->SetData<VertexPositionColor, 6>(graphicsDevice->GetDevice1(), vertices);
		

		std::ifstream vsFile("C:\\Users\\alex\\source\\repos\\Win32Test\\Debug\\basicVS.cso", std::ios::binary);
		std::ifstream psFile("C:\\Users\\alex\\source\\repos\\Win32Test\\Debug\\basicPS.cso", std::ios::binary);
		std::vector<char> vsData = { std::istreambuf_iterator<char>(vsFile), std::istreambuf_iterator<char>() };
		std::vector<char> psData = { std::istreambuf_iterator<char>(psFile), std::istreambuf_iterator<char>() };
		
		
	    graphicsDevice->GetDevice1().CreateVertexShader(vsData.data(), vsData.size(), nullptr, &vertexShader);
		graphicsDevice->GetDevice1().CreatePixelShader(psData.data(), psData.size(), nullptr, &pixelShader);
		
		graphicsDevice->GetDevice1().CreateInputLayout(VertexPositionColor::vertexDescV1, 2, vsData.data(), vsData.size(), &inputLayout);
	
		struct CBufferStruct
		{
			DirectX::XMFLOAT4 Color;
		};

		auto buffer = CBufferStruct();
		buffer.Color = DirectX::XMFLOAT4(1, 1, 0, 1);

		m_constantBuffer = std::make_unique<ConstantBuffer>(graphicsDevice->GetDevice1());
		m_constantBuffer->Write<CBufferStruct>(&buffer);
	
		graphicsDevice->GetContext1().PSSetConstantBuffers(0, 1, m_constantBuffer->GetBuffer());
	}

	void Game01::Update()
	{
		
	}

	void Game01::Draw()
	{
		graphicsDevice->Clear(Color::CornFlowerBlue);

		const UINT stride = sizeof(vertices[0]);
		const UINT offset = 0;

	    graphicsDevice->GetContext1().IASetInputLayout(inputLayout);
	

		graphicsDevice->SetVertexShader(*vertexShader);
		graphicsDevice->SetPixelShader(*pixelShader);
		graphicsDevice->SetVertexBuffer(*m_vertexBuffer, sizeof(VertexPositionColor));
	
		
		graphicsDevice->GetContext1().IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		graphicsDevice->GetContext1().Draw(6, 0);
	}

	Game01::~Game01()
	{
		SAFE_RELEASE(vertexShader);
		SAFE_RELEASE(pixelShader);
		SAFE_RELEASE(inputLayout);
		
	}
}
