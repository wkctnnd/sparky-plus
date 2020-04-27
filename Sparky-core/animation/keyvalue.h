#pragma once
#include <string>
#include <vector>
#include "Interpolator.h"


namespace sparky
{
	namespace animation
	{
 




		struct KeyValue
		{
			KeyValue(float v, unsigned int t)
			{
				value = v;
				time = t;
			}
			unsigned int time;//millisecond
			float value;
		};


		//class KeyValueCollectionBase
		//{
		//public:
		//	virtual InterpolatorBase * GetInterpolator(KeyValueCollectionBase* keyvalues) { return 0; }
		//	int GetUniqueKey() { return m_UniqueKey; }
		//protected:
		//	int m_UniqueKey;
		//};

	
		class KeyValueCollection  
		{
		public:

			//Interpolator<datatype>* GetInterpolator(KeyValueCollection<datatype>* property);

			InterpolatorBase* GetInterpolator(KeyValueCollection* keyvalues);

				// T& Evaluate(unsigned long time);
			void SetInterpolatorType(InterpolatorType type);

			void AddKeyValue(KeyValue& keyvalue);
			
			// float GetValue() { return m_Value; }
			// void BindData(KeyValueSet<datatype>*  data);

			inline void FindKey(int startpos, unsigned long elapsetime, int& key)
			{
				if (elapsetime > m_KeyValues[m_KeyValues.size()-1].time)
				{
					key = m_KeyValues.size() - 1;
					return;
				}

				int find = 0;
				for (int i = startpos+1; i < m_KeyValues.size(); i++)
				{
					if (m_KeyValues[i].time > elapsetime)
					{
						if (i == 22 && m_KeyValues.size() == 23)
						{
							int  a = 1;
						}
						key = i;
						find = 1;
						break;
					}
				}
				if (find == 0)
				{
					int a = 1;
				}
			}

			inline KeyValue& GetKeyValue(int pos)
			{
				return m_KeyValues[pos];
			}

		private:
			std::vector<KeyValue>  m_KeyValues;
			InterpolatorType  m_Type;
			//datatype m_Value;
			int m_UniqueKey;
			std::string m_Name;
			
		};

		/*template< class datatype>
		void sparky::animation::Property<datatype>::AddKeyValue(KeyValue<datatype>& keyvalue)
		{
		
		}
		
		template< class datatype>
		void sparky::animation::Property<datatype>::SetInterpolatorType(InterpolatorType type)
		{
		
		}
		
		template< class datatype>
		sparky::animation::Interpolator<datatype>* sparky::animation::Property<datatype>::GetInterpolator(Property<datatype>* property)
		{
		return nullptr;
		}*/
		

	}
}
//#include "keyvalue.inl"
