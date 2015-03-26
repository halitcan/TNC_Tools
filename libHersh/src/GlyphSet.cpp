/*
 * GlyphSet.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: john
 */

#include "GlyphSet.h"

namespace hersh
{

GlyphSet::GlyphSet()
{

}

GlyphSet::~GlyphSet()
{
}

void GlyphSet::push_back( const Glyph g )
{
	_glyphs.push_back( g );
}


void GlyphSet::scale( const float s )
{
	for( auto g : _glyphs )
		g.scale( s );
}

void GlyphSet::mirror( const bool mirror_x, const bool mirror_y )
{
	for( auto g : _glyphs )
		g.mirror( mirror_x, mirror_y );
}

size_t GlyphSet::size()
{
	return _glyphs.size();
}

void GlyphSet::clear()
{
	_glyphs.clear();
}

std::vector<Glyph>::iterator GlyphSet::begin()
{
	return _glyphs.begin();
}

std::vector<Glyph>::iterator GlyphSet::end()
{
	return _glyphs.end();
}

} /* namespace hersh */
