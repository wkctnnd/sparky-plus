#pragma once
#include <vector>
#include "keyvalue.h"
#include "maths/quaternion.h"
#include "maths/vec3.h"
using namespace sparky::maths;
namespace sparky
{
	namespace animation
	{
		class AnimationLayer
		{
		public:
			bool GetLoop() const;
			void SetLoop(bool loop);

			void SetWeight(float weight);
			bool GetWeight()const;


			void AddKeyValueNode(class KeyValueNodeBase* keyvaluenode);
			//Property<float> GetFloatProperties();
			//std::vector<Interpolator<float>*> GetFloatInterpolator();
			//std::vector<Interpolator<vec3>*> GetVec3Interpolator();
			//std::vector<Interpolator<Quaternion>*> GetQuatInterpolator();

			//std::vector<InterpolatorBase*> GetInterPolator();
			void Update(unsigned long elapse);
			int GetKeyValueNodeCount() { return m_KeyValueNodeBaseArray.size(); }
			KeyValueNodeBase* GetKeyValueNode(int id) { return m_KeyValueNodeBaseArray[id]; }
		private:

			std::vector<std::string>  m_PropertyName;

			//std::vector<KeyValueCollection*> m_KeyValueCollectionArray;
			std::vector<KeyValueNodeBase*> m_KeyValueNodeBaseArray;
		/*	std::vector<KeyValueCollection*> m_FloatProperties;
			std::vector<KeyValueCollection<Quaternion>*> 	m_QuatProperties;
			std::vector<KeyValueCollection<vec3>*> m_Vec3Properties;*/
			float m_BlendWeight;
			bool m_Loop;

			
		};



	}
}