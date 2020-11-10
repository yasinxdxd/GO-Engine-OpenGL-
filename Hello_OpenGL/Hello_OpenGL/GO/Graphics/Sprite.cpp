#include "Sprite.h"


namespace go
{

	Sprite::Sprite()
	{
		
	}

	Sprite::Sprite(go::Texture& texture)
	{
		
		m_Texture = &texture;
		m_defaultShader.use(); // don't forget to activate/use the shader before setting uniforms!
		//m_defaultShader.setFloat_4("ourColor", 0.f, 0.3f, 0.3f, 0.1f);
		m_defaultShader.setInt("texture1", 0);
	}

	//Setters:
	void Sprite::setTexture(Texture& texture)
	{
		m_Texture = &texture;
		m_defaultShader.use(); // don't forget to activate/use the shader before setting uniforms!
		//m_defaultShader.setFloat_4("ourColor", 1.f, 1.f, 0.3f, 0.001f);
		m_defaultShader.setInt("texture1", 0);
	}

	void Sprite::setPosition(Vec2f position)
	{
		m_position = position;
		setShader();
	}

	void Sprite::setSize(Vec2f size)
	{
		m_size = size;
		setShader();
	}

	//Getters:
	Vec2f Sprite::getPosition()
	{
		return m_position;
	}

	Vec2f Sprite::getSize()
	{
		return m_size;
	}


	void Sprite::draw(go::Vec2ui windowSize)
	{
		m_windowSize = windowSize;
		setShader();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_Texture->m_texture);
		m_defaultShader.use();
		glBindTexture(GL_TEXTURE_2D, 0);
		//std::cout << "Sprite::draw()" << std::endl;
	}
}
