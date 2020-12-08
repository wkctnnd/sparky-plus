#pragma once
namespace sparky
{
	namespace game
	{
		class Controller
		{
		public:
			void SetController(Actor* owner)
			{
				m_Owner = owner;
			}

		protected:
			Actor *m_Owner;
		};
	}
}