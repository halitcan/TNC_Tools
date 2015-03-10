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
#include <TNC150/InstrStop.h>
#include <cmath>

#include <iostream>

namespace heidenhersh
{

EngFlat::EngFlat( hersh::GlyphSet &glyphs, const uint16_t feed, float zsafe, float zfinish )
	    : Engrave{ glyphs, feed, zsafe }, _zfinish{ zfinish }
{
}

EngFlat::EngFlat() : _zfinish{ -0.3f }
{
}

EngFlat::~EngFlat()
{
}

Engrave::ProgramVector EngFlat::makeLinear()
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
		{
			trans = (g - 1)->getRPos() + (g->getLPos() * -1) + _spacing;
			g->translate( trans, 0.0f );
		}


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

Engrave::RotaryVector EngFlat::makeRotary( float dia )
{
	ProgramVector pgm_ret;
	std::vector<float> angle_ret;

	if( _glyphs == nullptr )
		return RotaryVector{ pgm_ret, angle_ret };

	float angle = 0.0f;
	uint8_t pgm_no = 1;
	uint8_t lblNo = 0;
	pgm_ret.push_back( TNC150::Program( pgm_no++ ) );

	pgm_ret.back().insert( std::make_shared<TNC150::InstrFN0>( 0, _zsafe ) );

	for( auto g = _glyphs->begin(); g != _glyphs->end(); g++ )
	{
		//Calculate angle
		if( g != _glyphs->begin() )
		{
			float dist = (g - 1)->getRPos() + (g->getLPos() * -1) + _spacing;
			angle += (360 * (dist / (dia * M_PI)));

			if( g->size() != 0 )	//Skip whitespace
			{
				angle_ret.push_back( angle );
				pgm_ret.back().insert( std::make_shared<TNC150::InstrStop>() );
			}
		}

		if( pgm_ret.back().size() + g->size() > 980 )
		{
			pgm_ret.back().insert( std::make_shared<TNC150::InstrL>( TNC150::Axis( TNC150::Axis::Name::Z, _zsafe ), 2, 6000 ) );
			pgm_ret.push_back( TNC150::Program( pgm_no++ ) );
			pgm_ret.back().insert( std::make_shared<TNC150::InstrFN0>( 0, _zsafe ) );
			lblNo = 0;
		}

		Engrave::LinearVector l = glyph2l( *g );

		pgm_ret.back().insert( std::make_shared<TNC150::InstrFN0>( 1, 0.0f ) );
		pgm_ret.back().insert( std::make_shared<TNC150::InstrLabelSet>( lblNo ) );
		pgm_ret.back().insert( std::make_shared<TNC150::InstrFN2>( 1, 1, TNC150::Field<float>::Dir::Positive, _zfinish / _n_cuts ) );

		for( auto i : l )
			pgm_ret.back().insert( std::make_shared<TNC150::InstrL>( i ) );

		pgm_ret.back().insert( std::make_shared<TNC150::InstrFN11>( 1, _zfinish, lblNo ) );
		lblNo++;
	}

	pgm_ret.back().insert( std::make_shared<TNC150::InstrL>( TNC150::Axis( TNC150::Axis::Name::Z, _zsafe ), 2, 6000 ) );

	return RotaryVector{ pgm_ret, angle_ret };
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

