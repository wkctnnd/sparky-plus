#pragma once
namespace sparky
{
	namespace render
	{
		enum PassType
		{
			LightPass,
			ShadowPass,

			PassNum
		};
		class Pass
		{
		public:
			virtual void AddMeshDrawCommand() = 0;
			virtual void Process() = 0;


		};
	}
}
