#ifndef GO_GUI
#define GO_GUI

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Window/Window.h"

namespace go
{
	

	class GUI
	{
	public:
		void render();
		static GUI* getInstance();
		void Init(go::Window& window);
		//
	private:
		GUI();
	public:
		~GUI();

	private:
		static GUI* m_instance;
	};


}
#endif // GO_GUI
