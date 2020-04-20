#pragma once



namespace sparky
{
	namespace render {

		class SkeletalMesh
		{
		public:

			class SkinMesh* GetRenderable();
			void Update();
		private:

			class SkinMesh* m_SkinMesh;
			class Skeleton* m_Skeleton;
		};
	}
}