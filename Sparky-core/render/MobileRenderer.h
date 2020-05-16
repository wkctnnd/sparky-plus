#pragma once
#include "Renderer.h"
#include <vector>
namespace sparky
{
	namespace render
	{
		class  MobileRenderer:public Renderer
		{
		public:

			virtual void Render(std::vector<class View*>);


		private:

		};
	}
}