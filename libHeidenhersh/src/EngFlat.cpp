/*
 * EngFlat.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "EngFlat.h"
#include <cmath>

namespace heidenhersh
{

EngFlat::EngFlat( std::vector<hersh::Glyph> &glyphs, const uint16_t feed ) : Engrave{ glyphs, feed }
{
}

EngFlat::EngFlat()
{
}

EngFlat::~EngFlat()
{
}

Engrave::ProgramVector EngFlat::makeLinear( float spacing )
{
	ProgramVector ret;

	if( _glyphs == nullptr )
		return ret;

	float trans = 0.0f;
	int pgm_no = 1;
	ret.push_back( TNC150::Program( pgm_no++ ) );

	for( auto g = _glyphs->begin(); g != _glyphs->end(); g++ )
	{
		if( ret.back().size() + g->size() > 950 )
			ret.push_back( TNC150::Program( pgm_no++ ) );

		if( g != _glyphs->begin() )
			g->translate( trans, 0.0f );

		trans = g->getRPos() + spacing;

		Engrave::LinearVector l = glyph2l( *g );
		for( auto i : l )
			ret.back().insert( std::make_shared<TNC150::InstrL>( i ) );
	}

	return ret;
}

Engrave::RotaryVector EngFlat::makeRotary( float spacing, float dia )
{
	Engrave::RotaryVector ret;

	if( _glyphs == nullptr )
		return ret;

	float angle = 0.0f;

	for( auto g = _glyphs->begin(); g != _glyphs->end(); g++ )
	{
		if( g != _glyphs->begin() )
			angle += 360.0f / (g->getWidth() / (dia * M_PI));

//		Engrave::LinearVector l = glyph2l( *g );
//		for( auto i : l )
//			ret.push_back( EngraveRotaryEntry{ i, angle } );
	}


	return ret;
}

} /* namespace heidenhersh */
