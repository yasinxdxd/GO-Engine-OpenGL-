#include "Graphics/Shader.h"
#include <glad/glad.h>

namespace go
{
	Shader::Shader()
	{
		m_ProgramID = glCreateProgram();
		m_VertexID = glCreateShader(GL_VERTEX_SHADER);
		m_FragID = glCreateShader(GL_FRAGMENT_SHADER);
		m_verPath = nullptr;
		m_fragPath = nullptr;
	}

	Shader::Shader(GOcchar* vertex_path, GOcchar* frag_path)
	{
		m_ProgramID = glCreateProgram();
		m_VertexID = glCreateShader(GL_VERTEX_SHADER);
		m_FragID = glCreateShader(GL_FRAGMENT_SHADER);
		m_verPath = nullptr;
		m_fragPath = nullptr;
		setVertexAndFragment(vertex_path, frag_path);
	}


	Shader::~Shader()
	{
		glBindVertexArray(0);
		glDeleteShader(m_VertexID);
		glDeleteShader(m_FragID);
		glDeleteProgram(m_ProgramID);
	}

	void Shader::use()
	{
		glUseProgram(m_ProgramID);
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		//std::cout<< "here" <<std::endl;
	}

	void Shader::setVertexAndFragment(GOcchar* vertex_path, GOcchar* frag_path)
	{
		if (createShader(vertex_path, frag_path))
			std::cout << "createShader--->OK" << std::endl;
		if (attachShader())
			std::cout << "attachsShader--->OK" << std::endl;
	}


	void Shader::setBool(const std::string& name, GObool value) const
	{
		glUniform1i(glGetUniformLocation(m_ProgramID, name.c_str()), (GOint)value);
	}

	void Shader::setInt(const std::string& name, GOint value) const
	{
		glUniform1i(glGetUniformLocation(m_ProgramID, name.c_str()), value);
	}

	void Shader::setFloat(const std::string& name, GOfloat value) const
	{
		glUniform1f(glGetUniformLocation(m_ProgramID, name.c_str()), value);
	}

	void Shader::setFloat_4(const std::string& name, GOfloat r, GOfloat g, GOfloat b, GOfloat a ) const
	{
		glUniform4f(glGetUniformLocation(m_ProgramID, name.c_str()), r, g, b, a);
	}

	void Shader::setFloat_3(const std::string& name, GOfloat r, GOfloat g, GOfloat b) const
	{
		glUniform3f(glGetUniformLocation(m_ProgramID, name.c_str()), r, g, b);
	}

	GObool Shader::createShader(GOcchar* vertex_path, GOcchar* frag_path)
	{
		m_verPathStr = loadFromFile(vertex_path);
		m_fragPathStr = loadFromFile(frag_path);

		m_verPath = m_verPathStr.c_str();
		m_fragPath = m_fragPathStr.c_str();


		glShaderSource(m_VertexID, 1, &m_verPath, NULL);
		glCompileShader(m_VertexID);

		///
		/// 
		int  success;
		char infoLogV[256];
		char infoLogF[256];

		/*for control*/
		glGetShaderiv(m_VertexID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(m_VertexID, 256, NULL, infoLogV);
			std::cout << "ERROR::VERTEX_SHADER::COMPILATION_FAILED\n" << infoLogV << std::endl;
			glDeleteShader(m_VertexID);
			glDeleteShader(m_FragID);
			return false;
		}

		glShaderSource(m_FragID, 1, &m_fragPath, NULL);
		glCompileShader(m_FragID);

		/*for control*/
		glGetShaderiv(m_FragID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(m_FragID, 256, NULL, infoLogF);
			std::cout << "ERROR::FRAGMENT_SHADER::COMPILATION_FAILED\n" << infoLogF << std::endl;
			glDeleteShader(m_VertexID);
			glDeleteShader(m_FragID);
			return false;
		}
		std::cout << m_VertexID << "  " << m_FragID << std::endl;
		return true;
	}

	GObool Shader::attachShader()
	{
		std::cout << m_VertexID << "  " << m_FragID << std::endl;
		//Attach shader porgram and vertex shader:
		glAttachShader(m_ProgramID, m_VertexID);
		//Attach shader porgram and fragment shader:
		glAttachShader(m_ProgramID, m_FragID);
		//Linking
		glLinkProgram(m_ProgramID);

		/*for control the linking*/
		int  successProgram;
		char infoLogProgram[512];
		glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &successProgram);
		if (!successProgram)
		{
			glGetProgramInfoLog(m_ProgramID, 512, NULL, infoLogProgram);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLogProgram << std::endl;
			glDeleteShader(m_VertexID);
			glDeleteShader(m_FragID);
			return false;
		}

		/*if Linking is ok, we don't need shaders anymore*/
		glDeleteShader(m_VertexID);
		glDeleteShader(m_FragID);
		return true;
	}


	std::string Shader::loadFromFile(GOcchar* filePath) 
	{
		std::string content;
		std::ifstream fileStream(filePath, std::ios::in);

		if (!fileStream.is_open()) {
			std::cerr << "Could not read file " << filePath << " File does not exist." << std::endl;
			return "";
		}

		std::string line = "";
		while (!fileStream.eof()) 
		{
			std::getline(fileStream, line);
			content.append(line + "\n");
		}

		fileStream.close();
		return content;
	}

}