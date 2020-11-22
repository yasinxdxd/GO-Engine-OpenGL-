#ifndef GO_MOUSE_H
#define GO_MOUSE_H


#include "Math/Vectors.h"
#include "GLFW/glfw3.h"

namespace go
{

	class Mouse
	{
	public:
		enum MouseButton
		{ Left, Right };

	public:
		Mouse();
		static Vec2d& getPosition(void);
		static GObool isMousePressed(go::Mouse::MouseButton);
	


	private:
		//returning values
		static inline GObool is_mouse_pressed; //static GObool isMousePressed(go::Mouse::MouseButton);
		static inline MouseButton m_button;


	private:
		static inline go::Vec2d m_position;

	private:
		//callbacks:
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		static void mouse_button_callback(GLFWwindow* window, GOint button, GOint action, GOint mods);



	friend class Window;
	//friend class WindowEvent;
	};

}



#endif