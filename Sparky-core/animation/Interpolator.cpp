#include "Interpolator.h"
#include "keyvalue.h"
#include "maths//util.h"
//https://yuese87.com/videos/21966/ed1864ec153f9af779208c8e1bab4e0a/
using namespace sparky::maths;
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

			t = Util::Max<float>(t, 1);

			result = (1 - t) * startkey.value + t * endkey.value;

			m_LastKey = key - 1;
			return result;
		}


	}
}