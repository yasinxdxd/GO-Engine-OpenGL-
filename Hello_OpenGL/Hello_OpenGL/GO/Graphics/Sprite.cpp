#include "Sprite.h"


namespace go
{

	Sprite::Sprite()
	{
		m_defaultShader.setVertexAndFragment("GO/GLSL/DefaultTextureVertexShader.glsl", "GO/GLSL/DefaultTextureFragmentShader.glsl");
	}

	Sprite::Sprite(go::Texture& texture)
	{
		m_defaultShader.setVertexAndFragment("GO/GLSL/DefaultTextureVertexShader.glsl", "GO/GLSL/DefaultTextureFragmentShader.glsl");
		setTexture(texture);
	}

	//Setters:
	void Sprite::setTexture(Texture& texture)
	{
		m_Texture = &texture;
		m_defaultShader.use(); // don't forget to activate/use the shader before setting uniforms!
		//m_defaultShader.setFloat_4("ourColor", 1.f, 1.f, 0.3f, 0.001f);
		m_defaultShader.setInt("texture1", 0);
	}

	Sprite::~Sprite()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
		glDeleteTextures(sizeof(GOuint), &m_Texture->m_texture);
	}



	void Sprite::setPosition(Vec2f position)
	{
		m_position = position;
	}

	void Sprite::setSize(Vec2f size)
	{
		m_size = size;
	}

	//Getters:
	Vec2f Sprite::getPosition() const
	{
		return m_position;
	}

	Vec2f Sprite::getSize() const
	{
		return m_size;
	}


	void Sprite::draw(go::Vec2ui windowSize)
	{
		m_windowSize = windowSize;
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_Texture->m_texture);
		m_defaultShader.use();
		m_defaultVertexArray.bind();
		glBindTexture(GL_TEXTURE_2D, 0);
		setShader();
		//std::cout << "Sprite::draw()" << std::endl;
	}
}
