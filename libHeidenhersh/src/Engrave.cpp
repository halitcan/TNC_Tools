/*
 * Engrave.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "Engrave.h"

namespace heidenhersh
{

Engrave::Engrave( hersh::GlyphSet &glyphs, uint16_t feed, float zsafe )
		: _glyphs{ &glyphs }, _wfeed{ feed }, _ffeed{ 6000 }, _zsafe{ zsafe }, _n_cuts{ 1 }, _spacing{ 0.0f }
{
}

Engrave::Engrave( hersh::GlyphSet &glyphs, uint16_t feed, float zsafe, uint8_t n_cuts )
						: _glyphs{ &glyphs }, _wfeed{ feed }, _ffeed{ 6000 }, _zsafe{ zsafe }, _n_cuts{ n_cuts }, _spacing{ 0.0f }
{
}

Engrave::Engrave() : _glyphs{ nullptr }, _wfeed{ 30 }, _ffeed{ 6000 }, _zsafe{ 0.2f }, _n_cuts{ 1 }, _spacing{ 0.0f }
{
}

Engrave::~Engrave()
{
}

Engrave::LinearVector Engrave::glyph2l( hersh::Glyph g )
{
	LinearVector ret;

	for( auto &p : g.getPaths() )
	{
		ret.push_back( TNC150::InstrL{ TNC150::Axis{ TNC150::Axis::Name::Z, (uint8_t)0, TNC150::Field<float>::Dir::Positive }, _ffeed } );
		if( p.size() > 0 )
		{
			ret.push_back( TNC150::InstrL{ TNC150::Axis{ TNC150::Axis::Name::X, p[0].getX() },
										   TNC150::Axis{ TNC150::Axis::Name::Y, p[0].getY() }, _ffeed } );
			ret.push_back( TNC150::InstrL{ TNC150::Axis{ TNC150::Axis::Name::Z, 1,
														 TNC150::Field<float>::Dir::Positive }, _wfeed } );
			for( auto v = p.begin() + 1; v != p.end(); v++ )
			{
				ret.push_back( TNC150::InstrL{ TNC150::Axis{ TNC150::Axis::Name::X, v->getX() },
											   TNC150::Axis{ TNC150::Axis::Name::Y, v->getY() }, _wfeed } );
			}
		}
	}

	return ret;
}

void Engrave::setNCuts( const uint8_t value )
{
	_n_cuts = value;
}

void Engrave::setSpacing( const float value )
{
	_spacing = value;
}

void Engrave::setFastFeed( const uint16_t value )
{
	_ffeed = value;
}

void Engrave::scale( float s )
{
	if( _glyphs == nullptr )
		return;

	_glyphs->scale( s );
}

void Engrave::mirror( bool mirror_x, bool mirror_y )
{
	if( _glyphs == nullptr )
		return;

	_glyphs->mirror( mirror_x, mirror_y );
}

} /* namespace heidenhersh */

