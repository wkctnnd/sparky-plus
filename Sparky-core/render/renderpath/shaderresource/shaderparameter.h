#pragma once
enum ParameterType
{
	TEXTURE_TYPE,
	FLOAT_TYPE,
	FLOAT4_TYPE,
	FLOAT3_TYPE
};
class UniformParameter
{
	void Add(ParameterType type£¬)
};


template<class UniformParameter>
class TUniformBuffer
{
public:
	static TUniformBuffer<UniformParameter>* CreateUniform(UniformParameter parameter);
};