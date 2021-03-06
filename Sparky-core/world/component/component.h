#pragma once

//https://zhuanlan.zhihu.com/p/106946506
#include <vector>
using namespace std;
namespace sparky
{
	namespace world
	{
		class Actor;

		enum ComponentType
		{
			CAMER_TYPE,
			TRANSFORM_TYPE,
			STATICMESHRENDERER_TYPE,
			RIGIDBODY_TYPE,
 
			ANIMATION_TYPE,
			SCRIPT_TYPE,		};
		class Component
		{
		public:
			Component(Actor* owner)
			{
				m_Enable = true;
				m_Owner = owner;
			}
			Actor* GetOwner() 
			{
				return m_Owner;
			}
			virtual ComponentType GetType() = 0;
			virtual void PreUpdate() = 0;
			virtual void Update() = 0;
			virtual void PostUpdate() = 0;
			void SetEnable(bool enable)
			{
				m_Enable = enable;
			}

			bool IsEnable()
			{
				return m_Enable;
			}
			//virtual SceneProxy GetSceneProxy() = 0;
			//Component GetParentComponent();
		protected:
			//std::vector<Component*> m_Children;
			Actor* m_Owner;
			bool m_Enable;
			
		};
	}
}