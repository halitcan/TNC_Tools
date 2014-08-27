/*
 * Glyph.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: john
 */

#include "Glyph.h"
#include <limits>

#include <iostream>

namespace hersh
{
Glyph::Glyph() : glyphnum{ 0 }, lpos{ 0 }, rpos{ 0 }
{

}

Glyph::~Glyph()
{
}

void Glyph::setGlyphNum( const int value )
{
	glyphnum = value;
}

void Glyph::setLPos( const float value )
{
	lpos = value;
}

void Glyph::setRPos( const float value )
{
	rpos = value;
}

void Glyph::setPaths( std::vector<std::vector<Vertex> > p )
{
	paths = p;
}

wchar_t Glyph::getGlyphNum()
{
	return glyphnum;
}

std::vector<std::vector<Vertex> > &Glyph::getPaths()
{
	return paths;
}

void Glyph::scale( const float s )
{
	for( std::vector<Vertex> &p : paths )
		for( Vertex &v : p )
			v.scale( s );

	lpos *= s;
	rpos *= s;
}

float Glyph::getHeight()
{
	float min_y = std::numeric_limits<float>::max();
	float max_y = std::numeric_limits<float>::min();
	for( auto &p : paths )
	{
		for( auto &v : p )
		{
			float y = v.getY();
			if( y > max_y )
				max_y = y;
			else if( y < min_y )
				min_y = y;
		}
	}

	return max_y - min_y;
}

void Glyph::translate( const float x, const float y )
{
	for( std::vector<Vertex> &p : paths )
		for( Vertex &v : p )
			v.translate( x, y );

	lpos += x;
	rpos += x;
}

float Glyph::getLPos()
{
	return lpos;
}

float Glyph::getRPos()
{
	return rpos;
}

void Glyph::mirror( const bool mirror_x, const bool mirror_y )
{
	if( mirror_x )
	{
		float tmp = lpos;
		lpos = rpos;
		rpos = tmp;
	}

	for( std::vector<Vertex> &p : paths )
		for( Vertex &v : p )
		{
			if( mirror_x )
				v.setX( (v.getX() * -1 ) );
			if( mirror_y )
				v.setY( (v.getY() * -1 ) );
		}
}

float Glyph::getWidth()
{
	return rpos + (lpos * -1);
}

size_t Glyph::size()
{
	size_t ret = 0;
	for( auto p : paths )
		ret += p.size();

	return ret;
}

} //namespace Hersh
