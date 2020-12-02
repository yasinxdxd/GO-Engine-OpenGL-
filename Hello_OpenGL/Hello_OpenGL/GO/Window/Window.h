#ifndef GO_WINDOW_H
#define GO_WINDOW_H

#include "Math/Vectors.h"
#include "Graphics/Renderable.h"
#include "Window/WindowEvent.h"
#include "GUI/GUI.h"
#include <iostream>
#include <string>

namespace go
{
	class Window
	{
	public:

		Window(GOuint width, GOuint height, GOcchar* title);
		Window(Vec2ui screen_size, GOcchar* title);
		~Window();

		//Getters:
		GOuint getWidth() const;
		GOuint getHeight() const;
		//Setters:
		void setFPS();

		//Others:
		void pollEvent();
		GObool isClose() const;
		void clear();
		void clear(GOsint r, GOsint g, GOsint b);
		void render(go::Renderable&);
		void display();

	private:
		GObool Init();

	private:
		

	private:
		GLFWwindow* m_window;
		Vec2ui m_size;
		std::string m_title;
	private:
		GObool m_close;
		GOfloat m_aspectRatio;
		GOsint m_FPS;
	
		
	friend class GUI;
	};

}

#endif //GO_WINDOW_H