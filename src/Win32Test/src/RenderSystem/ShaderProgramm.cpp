#include "../stdafx.h"
#include "ShaderProgramm.h"
#include "VertexPostitionColor.h"


namespace Engine
{
	ShaderProgramm::ShaderProgramm(ShaderCreateInfo shaderCreateInfo, GraphicsDevice& graphicsDevice)
	{
		//C:\\Users\\alex\\source\\repos\\Win32Test\\Debug\\basicVS.cso
		std::ifstream vsFile(shaderCreateInfo.vsPath, std::ios::binary);
		std::ifstream psFile(shaderCreateInfo.psPath, std::ios::binary);

		std::vector<char> vsdata = { std::istreambuf_iterator<char>(vsFile), std::istreambuf_iterator<char>() };
		std::vector<char> psdata = { std::istreambuf_iterator<char>(psFile), std::istreambuf_iterator<char>() };
		
		graphicsDevice.GetDevice1().CreateVertexShader(vsdata.data(), vsdata.size(), nullptr, &vertexShader);
		graphicsDevice.GetDevice1().CreatePixelShader(psdata.data(), psdata.size(), nullptr, &pixelShader);

		graphicsDevice.GetDevice1().CreateInputLayout(shaderCreateInfo.inputDesc, 2, vsdata.data(), vsdata.size(), &inputLayout);
	}


	

	ShaderProgramm::~ShaderProgramm()
	{
		SAFE_RELEASE(vertexShader);
		SAFE_RELEASE(pixelShader);
		SAFE_RELEASE(inputLayout);
	}
}
