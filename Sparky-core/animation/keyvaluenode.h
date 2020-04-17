#pragma once
#include <vector>
namespace sparky
{
	namespace animation
	{
		enum KeyValueNodeType
		{
			Translate_Type,
			Scale_Type,
			Rotation_Type,

		};


		//ʵ����channel������ϵ
		class KeyValueNode
		{
		public:
			KeyValueNodeType GetType();

 
		private:
			KeyValueNodeType m_Type;
			class KeyValueCollection *m_KeyValueCollection;
			//std::vector<>
		};
	}
}
