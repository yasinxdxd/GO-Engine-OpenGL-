#pragma once
#ifndef GO_SHADER_H
#define GO_SHADER_H
//#define GLFW_INCLUDE_NONE

#include "Core/Definitions.h"
#include "Math/Vectors.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <fstream>

namespace go
{

	class Shader
	{
	public:
		Shader(GOcchar* vertex_path, GOcchar* frag_path);
		~Shader();
		void use();

	public:
		GOuint getProgramID() { return m_ProgramID; }
	public:
		void setVertices(go::Vec2f position, go::Vec2f size, go::Vec2ui windowsSize);

	public:
		void setBool(const std::string& name, GObool value) const;
		void setInt(const std::string& name, GOint value) const;
		void setFloat(const std::string& name, GOfloat value) const;
		void setFloat_4(const std::string& name, GOfloat r, GOfloat g, GOfloat b, GOfloat a) const;

	private:
		GObool createShader(GOcchar* vertex_path, GOcchar* frag_path);
		GObool attachShader();
		GObool setBuffers();
		std::string loadFromFile(GOcchar* filePath);

	private:
		std::string m_verPathStr;
		std::string m_fragPathStr;
		const char* m_verPath;
		const char* m_fragPath;
		GOuint m_ProgramID;
		GOuint m_VertexID;
		GOuint m_FragID;

		GOfloat vertices[32] = {
			// positions          // colors           // texture coords
			-0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 1.0f, // top left 
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
			 0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.0f,   1.0f, 0.0f, // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f  // bottom left
		};
		GOuint indices[6] = {
			0, 1, 2, // first triangle
			2, 3, 0  // second triangle
		};

		GOuint VAO;
		GOuint VBO;
		GOuint EBO;


	};

}
#endif //GO_SHADER_H