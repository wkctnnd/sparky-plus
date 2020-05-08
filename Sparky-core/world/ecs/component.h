#pragma once

//https://zhuanlan.zhihu.com/p/106946506


namespace sparky
{
	namespace ecs
	{
		class IComponent
		{
		public:
			virtual void Register() = 0;

			
		};
	}
}