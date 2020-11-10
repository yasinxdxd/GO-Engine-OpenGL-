#include "Shader.h"


namespace go
{

	Shader::Shader(GOcchar* vertex_path, GOcchar* frag_path)
	{
		m_ProgramID = glCreateProgram();
		m_VertexID = glCreateShader(GL_VERTEX_SHADER);
		m_FragID = glCreateShader(GL_FRAGMENT_SHADER);
		m_verPath = nullptr;
		m_fragPath = nullptr;
		if (createShader(vertex_path, frag_path))
			std::cout << "createShader--->OK" <<std::endl;
		if(attachShader())
			std::cout << "attachsShader--->OK" << std::endl;
		if(setBuffers())
			std::cout << "setBuffers--->OK" << std::endl;
	}

	Shader::~Shader()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		glDeleteShader(m_VertexID);
		glDeleteShader(m_FragID);
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glDeleteProgram(m_ProgramID);
	}

	void Shader::use()
	{
		glUseProgram(m_ProgramID);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		//std::cout<< "here" <<std::endl;
	}

	void Shader::setVertices(go::Vec2f position, go::Vec2f size, go::Vec2ui windowSize)
	{
		vertices[0] = (position.x - ((GOfloat)windowSize.x / 2)) / ((GOfloat)windowSize.x/2);					vertices[1] = (position.y - ((GOfloat)windowSize.y / 2)) / -((GOfloat)windowSize.y / 2);
		vertices[8] = (position.x + size.x - ((GOfloat)windowSize.x / 2)) / ((GOfloat)windowSize.x / 2);		vertices[9] = (position.y - ((GOfloat)windowSize.y / 2)) / -((GOfloat)windowSize.y / 2);
		vertices[16] = (position.x + size.x - ((GOfloat)windowSize.x / 2)) / ((GOfloat)windowSize.x / 2);		vertices[17] = (position.y + size.y - ((GOfloat)windowSize.y / 2)) / -((GOfloat)windowSize.y / 2);
		vertices[24] = (position.x - ((GOfloat)windowSize.x/2)) / ((GOfloat)windowSize.x / 2);					vertices[25] = (position.y + size.y - ((GOfloat)windowSize.y / 2)) / -((GOfloat)windowSize.y / 2);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

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

	GObool Shader::setBuffers()
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
		
		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);
		//////////////////////////
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
		while (!fileStream.eof()) {
			std::getline(fileStream, line);
			content.append(line + "\n");
		}

		fileStream.close();
		return content;
	}

}