#ifndef GO_TEXTURE_H
#define GO_TEXTURE_H


#include "Math/Vectors.h"
#include <glad/glad.h>
#include <string>
#include <iostream>

namespace go
{
	class Texture
	{
	public:
		Texture();
		Texture(GOcchar* path_file);
		~Texture();

		void loadFromFile(GOcchar* path_file);
		
	private:

		struct textureData
		{
			Vec2i size;
			GOint channels;
			GOuchar* data;

		}textureData;

		GOuint m_texture;
		
	friend class Sprite;

	};

}

#endif //GO_TEXTURE_H
