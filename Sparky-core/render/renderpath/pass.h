#pragma once
namespace sparky
{
	namespace world
	{
		class PrimitiveSceneProxy;
		class Scene;
	}
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
			virtual void AddMeshDrawCommand(world::PrimitiveSceneProxy* psp, world::Scene* scene) = 0;
			virtual void Process() = 0;


		};
	}
}
