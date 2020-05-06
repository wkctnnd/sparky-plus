#pragma once
#include "animationlayer.h"
#include "keyvaluenode.h"
namespace sparky
{
	namespace animation
	{


		bool AnimationLayer::GetLoop() const
		{
			return false;
		}
		void AnimationLayer::SetLoop(bool loop)
		{

		}

		void AnimationLayer::SetWeight(float weight)
		{

		}

		bool AnimationLayer::GetWeight()const
		{
			return false;
		}

		/*std::vector<Interpolator<float>*>  AnimationLayer::GetFloatInterpolator()
		{
			std::vector<Interpolator<float>*> interpolator;
			for (unsigned int i = 0; i < m_FloatProperties.size(); i++)
			{
				auto temp = m_FloatProperties[i]->GetInterpolator(m_FloatProperties[i]);
				interpolator.push_back(temp);
			}
			return interpolator;
		}

		std::vector<Interpolator<float3>*>  AnimationLayer::Getfloat3Interpolator()
		{
			std::vector<Interpolator<float3>*> interpolator;
			for (unsigned int i = 0; i < m_float3Properties.size(); i++)
			{
				interpolator.push_back(m_float3Properties[i]->GetInterpolator(m_float3Properties[i]));
			}
			return interpolator;
		}

		std::vector<Interpolator<Quaternion>*>  AnimationLayer::GetQuatInterpolator()
		{
			std::vector<Interpolator<Quaternion>*> interpolator;
			for (unsigned int i = 0; i < m_QuatProperties.size(); i++)
			{
				interpolator.push_back(m_QuatProperties[i]->GetInterpolator(m_QuatProperties[i]));
			}
			return interpolator;
		}*/
		void AnimationLayer::AddKeyValueNode(std::string name, KeyValueNodeBase* keyvaluenode)
		{
			m_KeyValueNodeBaseArray.push_back(keyvaluenode);
			auto it = m_KeyValueNodeBaseMap.find(name);
			if (it != m_KeyValueNodeBaseMap.end())
			{
				m_KeyValueNodeBaseMap.insert(std::make_pair(name, std::vector<KeyValueNodeBase*>()));
			}

			m_KeyValueNodeBaseMap[name].push_back(keyvaluenode);
			//m_KeyValueNodeBaseMap.insert(make_pair(name, keyvaluenode));
		}

		KeyValueNodeBase* AnimationLayer::GetKeyValueNode(std::string name, PropertyType type)
		{
			auto it = m_KeyValueNodeBaseMap.find(name);
			if (it == m_KeyValueNodeBaseMap.end())  return 0;
			
			auto& nodearray = it->second;
			for (unsigned int i = 0; i < nodearray.size(); i++)
			{
				if (nodearray[i]->GetType() == type)
				{
					return nodearray[i];
				}
			}

			return 0;
		}

		//std::vector<InterpolatorBase*> AnimationLayer::GetInterPolator()
		//{
		//	std::vector<InterpolatorBase*> interpolator;
		//	//for (unsigned int i = 0; i < m_FloatProperties.size(); i++)
		//	//{
		//	//	auto temp = m_FloatProperties[i]->GetInterpolator(m_FloatProperties[i]);
		//	//	//interpolator.push_back(temp);
		//	//}
 
		//	//for (unsigned int i = 0; i < m_QuatProperties.size(); i++)
		//	//{
		//	//	//interpolator.push_back(m_float3Properties[i]->GetInterpolator(m_QuatProperties[i]));
		//	//}
 
		//	//for (unsigned int i = 0; i < m_QuatProperties.size(); i++)
		//	//{
		//	//	//interpolator.push_back(m_QuatProperties[i]->GetInterpolator(m_QuatProperties[i]));
		//	//}
		//	for(unsigned int i=0;i<m_KeyValueCollectionArray.size();i++)
		//		interpolator.push_back(m_KeyValueCollectionArray[i]->GetInterpolator(m_KeyValueCollectionArray[i]));
		//	return interpolator;
		//}

		void AnimationLayer::Update(unsigned long elapse)
		{
	
		}
	}
}