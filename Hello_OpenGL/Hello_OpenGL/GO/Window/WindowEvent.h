#ifndef GO_WINDOW_EVENT
#define GO_WINDOW_EVENT
#include "Core/Definitions.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace go
{
	class WindowEvent
	{
		explicit WindowEvent();

		//call backs:
		static void frame_buffer_size_callback(GLFWwindow* window, GOint width, GOint height);

	public:
		

		friend class Window;
	};


}




#endif //GO_WINDOW_EVENT