#pragma once
#include <vector>
#include "keyvalue.h"
#include "maths/quaternion.h"
#include "maths/vec3.h"
#include "global.h"
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

			void SetName(std::string name) { m_Name = name; }
			std::string GetName() { return m_Name; }
			void AddKeyValueNode(std::string name, class KeyValueNodeBase* keyvaluenode);
			//Property<float> GetFloatProperties();
			//std::vector<Interpolator<float>*> GetFloatInterpolator();
			//std::vector<Interpolator<float3>*> Getfloat3Interpolator();
			//std::vector<Interpolator<Quaternion>*> GetQuatInterpolator();

			//std::vector<InterpolatorBase*> GetInterPolator();
			void Update(unsigned long elapse);
			int GetKeyValueNodeCount() { return m_KeyValueNodeBaseArray.size(); }

			//暂时用骨骼名称为索引
			KeyValueNodeBase* GetKeyValueNode(std::string name, PropertyType type);
			KeyValueNodeBase* GetKeyValueNode(int id) { return m_KeyValueNodeBaseArray[id]; }
		private:

			std::vector<std::string>  m_PropertyName;

			//std::vector<KeyValueCollection*> m_KeyValueCollectionArray;
			std::vector<KeyValueNodeBase*> m_KeyValueNodeBaseArray;


			//同一名字骨骼可能有不同属性
			std::map<std::string, std::vector<KeyValueNodeBase*>> m_KeyValueNodeBaseMap;
		/*	std::vector<KeyValueCollection*> m_FloatProperties;
			std::vector<KeyValueCollection<Quaternion>*> 	m_QuatProperties;
			std::vector<KeyValueCollection<float3>*> m_float3Properties;*/
			float m_BlendWeight;
			bool m_Loop;

			std::string m_Name;
		};



	}
}