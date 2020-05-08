#pragma once
#include <vector>
namespace sparky
{
	namespace render
	{
		class  Scene
		{
		public:
			void AddSceneProxy(class SceneProxy* proxy);
			
			
			 
		private:
			std::vector<class SceneProxy*> m_SceneProxyArray;
		};
	}
}