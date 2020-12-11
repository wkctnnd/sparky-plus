#pragma once
namespace sparky
{
	namespace world
	{
		class Actor;
		class AnimationComponent;
	}
	namespace game
	{
		class Controller
		{
		public:
			void SetOwner(world::AnimationComponent* owner)
			{
				m_Owner = owner;
			}

		protected:
			world::AnimationComponent *m_Owner;
		};
	}
}