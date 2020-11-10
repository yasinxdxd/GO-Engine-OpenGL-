#pragma once
#ifndef GO_TEXTURE_H
#define GO_TEXTURE_H


#include "Math/Vectors.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

namespace go
{
	class Texture
	{
	public:
		Texture();
		Texture(GOcchar* path_file);

		void loadFromFile(GOcchar* path_file);
		
	private:
		Vec2i size;
		GOint channels;
		GOuchar* data;
		GOuint m_texture;
		
	friend class Sprite;

	};

}

#endif //GO_TEXTURE_H
