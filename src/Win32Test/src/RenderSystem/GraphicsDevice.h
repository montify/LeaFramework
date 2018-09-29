// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#pragma once
#include "RenderForm.h"
#include "VertexBuffer.h"

namespace Engine
{
	
	class GraphicsDevice
	{
	public:
		std::shared_ptr<RenderForm> renderForm;
		
	public:
	    GraphicsDevice(std::shared_ptr<RenderForm>& renderForm);
		~GraphicsDevice();
		void Present(bool isVSync);
	
	private:
		void Init();
		
		// Render Commands
	public: 
		void Clear(std::array<float, 3>& clearColor);
		void SetVertexBuffer(VertexBuffer& inVertexBuffer, UINT inSizeOfVertex);
		void SetVertexShader(ID3D11VertexShader& inVertexShader) const;
		void SetPixelShader(ID3D11PixelShader& inPixelShader) const;
		//ID3D11Device& GetDevice() const { return *m_device; };
		ID3D11Device1& GetDevice1() const { return *m_device1; };
		//ID3D11DeviceContext& GetContext() const { return *m_deviceContext; };
		ID3D11DeviceContext1& GetContext1() const { return *m_deviceContext1; };

	private:
		ID3D11Device* m_device;
		ID3D11Device1* m_device1;
		ID3D11DeviceContext1* m_deviceContext1;
		IDXGISwapChain* m_swapChain;
		ID3D11DeviceContext* m_deviceContext;
		ID3D11RenderTargetView* m_renderTargetView;
		ID3D11Texture2D* m_depthStencilBuffer;
		ID3D11Texture2D *pBackBuffer;
	};

}