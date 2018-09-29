cbuffer buffer1 : register(b0)
{
	float4 Color1;
};

struct PSInput
{
	float4 Pos : SV_Position;
	float4 Color: COLOR;
};

float4 main(PSInput In) : SV_Target
{
	return Color1;
}