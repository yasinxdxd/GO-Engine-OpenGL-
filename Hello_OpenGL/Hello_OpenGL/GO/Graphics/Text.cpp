#include "Text.h"
#include <glad/glad.h>

namespace go
{
	Text::Text()
	{
		m_defaultShader.setVertexAndFragment("GO/GLSL/DefaultTextVertexShader.glsl", "GO/GLSL/DefaultTextFragmentShader.glsl");
	}
	Text::Text(GOcchar* text)
	{
		m_defaultShader.setVertexAndFragment("GO/GLSL/DefaultTextVertexShader.glsl", "GO/GLSL/DefaultTextFragmentShader.glsl");
		setString(text);
	}
	Text::Text(go::Font& font)
	{
		m_defaultShader.setVertexAndFragment("GO/GLSL/DefaultTextVertexShader.glsl", "GO/GLSL/DefaultTextFragmentShader.glsl");
		setFont(font);
	}
	Text::Text(GOcchar* text, go::Font& font)
	{
		m_defaultShader.setVertexAndFragment("GO/GLSL/DefaultTextVertexShader.glsl", "GO/GLSL/DefaultTextFragmentShader.glsl");
		setFont(font);
		setString(text);
	}
	Text::~Text()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
		for(GOuint i = 0; i< m_Font.m_FontCharacters.size(); i++)
			glDeleteTextures(sizeof(GOuint), &m_Font.m_FontCharacters[i].m_texture);
	}
	void Text::setFont(go::Font& font)
	{
		m_Font = font;
	}
	void Text::setString(GOcchar* text)
	{
		m_string = text;
	}
	void Text::setPosition(Vec2f position)
	{
		m_position = position;
	}
	void Text::setSize(Vec2f size)
	{
		m_size = size;
	}
	Vec2f Text::getPosition() const
	{
		return m_position;
	}
	Vec2f Text::getSize() const
	{
		return m_size;
	}

	void Text::draw(go::Vec2ui windowSize)
	{

		//std::string::const_iterator c = m_string.begin(); c != m_string.end(); c++
		//std::cout << m_Font->m_FontCharacters.find('?')->first;
		/*for (int i = 0; i<128; i++)
		{
			m_windowSize = windowSize;
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, m_Font.m_FontCharacters[i].m_texture);
			m_defaultShader.setFloat_4("ourColor", 1, 0, 0, 0);
			m_defaultShader.use();
			m_defaultVertexArray.bind();
			m_defaultVertexArray.unBind();
			glBindTexture(GL_TEXTURE_2D, 0);
			setShader();
			m_defaultVertexArray.setPositionAndRotationVertices(m_origin, go::Vec2f(m_position.x+i*18, m_position.y), m_size, m_windowSize, m_angle);
		}
		*/
		
		int i = 0;
		std::string::const_iterator c;
		for (c = this->m_string.begin(); c != this->m_string.end(); c++)
		{
			m_windowSize = windowSize;
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, m_Font.m_FontCharacters[*c].m_texture);
			m_defaultShader.setFloat_4("ourColor", 1, 0, 1, 1);
			m_defaultShader.use();
			m_defaultVertexArray.bind();
			m_defaultVertexArray.unBind();
			glBindTexture(GL_TEXTURE_2D, 0);
			//setShader();
			m_defaultVertexArray.setPositionAndRotationVertices(m_origin, go::Vec2f(m_position.x + i * this->getSize().x, m_position.y), m_size, m_windowSize, m_angle);
			i++;
		}
		
	

		
	}
		
		
}


	



