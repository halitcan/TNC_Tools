/*
 * EngFlat.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "EngFlat.h"
#include <TNC150/InstrFN0.h>
#include <TNC150/InstrLabelSet.h>
#include <TNC150/InstrFN11.h>
#include <TNC150/InstrFN2.h>
#include <cmath>

namespace heidenhersh
{

EngFlat::EngFlat( hersh::GlyphSet &glyphs, const uint16_t feed, float zsafe, float zfinish, uint8_t n_cuts )
	    : Engrave{ glyphs, feed }, _zsafe{ zsafe }, _zfinish{ zfinish }, _n_cuts{ n_cuts }
{
}

EngFlat::EngFlat() : _zsafe{ 0.2f }, _zfinish{ -0.3f }, _n_cuts{ 2 }
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
	uint8_t pgm_no = 1;
	uint8_t lblNo = 0;
	ret.push_back( TNC150::Program( pgm_no++ ) );

	ret.back().insert( std::make_shared<TNC150::InstrFN0>( 0, _zsafe ) );

	for( auto g = _glyphs->begin(); g != _glyphs->end(); g++ )
	{
		if( ret.back().size() + g->size() > 980 )
		{
			ret.back().insert( std::make_shared<TNC150::InstrL>( TNC150::Axis( TNC150::Axis::Name::Z, _zsafe ), 2, 6000 ) );
			ret.push_back( TNC150::Program( pgm_no++ ) );
			ret.back().insert( std::make_shared<TNC150::InstrFN0>( 0, _zsafe ) );
			lblNo = 0;
		}

		if( g != _glyphs->begin() )
			g->translate( trans, 0.0f );

		trans = g->getRPos() + spacing;

		Engrave::LinearVector l = glyph2l( *g );

		ret.back().insert( std::make_shared<TNC150::InstrFN0>( 1, 0.0f ) );
		ret.back().insert( std::make_shared<TNC150::InstrLabelSet>( lblNo ) );
		ret.back().insert( std::make_shared<TNC150::InstrFN2>( 1, 1, TNC150::Field<float>::Dir::Positive, _zfinish / _n_cuts ) );

		for( auto i : l )
			ret.back().insert( std::make_shared<TNC150::InstrL>( i ) );

		ret.back().insert( std::make_shared<TNC150::InstrFN11>( 1, _zfinish, lblNo ) );
		lblNo++;
	}

	ret.back().insert( std::make_shared<TNC150::InstrL>( TNC150::Axis( TNC150::Axis::Name::Z, _zsafe ), 2, 6000 ) );

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

void EngFlat::scale( const float s )
{
	if( _glyphs == nullptr )
		return;

	_glyphs->scale( s );
}

void EngFlat::mirror( const bool mirror_x, const bool mirror_y )
{
	if( _glyphs == nullptr )
		return;

	_glyphs->mirror( mirror_x, mirror_y );
}

} /* namespace heidenhersh */

