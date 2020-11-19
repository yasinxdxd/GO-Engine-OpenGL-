#ifndef GO_MOUSE_H
#define GO_MOUSE_H


#include "Math/Vectors.h"


namespace go
{

	class Mouse
	{
	public:
		Mouse();
		static Vec2d& getPosition(void);
	
	private:
		static inline go::Vec2d m_position;

	friend class Window;
	};

}



#endif