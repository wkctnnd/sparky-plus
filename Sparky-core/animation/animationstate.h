#pragma once
#include <string>
namespace sparky
{
	namespace animation
	{
		class AnimationState
		{
		public:
			const std::string& GetAnimationName() const;
			bool GetLoop() const;
			void SetLoop(bool loop);

			void SetWeight(float weight);
			bool GetWeight()const;

		protected:
			std::string m_AnimationName;
			float m_Weight;
			bool m_Loop;
			bool m_Enabled;

		};
	}
}
