#pragma once

struct ShaderCreateInfo
{
	const char* vsPath;
	const char* psPath;
	const D3D11_INPUT_ELEMENT_DESC* inputDesc;
};