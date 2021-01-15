#pragma once
namespace sparky
{
	namespace world
	{
		class Actor;
	}
	namespace game
	{
		class Controller
		{
		public:
			void SetController(world::Actor* owner)
			{
				m_Owner = owner;
			}

		protected:
			world::Actor *m_Owner;
		};
	}
}