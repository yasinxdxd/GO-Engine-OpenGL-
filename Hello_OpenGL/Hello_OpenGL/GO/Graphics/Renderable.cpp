#include "Renderable.h"

namespace go
{

	Renderable::Renderable()
	{ }

	//Setters:
	void Renderable::setPosition(Vec2f position)
	{
		m_position = position;
	}

	void Renderable::setOrigin(Vec2f origin)
	{
		m_origin = origin;
	}

	void Renderable::setSize(Vec2f size)
	{
		m_size = size;
	}

	//Getters:
	Vec2f Renderable::getPosition() const
	{
		return m_position;
	}

	Vec2f Renderable::getOrigin() const
	{
		return m_origin;
	}

	Vec2f Renderable::getSize() const
	{
		return m_size;
	}

	void Renderable::draw(go::Vec2ui windowSize)
	{
		m_windowSize = windowSize;
		m_defaultShader.use();
		m_defaultVertexArray.bind();
		m_defaultVertexArray.unBind();
		setShader();
		//std::cout << "Renderable::draw()" << std::endl;
	}

	void Renderable::setShader()
	{
		m_defaultVertexArray.setVertices(m_origin, m_position, m_size, m_windowSize);
	}

}


		