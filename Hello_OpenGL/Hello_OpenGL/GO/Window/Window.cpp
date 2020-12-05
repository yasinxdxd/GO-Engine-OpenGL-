#include "Window/Window.h"
#include "Input/Mouse.h"
#include "Input/Keyboard.h"


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
		/*init GLFW*/
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

		/*init GLAD*/
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

	Vec3si Window::getColor() const
	{
		return m_colors;
	}

	GOfloat Window::getFPS() const
	{
		return m_FPS;
	}

	void Window::setFPS(GOfloat FPS)
	{
		m_FPS = FPS;
	}

	void Window::setColor(go::Vec3si color)
	{
		m_colors = color;
	}

	//Setters:

	//Others:
	void Window::pollEvent()
	{
		glfwPollEvents();
		m_close = (glfwWindowShouldClose(m_window)) ? true : false;
		
		glfwSetFramebufferSizeCallback(m_window, WindowEvent::frame_buffer_size_callback);
		
		glfwSetKeyCallback(m_window, go::Keyboard::key_callback);
		
		//glfwSetInputMode(m_window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_FALSE);//GLFW_TRUE
		glfwSetCursorPosCallback(m_window, Mouse::cursor_position_callback);
		glfwGetCursorPos(m_window, &go::Mouse::m_position.x, &go::Mouse::m_position.y);
		glfwSetMouseButtonCallback(m_window, Mouse::mouse_button_callback);
	}

	GObool Window::isClose() const 
	{ return m_close; }


	void Window::clear()
	{
		glClearColor((GOfloat)m_colors.x/255, (GOfloat)m_colors.y / 255, (GOfloat)m_colors.z / 255, 0);
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


	

}