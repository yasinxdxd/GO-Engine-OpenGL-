#include "GUI/GUI.h"

go::GUI* go::GUI::m_instance = nullptr;

namespace go
{
	GUI::GUI()
	{
		
	}

	void GUI::Init(go::Window& window)
	{
		IMGUI_CHECKVERSION();

		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls


		// Setup Platform/Renderer backends
		ImGui_ImplGlfw_InitForOpenGL(window.m_window, true);
		ImGui_ImplOpenGL3_Init("#version 330 core");

		// Setup Dear ImGui style
		//ImGui::StyleColorsDark();
		ImGui::StyleColorsLight();
	}
	
	GUI::~GUI()
	{
		delete this->m_instance;
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	
	void GUI::render()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		{

			ImGui::Begin("Window");
			ImGui::Text("Proporites: ");
			//ImGui::SliderFloat("SizeX", &sliderfloatX, 0.f, 1280.f);
			//ImGui::SliderFloat("SizeY", &sliderfloatY, 0.f, 720.f);
			//ImGui::SliderAngle("Angle", &angle);
			//ImGui::SliderInt("Scale", &scale, 1, 4);

			ImGui::End();

		}


		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	GUI* GUI::getInstance()
	{
		return m_instance = m_instance == nullptr ? new GUI() : m_instance;
	}
}