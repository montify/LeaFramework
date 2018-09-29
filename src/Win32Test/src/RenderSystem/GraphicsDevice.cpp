// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "../stdafx.h"
#include "GraphicsDevice.h"


namespace Engine
{

	GraphicsDevice::GraphicsDevice(std::shared_ptr<RenderForm>& renderForm)
		:renderForm(renderForm)
	{
		Init();

	/*	renderForm->OnWindowSizeChanged.Subscribe("OnWindowSizeChanged", [](Alex::EventArgs e) 
		{
			
		});
		*/
	}


	GraphicsDevice::~GraphicsDevice()
	{
		SAFE_RELEASE(m_device)
		SAFE_RELEASE(m_swapChain)
		SAFE_RELEASE(m_deviceContext)
		SAFE_RELEASE(m_deviceContext1)
		SAFE_RELEASE(m_renderTargetView)
		SAFE_RELEASE(pBackBuffer)
		SAFE_RELEASE(m_device)
		SAFE_RELEASE(m_device1)
	}

	void GraphicsDevice::Init()
	{
		const auto featureLevel = D3D_FEATURE_LEVEL_11_1;
		m_device = nullptr;
		m_swapChain = nullptr;
		m_deviceContext = nullptr;
		m_renderTargetView = nullptr;
		m_depthStencilBuffer = nullptr;

		DXGI_SWAP_CHAIN_DESC sd;
		ZeroMemory(&sd, sizeof(sd));
		sd.BufferCount = 1;
		sd.BufferDesc.Width = renderForm->GetWidth();
		sd.BufferDesc.Height = renderForm->GetHeight();
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.OutputWindow = renderForm->GetHandle();
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.Windowed = TRUE;
#ifdef _DEBUG
		auto flags = D3D11_CREATE_DEVICE_BGRA_SUPPORT | D3D11_CREATE_DEVICE_DEBUG;
#else
		auto flags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#endif
		
		auto result = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags, &featureLevel, 1,
			D3D11_SDK_VERSION, &sd, &m_swapChain, &m_device, nullptr, &m_deviceContext);

		if (FAILED(result))
			__debugbreak();

		if (FAILED(m_device->QueryInterface(__uuidof(ID3D11Device1), reinterpret_cast<void**>(&m_device1))))
			__debugbreak();

		m_device1->GetImmediateContext1(&m_deviceContext1);

		if (FAILED(m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer)))
			__debugbreak();

		if (FAILED(m_device->CreateRenderTargetView(pBackBuffer, nullptr, &m_renderTargetView)))
			__debugbreak();

		m_deviceContext->OMSetRenderTargets(1, &m_renderTargetView, nullptr);
		
		D3D11_VIEWPORT vp;
		vp.Width = static_cast<FLOAT>(renderForm->GetWidth());
		vp.Height = static_cast<FLOAT>(renderForm->GetHeight());
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		m_deviceContext->RSSetViewports(1, &vp);
	}

	void GraphicsDevice::Present(bool isVSync)
	{
		if(isVSync)
			m_swapChain->Present(1, 0);
		else
			m_swapChain->Present(0, 0);
	}

	void GraphicsDevice::Clear(std::array<float, 3>& clearColor)
	{
		m_deviceContext1->ClearRenderTargetView(m_renderTargetView, clearColor.data());
	}

	void GraphicsDevice::SetVertexBuffer(VertexBuffer& inVertexBuffer, UINT inVertexStructSize)
	{
		const UINT offset = 0;
		m_deviceContext1->IASetVertexBuffers(0, 1, inVertexBuffer.GetVertexBuffer(), &inVertexStructSize, &offset);
	}

	void GraphicsDevice::SetVertexShader(ID3D11VertexShader& inVertexShader) const
	{
		m_deviceContext1->VSSetShader(&inVertexShader, nullptr, 0);
	}
	void GraphicsDevice::SetPixelShader(ID3D11PixelShader& inPixelShader) const
	{
		m_deviceContext1->PSSetShader(&inPixelShader, nullptr, 0);
	}

}

