#include "Font.h"
#include <iostream>
#include <glad/glad.h>

namespace go
{

	Font::Font()
	{
		if (FT_Init_FreeType(&ft))
		{
			std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
		}

	}

	Font::Font(GOcchar* path_file)
	{
		if (FT_Init_FreeType(&ft))
		{
			std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
		}
        loadFromFile(path_file);
	}

	Font::~Font()
	{
        
	}

	void Font::loadFromFile(GOcchar* path_file)
	{
		if (FT_New_Face(ft, path_file, 0, &face))
		{
			std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
		}
        else {
            // set size to load glyphs as
            FT_Set_Pixel_Sizes(face, 0, 48);

            // disable byte-alignment restriction
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

            // load first 128 characters of ASCII set
            for (GOuchar c = 0; c < 128; c++)
            {
                // Load character glyph 
                if (FT_Load_Char(face, c, FT_LOAD_RENDER))
                {
                    std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
                    continue;
                }
                ////////////////////////////////////////////////////////////////////
                GOuint texture;
                glGenTextures(1, &texture);
                glBindTexture(GL_TEXTURE_2D, texture);
                ////////////////////////////////////////////////////////////////////
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                ////////////////////////////////////////////////////////////////////
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
                ////////////////////////////////////////////////////////////////////
                m_character character = {
                        texture,
                        go::Vec2i(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                        go::Vec2i(face->glyph->bitmap_left, face->glyph->bitmap_top),
                        static_cast<GOuint>(face->glyph->advance.x)
                };
                m_font_characters.insert(std::pair<char, m_character>(c, character));
                glBindTexture(GL_TEXTURE_2D, 0);
            }
        }
        FT_Done_Face(face);
        FT_Done_FreeType(ft);
	}



}