#include "Sprite.h"
//#include <stdexcept>

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


	Sprite::~Sprite()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
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
	}

	void Sprite::setOrigin(Vec2f origin)
	{
		m_origin = origin;
	}

	void Sprite::setSize(Vec2f size)
	{
		m_size = size;
	}

	void Sprite::setRotatiton(GOfloat angle)
	{
		m_angle = angle;
	}

	void Sprite::setColor(GOsint r, GOsint g, GOsint b)
	{
		//m_defaultShader.setFloat_4("ourColor", float(r / 255), float(g / 255), float(b / 255), float(a / 255));
		m_defaultVertexArray.setColorVertices(r, g, b, 255, 0);
		m_defaultVertexArray.setColorVertices(r, g, b, 255, 1);
		m_defaultVertexArray.setColorVertices(r, g, b, 255, 2);
		m_defaultVertexArray.setColorVertices(r, g, b, 255, 3);
	}

	void Sprite::setColor(GOsint r, GOsint g, GOsint b, GOsint a)
	{
		//m_defaultShader.setFloat_4("ourColor", float(r / 255), float(g / 255), float(b / 255), float(a / 255));
		m_defaultVertexArray.setColorVertices(r, g, b, a, 0);
		m_defaultVertexArray.setColorVertices(r, g, b, a, 1);
		m_defaultVertexArray.setColorVertices(r, g, b, a, 2);
		m_defaultVertexArray.setColorVertices(r, g, b, a, 3);
	}

	//Getters:
	Vec2f Sprite::getPosition() const
	{
		return m_position;
	}

	Vec2f Sprite::getOrigin() const
	{
		return m_origin;
	}

	Vec2f Sprite::getSize() const
	{
		return m_size;
	}

	GOfloat Sprite::getRotatiton() const
	{
		return m_angle;
	}


	void Sprite::draw(go::Vec2ui windowSize)
	{
		m_windowSize = windowSize;
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_Texture->m_texture);
		m_defaultShader.use();
		m_defaultVertexArray.bind();
		m_defaultVertexArray.unBind();
		glBindTexture(GL_TEXTURE_2D, 0);
		setShader();
		//std::cout << "Sprite::draw()" << std::endl;
	}
}
