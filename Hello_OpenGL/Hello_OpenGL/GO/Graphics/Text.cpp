#include "Text.h"

namespace go
{
	Text::Text()
	{
		m_defaultShader.setVertexAndFragment("GO/GLSL/DefaultTextVertexShader.glsl", "GO/GLSL/DefaultTextFragmentShader.glsl");
		m_Font = nullptr;
	}
	Text::Text(GOcchar* text)
	{
		m_defaultShader.setVertexAndFragment("GO/GLSL/DefaultTextVertexShader.glsl", "GO/GLSL/DefaultTextFragmentShader.glsl");
		m_Font = nullptr;
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
		for(int i = 0; i< m_Font->m_font_characters.size(); i++)
			glDeleteTextures(sizeof(GOuint), &m_Font->m_font_characters[i].m_texture);
	}
	void Text::setFont(go::Font& font)
	{
		m_Font = &font;
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
		m_windowSize = windowSize;
		glActiveTexture(GL_TEXTURE0);
		for (int i = 0; i < m_Font->m_font_characters.size(); i++)
			glBindTexture(GL_TEXTURE_2D, m_Font->m_font_characters[i].m_texture);
		m_defaultShader.setFloat_3("textColor", 0, 0, 1);
		m_defaultShader.use();
		glBindTexture(GL_TEXTURE_2D, 0);
		setShader();



		std::string::const_iterator c;
		for (c = m_string.begin(); c != m_string.end(); c++)
		{
			Font::m_character ch = m_Font->m_font_characters[*c];

			float xpos = m_position.x + ch.bearing.x * 1;
			float ypos = m_position.y - (ch.size.y - ch.bearing.y) * 1;

			float w = ch.size.x * 1;
			float h = ch.size.y * 1;
			// update VBO for each character
			float vertices[6][4] = {
				{ xpos,     ypos + h,   0.0f, 0.0f },
				{ xpos,     ypos,       0.0f, 1.0f },
				{ xpos + w, ypos,       1.0f, 1.0f },

				{ xpos,     ypos + h,   0.0f, 0.0f },
				{ xpos + w, ypos,       1.0f, 1.0f },
				{ xpos + w, ypos + h,   1.0f, 0.0f }
			};
			// render glyph texture over quad
			glBindTexture(GL_TEXTURE_2D, ch.m_texture);
			m_position.x += (ch.advance >> 6) * 1; // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
		}
		glBindVertexArray(0);
		m_defaultShader.setFloat_3("textColor", 1, 0, 0);
		m_defaultShader.use();
		glBindTexture(GL_TEXTURE_2D, 0);
		setShader();

	}


	



}