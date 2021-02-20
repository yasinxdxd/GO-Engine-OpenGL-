#include "Graphics/Texture.h"
#include "stb_image.h"
#include <fstream>
#include <glad/glad.h>

namespace go
{
	Texture::Texture()
	{
		textureData.data = nullptr;
		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		stbi_set_flip_vertically_on_load(true);
	}

	Texture::Texture(GOcchar* path_file)
	{
		textureData.data = nullptr;
		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

		float borderColor[] = { 1.0f, 1.0f, 0.0f, 0.0f };
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
		
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// GL_NEAREST, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		stbi_set_flip_vertically_on_load(true);
		
		loadFromFile(path_file);
	}

	Texture::~Texture()
	{
		glDeleteTextures(sizeof(GOuint), &m_texture);
	}
	
	void Texture::loadFromFile(GOcchar* path_file)
	{
		textureData.data = stbi_load(path_file, &textureData.size.x, &textureData.size.y, &textureData.channels, STBI_rgb_alpha);
		if(stbi_failure_reason())
			std::cout << "stbi failure reason: " << stbi_failure_reason() << std::endl;
		if (textureData.data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureData.size.x, textureData.size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData.data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
			std::cout << "Image couldn't loaded: " << path_file << std::endl;
		stbi_image_free(textureData.data);
	}

	Texture::operator GOuint() const noexcept
	{
		return m_texture;
	}

	/*void Texture::loadFromMemory(unsigned GOcchar* path_file)
	{
		std::ifstream in_file(path_file, std::ios::binary);
		in_file.seekg(0, std::ios::end);
		int file_size = in_file.tellg();

		textureData.data = stbi_load_from_memory(path_file, file_size, &textureData.size.x, &textureData.size.y, &textureData.channels, STBI_rgb_alpha);
		if (stbi_failure_reason())
			std::cout << "stbi failure reason: " << stbi_failure_reason() << std::endl;
		if (textureData.data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureData.size.x, textureData.size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData.data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
			std::cout << "Image couldn't loaded: " << path_file << std::endl;
		stbi_image_free(textureData.data);
	}*/


}
