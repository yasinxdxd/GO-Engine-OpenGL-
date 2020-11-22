#include "VertexArray.h"
#include <glad/glad.h>
#include "Math/Vectors.h"
namespace go
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
		glEnableVertexAttribArray(2);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);
		//////////////////////////
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	VertexArray::~VertexArray()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

	void VertexArray::setPositionAndRotationVertices(go::Vec2f origin, go::Vec2f position, go::Vec2f size, go::Vec2ui windowSize, GOfloat angle)
	{
		//X:																																	//Y:
		vertices[0] = (position.x - origin.x + (size.x - origin.x) * cos(GO_D2R(angle+90)) - ((GOfloat)windowSize.x / 2)) / ((GOfloat)windowSize.x / 2);					vertices[1] = (position.y - origin.y + (size.y - origin.y) * sin(GO_D2R(angle+90)) - ((GOfloat)windowSize.y / 2)) / -((GOfloat)windowSize.y / 2);
		vertices[9] = (position.x - origin.x + (size.x - origin.x) * cos(GO_D2R(angle+360)) - ((GOfloat)windowSize.x / 2)) / ((GOfloat)windowSize.x / 2);					vertices[10] = (position.y - origin.y + (size.y - origin.y) * sin(GO_D2R(angle+360)) - ((GOfloat)windowSize.y / 2)) / -((GOfloat)windowSize.y / 2);
		vertices[18] = (position.x - origin.x + (size.x - origin.x) * cos(GO_D2R(angle+270)) - ((GOfloat)windowSize.x / 2)) / ((GOfloat)windowSize.x / 2);					vertices[19] = (position.y - origin.y + (size.y - origin.y) * sin(GO_D2R(angle+270)) - ((GOfloat)windowSize.y / 2)) / -((GOfloat)windowSize.y / 2);
		vertices[27] = (position.x - origin.x + (size.x - origin.x) * cos(GO_D2R(angle+180)) - ((GOfloat)windowSize.x / 2)) / ((GOfloat)windowSize.x / 2);					vertices[28] = (position.y - origin.y + (size.y - origin.y) * sin(GO_D2R(angle+180)) - ((GOfloat)windowSize.y / 2)) / -((GOfloat)windowSize.y / 2);
		
		

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	}

	void VertexArray::setColorVertices(GOsint r, GOsint g, GOsint b, GOsint a, GOsint vertex)
	{
		switch (vertex)
		{
		case 0:
			vertices[3] = (float)r / 255;	vertices[4] = (float)g / 255;	vertices[5] = (float)b / 255;	vertices[6] = (float)a / 255;
			break;
		case 1:
			vertices[12] = (float)r / 255;	vertices[13] = (float)g / 255;	vertices[14] = (float)b / 255;	vertices[15] = (float)a / 255;
			break;
		case 2:
			vertices[21] = (float)r / 255;	vertices[22] = (float)g / 255;	vertices[23] = (float)b / 255;	vertices[24] = (float)a / 255;
			break;
		case 3:
			vertices[30] = (float)r / 255;	vertices[31] = (float)g / 255;	vertices[32] = (float)b / 255;	vertices[33] = (float)a / 255;
			break;
		default:
			break;
		}
		
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

		// color attribute
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		

		
	}

	void VertexArray::bind()
	{
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void VertexArray::unBind()
	{
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}
