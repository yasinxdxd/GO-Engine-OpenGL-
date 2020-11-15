#ifndef GO_FONT_H
#define GO_FONT_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include "Math/Vectors.h"
#include <map>

namespace go
{

	class Font
	{
	public:

		Font();
		Font(GOcchar* path_file);
		~Font();

		void loadFromFile(GOcchar* path_file);


	private:

		struct m_character 
		{
			GOuint m_texture;	 // ID handle of the glyph texture
			go::Vec2i size;      // Size of glyph
			go::Vec2i bearing;   // Offset from baseline to left/top of glyph
			GOuint advance;		 // Horizontal offset to advance to next glyph
		};

	private:
		FT_Library ft;
		FT_Face face;

		std::map<char, m_character> m_font_characters;

		
		friend class Text;
	};

}


#endif // GO_FONT_H