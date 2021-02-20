#include "Graphics/Renderable.h"

namespace go
{

	Renderable::Renderable():
		m_position(Vec2f(0, 0)), m_origin(Vec2f(0, 0))
	{ 
		m_defaultShader.setVertexAndFragment("GO/GLSL/VertexShader.glsl", "GO/GLSL/FragmentShader.glsl");
	}

	//Setters:
	void Renderable::setPosition(Vec2f position)
	{
		m_position = position;
	}

	void Renderable::setTextureCoords(Vec2f position, Vec2f size)
	{
		m_defaultVertexArray.setTextureCoords(position, size);
	}

	void Renderable::setOrigin(Vec2f origin)
	{
		m_origin = origin;
	}

	void Renderable::setSize(Vec2f size)
	{
		m_size = size;
	}

	void Renderable::setRotatiton(GOfloat angle)
	{
		m_angle = angle;
	}

	void Renderable::setColor(GOsint r, GOsint g, GOsint b)
	{
		//m_defaultShader.setFloat_3("ourColor", float(r / 255), float(g / 255), float(b / 255));
		m_defaultVertexArray.setColorVertices(r, g, b, 255, 0);
		m_defaultVertexArray.setColorVertices(r, g, b, 255, 1);
		m_defaultVertexArray.setColorVertices(r, g, b, 255, 2);
		m_defaultVertexArray.setColorVertices(r, g, b, 255, 3);
	}

	void Renderable::setColor(GOsint r, GOsint g, GOsint b, GOsint a)
	{
		//m_defaultShader.setFloat_4("ourColor", float(r / 255), float(g / 255), float(b / 255), float(a / 255));
		m_defaultVertexArray.setColorVertices(r, g, b, a, 0);
		m_defaultVertexArray.setColorVertices(r, g, b, a, 1);
		m_defaultVertexArray.setColorVertices(r, g, b, a, 2);
		m_defaultVertexArray.setColorVertices(r, g, b, a, 3);
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

	GOfloat Renderable::getRotatiton() const
	{
		return m_angle;
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
		m_defaultVertexArray.setPositionAndRotationVertices(m_origin, m_position, m_size, m_windowSize, m_angle);
	}

}


		