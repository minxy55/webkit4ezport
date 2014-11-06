#ifndef EZRect_h_
#define EZRect_h_

#include "EZTypeDef.h"

namespace EZ
{

class EZRect
{
public:
	EZRect(EZ_INT32S x, EZ_INT32S y, EZ_INT32S w, EZ_INT32S h) :
		m_x(x), m_y(y), m_w(w), m_h(h)
	{ }
	EZ_INT32S x() { return m_x; }
	EZ_INT32S y() { return m_y; }
	EZ_INT32S width() { return m_w; }
	EZ_INT32S height() { return m_h; }
	
private:
	EZ_INT32S m_x, m_y, m_w, m_h;
};
	
}

#endif
