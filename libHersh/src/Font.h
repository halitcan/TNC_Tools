/*
 * Font.h
 *
 *  Created on: Aug 12, 2014
 *      Author: john
 */

#ifndef FONT_H_
#define FONT_H_

#include <string>
#include <vector>
#include "GlyphSet.h"
#include "Vertex.h"
#include "FontMap.h"

namespace hersh
{
class Font
{
	public:
		enum class FileError { };
		enum class GlyphError
		{
			LineTooShort, Empty, Invalid
		};
		enum class NoSuchGlyph { };

		Font();
		Font( std::string filename );
		virtual ~Font();
		void load( std::string filename );
		Glyph getGlyph( wchar_t g, FontMap &map );
		GlyphSet getGlyphs( std::wstring s, FontMap &m );

	private:
		GlyphSet glyphs;
		void parse_glyphs( std::vector<std::string> &rows );
		Glyph parse_glyph( std::string &line );
		std::vector<std::vector<Vertex>> parse_paths( std::string &line );
		void normalize_height();
};

} //namespace Hersh

#endif /* FONT_H_ */
