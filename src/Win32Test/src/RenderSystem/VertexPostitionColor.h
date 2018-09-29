#pragma once


struct VertexPositionColor
{
public:
	DirectX::XMFLOAT3 Position;
	DirectX::XMFLOAT4 Color;

	VertexPositionColor(DirectX::XMFLOAT3 Position, DirectX::XMFLOAT4 Color)
		:Position(Position), Color(Color)
	{
		
	}

	VertexPositionColor() { }

	static  const D3D11_INPUT_ELEMENT_DESC* GetInputLayout ()  { return &VertexPositionColor::vertexDesc[0]; }

private:
	// Version 1
	const static constexpr D3D11_INPUT_ELEMENT_DESC vertexDesc[]
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA,0 },

	 };



};


