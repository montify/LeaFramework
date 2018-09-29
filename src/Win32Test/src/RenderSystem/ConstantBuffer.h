#pragma once
#include "../stdafx.h"

class ConstantBuffer
{
private:
	ID3D11Buffer* m_buffer;
	ID3D11Device1& m_device;
public:
	ConstantBuffer(ID3D11Device1& InDevice)
		:m_device(InDevice)
	{
	
	}

	~ConstantBuffer()
	{
		SAFE_RELEASE(m_buffer);
	}

	ID3D11Buffer* const * GetBuffer() const
	{
		return &m_buffer;
	}

	template<typename T>
	void Write(T* constanStruct)
	{
		// Fill in a buffer description.
		D3D11_BUFFER_DESC cbDesc;
		cbDesc.ByteWidth = sizeof(T);
		cbDesc.Usage = D3D11_USAGE_DYNAMIC;
		cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		cbDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		cbDesc.MiscFlags = 0;
		cbDesc.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA InitData;
		InitData.pSysMem = constanStruct;
		InitData.SysMemPitch = 0;
		InitData.SysMemSlicePitch = 0;

		assert(m_device.CreateBuffer(&cbDesc, &InitData, &m_buffer) == S_OK);
	
	}
private:
	
};