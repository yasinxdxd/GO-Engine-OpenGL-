#ifndef GO_RENDERABLE_H
#define GO_RENDERABLE_H

#include "Graphics/Shader.h"
#include "Graphics/VertexArray.h"
#include "Math/Vectors.h"

namespace go
{

	class Renderable
	{

	public:
		explicit Renderable();
		//Setters:
		virtual void setPosition(Vec2f);
		virtual void setOrigin(Vec2f);
		virtual void setSize(Vec2f);
		virtual void setColor(GOsint r, GOsint g, GOsint b);
		virtual void setColor(GOsint r, GOsint g, GOsint b, GOsint a);
		//Getters:
		virtual Vec2f getPosition() const;
		virtual Vec2f getOrigin() const;
		virtual Vec2f getSize() const;

	protected:
		virtual void draw(go::Vec2ui windowSize);
		virtual void setShader();
	protected:
		go::Shader m_defaultShader;
		go::VertexArray m_defaultVertexArray;

		Vec2ui m_windowSize;
		Vec2f m_position;
		Vec2f m_size;
		Vec2f m_origin = Vec2f(0, 0);
	protected:
		virtual Renderable& operator=(const Renderable&) = delete; //NON-COPYABLE

	friend class Window;
	};

}


#endif //GO_RENDERABLE_H