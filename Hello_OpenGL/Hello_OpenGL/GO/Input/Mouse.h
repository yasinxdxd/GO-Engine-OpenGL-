#ifndef GO_MOUSE_H
#define GO_MOUSE_H


#include "Window/Window.h"


namespace go
{

	class Mouse
	{
	public:
		Mouse();
		//inline static Vec2d& getPosition();
		static inline go::Vec2d position;


	friend class Window;
	};

}



#endif