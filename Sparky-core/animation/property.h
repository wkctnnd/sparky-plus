#pragma once
#include "property.h"

template<class datatype>
class Property
{
public:
	datatype EvaluateValue(unsigned long time);


private:
	std::vector<class KeyValueNode*> m_KeyValueNodeArray;
};


template<class datatype>
datatype Property::EvaluateValue(unsigned long time)
{

}