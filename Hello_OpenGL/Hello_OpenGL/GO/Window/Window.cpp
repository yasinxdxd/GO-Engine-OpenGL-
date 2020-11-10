#include "Window/Window.h"

namespace go
{
	Window::Window(GOuint width, GOuint height, GOcchar* title)
	{
		m_size.x = width;
		m_size.y = height;
		m_title = title;
		m_aspectRatio = (GOfloat)m_size.x / (GOfloat)m_size.y;
		Init();
		m_close = (glfwWindowShouldClose(m_window)) ? true : false;
	}

	Window::Window(Vec2ui screen_size, GOcchar* title)
	{
		m_size = screen_size;
		m_title = title;
		Init();
		m_close = (glfwWindowShouldClose(m_window)) ? true : false;
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	bool Window::Init()
	{
		/*INIT GLFW*/
		if (!glfwInit())
		{
			std::cerr << "GLFW could not initialize!" << std::endl;
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		/*init the window*/
		m_window = glfwCreateWindow(m_size.x, m_size.y, m_title.c_str(), NULL, NULL);


		if (!m_window)
		{
			std::cout << "Window could not initialize!" << std::endl;
			glfwTerminate();
		}

		glfwMakeContextCurrent(m_window);

		/*init the GLAD*/
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cerr << "GLAD could not initialize!" << std::endl;
			return false;
		}

		glViewport(0, 0, m_size.x, m_size.y);


		return true;

	}


	//Getters:
	GOuint Window::getWidth() const { return m_size.x; }
	GOuint Window::getHeight() const { return m_size.y; }

	//Setters:

	//Others:
	void Window::pollEvent()
	{
		glfwPollEvents();
		m_close = (glfwWindowShouldClose(m_window)) ? true : false;
		glfwSetFramebufferSizeCallback(m_window, frame_buffer_size_callback);
		glfwSetKeyCallback(m_window, key_callback);
	}

	GObool Window::isClose() const { return m_close; }

	void Window::clear()
	{
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Window::render(go::Renderable& renderable)
	{
		renderable.draw(m_size);
	}
	void Window::display()
	{
		glfwSwapBuffers(m_window);
	}


	//call backs:
	void Window::frame_buffer_size_callback(GLFWwindow* window, GOint width, GOint height)
	{
		glViewport(0, 0, width, height);
	}

	void Window::key_callback(GLFWwindow* window, GOint key, GOint scancode, GOint action, GOint mods)
	{
		if (key == GLFW_KEY_E && action == GLFW_PRESS)
			std::cout << "E" << std::endl;
	}

}