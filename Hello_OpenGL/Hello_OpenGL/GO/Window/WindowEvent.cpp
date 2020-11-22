#include "WindowEvent.h"
#include <iostream>

namespace go
{

	//call backs:
	void WindowEvent::frame_buffer_size_callback(GLFWwindow* window, GOint width, GOint height)
	{
		glViewport(0, 0, width, height);
	}

	void WindowEvent::key_callback(GLFWwindow* window, GOint key, GOint scancode, GOint action, GOint mods)
	{
		if (key == GLFW_KEY_E && action == GLFW_PRESS)
			std::cout << "E" << std::endl;
	}

	


}