#include "Renderable.h"

namespace go
{

	Renderable::Renderable():
	m_defaultShader("GO/GLSL/DefaultTextureVertexShader.glsl", "GO/GLSL/DefaultTextureFragmentShader.glsl")
	{}

	//Setters:
	void Renderable::setPosition(Vec2f position)
	{
		m_position = position;
		setShader();
	}

	void Renderable::setSize(Vec2f size)
	{
		m_size = size;
		setShader();
	}

	//Getters:
	Vec2f Renderable::getPosition()
	{
		return m_position;
	}

	Vec2f Renderable::getSize()
	{
		return m_size;
	}

	void Renderable::draw(go::Vec2ui windowSize)
	{
		m_windowSize = windowSize;
		setShader();
		m_defaultShader.use();
		//std::cout << "Renderable::draw()" << std::endl;
	}

	void Renderable::setShader()
	{
		m_defaultShader.setVertices(m_position, m_size, m_windowSize);
	}

}


		