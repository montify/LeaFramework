struct VSInput
{
	float3 Pos : POSITION;
	float4 Color : COLOR;
};
struct VSOutput
{
	float4 Pos : SV_Position;
	float4 Color: COLOR;
};

VSOutput main(VSInput In)
{
	VSOutput Out;

	Out.Pos = float4(In.Pos.x, In.Pos.y, In.Pos.z, 1);
	Out.Color = In.Color;

	return Out;
}