#pragma once
#include "../stdafx.h"


namespace Engine
{
	

	class VertexBuffer
	{
	public:
		VertexBuffer()
		{
			vertexBufferDesc = { 0 };
			vertexBuffer = nullptr;
		}

		~VertexBuffer()
		{
			SAFE_RELEASE(vertexBuffer);
		}

	private:

		ID3D11Buffer* vertexBuffer;
		D3D11_BUFFER_DESC vertexBufferDesc;

	public:
		template <typename TVertexType, size_t verticesCount>
	    //void SetData(ID3D11Device1& device1, TVertexType(&vertices)[verticesCount])
		void SetData(ID3D11Device1& device1, TVertexType* vertices)
		{
			
			vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc.ByteWidth = sizeof(TVertexType) * verticesCount;
			vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc.CPUAccessFlags = 0;
			vertexBufferDesc.MiscFlags = 0;

			D3D11_SUBRESOURCE_DATA InitData;
			InitData.pSysMem = vertices;
			InitData.SysMemPitch = 0;
			InitData.SysMemSlicePitch = 0;

			
			device1.CreateBuffer(&vertexBufferDesc, &InitData, &vertexBuffer);
			
			
		}

		ID3D11Buffer* const * GetVertexBuffer() noexcept { return &vertexBuffer; }
	};


}
