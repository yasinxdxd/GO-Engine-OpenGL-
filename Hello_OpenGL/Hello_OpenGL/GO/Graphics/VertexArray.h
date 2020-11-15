#ifndef GO_VERTEXARRAY_H
#define GO_VERTEXARRAY_H

#include "Graphics/Vertex.h"
#include <vector>

namespace go
{


	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

	protected:

		void setVertices(go::Vec2f position, go::Vec2f size, go::Vec2ui windowsSize);
		void bind();

	private:

		GOfloat vertices[32] = {
			// positions          // colors           // texture coords
			-0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 1.0f, // top left 
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
			 0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.0f,   1.0f, 0.0f, // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f  // bottom left
		};
		GOuint indices[6] = {
			0, 1, 2, // first triangle
			2, 3, 0  // second triangle
		};

		std::vector<Vertex> m_vertecies;
		
		
		GOuint VAO;
		GOuint VBO;
		GOuint EBO;

		friend class Renderable;
		friend class Sprite;

	};

}


#endif // GO_VERTEXARRAY_H