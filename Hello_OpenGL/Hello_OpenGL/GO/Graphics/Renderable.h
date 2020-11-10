#pragma once
#ifndef GO_RENDERABLE_H
#define GO_RENDERABLE_H

#include "Graphics/Shader.h"
#include "Math/Vectors.h"

namespace go
{

	class Renderable
	{

	public:
		Renderable();
		//Setters:
		virtual void setPosition(Vec2f);
		virtual void setSize(Vec2f);
		//Getters:
		virtual Vec2f getPosition();
		virtual Vec2f getSize();

	protected:
		virtual void draw(go::Vec2ui windowSize);
		virtual void setShader();
	protected:
		go::Shader m_defaultShader;

		Vec2ui m_windowSize;
		Vec2f m_position;
		Vec2f m_size;

	friend class Window;
	};

}


#endif //GO_RENDERABLE_H