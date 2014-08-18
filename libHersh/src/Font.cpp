/*
 * Font.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: john
 */

#include "Font.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <limits>

namespace hersh
{

Font::Font()
{

}

Font::Font( std::string filename )
{
	load( filename );
}

Font::~Font()
{
}

void Font::load( std::string filename )
{
	std::ifstream file{ filename };
	if( file.is_open() )
	{
		std::vector<std::string> rows;
		std::string line;

		while( std::getline( file, line ) )
			rows.push_back( line );

		file.close();

		parse_glyphs( rows );
		normalize_height();
	}
	else
	{
		throw FileError();
	}
}

void Font::parse_glyphs( std::vector<std::string> &rows )
{
	glyphs.clear();

	for( auto line : rows )
	{
		//Check if line contains glyph number
		if( line.size() < 5 )
			throw GlyphError::LineTooShort;

		glyphs.push_back( parse_glyph( line ) );
	}

}

Glyph Font::parse_glyph( std::string& line )
{
	Glyph ret;

	try
	{
		ret.setGlyphNum( std::stoi( line.substr( 0, 5 ) ) );
	}
	catch( const std::invalid_argument & )
	{
		throw GlyphError::Invalid;
	}

	//Check if line contains other info
	if( line.size() < 10 )
		return ret;

	//Check if line contains the expected amount of characters
	try
	{
		int n_vert = std::stoi( line.substr( 5, 7 ) );

		if( line.size() < (unsigned int)(10 + (n_vert * 2) - 2) )
			throw GlyphError::Invalid;
	}
	catch( const std::invalid_argument & )
	{
		throw GlyphError::Invalid;
	}

	ret.setLPos( (float)(line[8] - 'R') );
	ret.setRPos( (float)(line[9] - 'R') );

	std::string paths_line = line.substr( 10, line.size() );
	std::vector<std::vector<Vertex>> paths = parse_paths( paths_line );
	ret.setPaths( paths );

	return ret;
}

Glyph Font::getGlyph( wchar_t g, FontMap &map )
{
	int gn = map.getGlyphNumber( g );

	for( auto i : glyphs )
		if( i.getGlyphNum() == gn )
			return i;

	throw NoSuchGlyph();

	return Glyph();
}

std::vector<Glyph> Font::getGlyphs( std::wstring s, FontMap& m )
{
	std::vector<Glyph> ret;
	for( auto c : s )
		ret.push_back( getGlyph( c, m ) );

	return ret;
}

std::vector<std::vector<Vertex> > Font::parse_paths( std::string& line )
{
	std::vector<std::vector<Vertex>> paths{ 1 };

	for( unsigned int offs = 0; offs < line.size(); offs += 2 )
	{
		std::string l = line.substr( offs, 2 );

		if( l == " R" )
			paths.push_back( std::vector<Vertex>() );
		else
			paths[paths.size() - 1].push_back( Vertex{ (float)(l[0] - 'R'), (float)(l[1] - 'R') } );
	}

	return paths;
}


void Font::normalize_height()
{
	float max_h = std::numeric_limits<float>::min();
	for( auto &g : glyphs )
	{
		float h = g.getHeight();
		if( h > max_h )
			max_h = h;

	}
	for( auto &g : glyphs )
		g.scale( 1.0f / max_h );
}

} //namespace Hersh
