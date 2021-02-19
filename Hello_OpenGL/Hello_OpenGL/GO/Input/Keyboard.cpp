#include "Keyboard.h"
#include <GLFW/glfw3.h>

namespace go
{
	
	
	
	GObool Keyboard::isKeyPressed(go::Keyboard::Key key)
	{
		m_key = key;
		return is_key_pressed;
	}
	

	//callbacks:
	void Keyboard::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == m_key && action == GLFW_PRESS)
			is_key_pressed = true;
		else
			is_key_pressed = false;
	}

}