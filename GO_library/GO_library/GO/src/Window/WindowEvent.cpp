#include "Window/WindowEvent.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace go
{

	//call backs:
	void WindowEvent::frame_buffer_size_callback(GLFWwindow* window, GOint width, GOint height)
	{
		glViewport(0, 0, width, height);
	}

	


}