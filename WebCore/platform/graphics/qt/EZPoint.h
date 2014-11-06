#ifndef EZPoint_h_
#define EZPoint_h_

#include "EZTypeDef.h"

namespace EZ 
{

class EZPoint 
{
public:
	EZPoint(EZ_INT32S x, EZ_INT32S y) :
		m_x(x), m_y(y)
	{ };

	EZ_INT32S x() { return m_x; }
	EZ_INT32S y() { return m_y; }
		
private:
	EZ_INT32S m_x, m_y;
};

}

#endif

