#include "WindowEvent.h"
#include <iostream>

namespace go
{

	//call backs:
	void WindowEvent::frame_buffer_size_callback(GLFWwindow* window, GOint width, GOint height)
	{
		glViewport(0, 0, width, height);
	}

	


}