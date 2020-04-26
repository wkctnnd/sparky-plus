#include "Interpolator.h"
#include "keyvalue.h"
namespace sparky
{
	namespace animation
	{


		float LinearInterpolator::Evaluate(unsigned long currenttime)
		{
			float result = 0;
			int key;
			m_keyValues->FindKey(m_LastKey, currenttime, key);

			KeyValue& startkey = m_keyValues->GetKeyValue(key - 1);
			KeyValue& endkey = m_keyValues->GetKeyValue(key);

			unsigned long timeduration = endkey.time - startkey.time;
			float t = (float)(currenttime - startkey.time) / float(timeduration);
			result = t * startkey.value + (1 - t)*endkey.value;

			m_LastKey = key;
			return result;
		}


	}
}