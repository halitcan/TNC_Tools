/*
 * Glyph.h
 *
 *  Created on: Aug 12, 2014
 *      Author: john
 */

#ifndef GLYPH_H_
#define GLYPH_H_

#include <vector>
#include "Vertex.h"

namespace hersh
{
class Glyph
{
	public:
		Glyph();
		virtual ~Glyph();
		void setGlyphNum( const int value );
		void setLPos( const float value );
		void setRPos( const float value );
		void setPaths( std::vector<std::vector<Vertex>> p );
		wchar_t getGlyphNum();
		std::vector<std::vector<Vertex>> &getPaths();
		void scale( float s );
		float getHeight();
		void translate( const float x, const float y );
		float getLPos();
		float getRPos();
		void mirror( const bool mirror_x, const bool mirror_y );

	private:
		int glyphnum;
		float lpos;
		float rpos;
		std::vector<std::vector<Vertex>> paths;

};

} //namespace Hersh
#endif /* GLYPH_H_ */
