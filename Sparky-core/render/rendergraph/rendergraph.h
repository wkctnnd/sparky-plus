#pragma once
#include <map>
#include <string>
namespace sparky
{
	namespace render
	{
		class RenderGraph
		{
		public:
			void Execute();
			void AddPass(std::string name, class Pass*);


		private:
			std::map<std::string, class Pass*> m_PassArray;
		};
	}
}