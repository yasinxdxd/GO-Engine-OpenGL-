#ifndef GO_WINDOW_EVENT
#define GO_WINDOW_EVENT
#include "Core/Definitions.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace go
{
	class WindowEvent
	{
		explicit WindowEvent();

		//call backs:
		static void frame_buffer_size_callback(GLFWwindow* window, GOint width, GOint height);
		static void key_callback(GLFWwindow* window, GOint key, GOint scancode, GOint action, GOint mods);
		



	public:
		

		friend class Window;
	};


}




#endif //GO_WINDOW_EVENT