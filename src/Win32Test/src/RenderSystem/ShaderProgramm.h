#pragma once
#include "GraphicsDevice.h"
#include "ShaderCreateInfo.h"
namespace Engine
{
	class ShaderProgramm
	{

	private:
		ID3D11VertexShader* vertexShader = nullptr;
		ID3D11PixelShader* pixelShader = nullptr;
		ID3D11InputLayout* inputLayout = nullptr;
	public:
		ShaderProgramm(ShaderCreateInfo shaderCreateInfo, GraphicsDevice& graphicsDevice);
		~ShaderProgramm();

		ID3D11PixelShader* GetPixelShader() const { return pixelShader; }
		ID3D11VertexShader* GetVertexShader() const { return vertexShader; }
		ID3D11InputLayout* GetInputLayout() const { return inputLayout; }
	};

}