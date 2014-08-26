/*
 * EngFlat.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "EngFlat.h"

namespace heidenhersh
{

EngFlat::EngFlat( std::vector<hersh::Glyph> &glyphs ) : Engrave{ glyphs }
{
}

EngFlat::~EngFlat()
{
}

Engrave::LinearVector EngFlat::makeLinear( float scale, float spacing )
{
	std::vector<TNC150::InstrL> ret;

	if( _glyphs == nullptr )
		return ret;

	for( auto g = _glyphs->begin(); g != _glyphs->end(); g++ )
	{
		g->scale( scale );

		for( auto &p : g->getPaths() )
		{
			ret.push_back( TNC150::InstrL{ TNC150::Axis{ TNC150::Axis::Name::Z, 0, TNC150::Field<float>::Dir::Positive } } );
			if( p.size() > 0 )
			{
				p[0].scale( scale );
				ret.push_back( TNC150::InstrL{ TNC150::Axis{ TNC150::Axis::Name::X, p[0].getX() },
											   TNC150::Axis{ TNC150::Axis::Name::Y, p[0].getY() } } );
				ret.push_back( TNC150::InstrL{ TNC150::Axis{ TNC150::Axis::Name::Z, 1,
															 TNC150::Field<float>::Dir::Positive } } );
				for( auto v = p.begin() + 1; v != p.end(); v++ )
				{
					ret.push_back( TNC150::InstrL{ TNC150::Axis{ TNC150::Axis::Name::X, v->getX() },
												   TNC150::Axis{ TNC150::Axis::Name::Y, v->getY() } } );
				}
			}
		}
	}

	return ret;
}

Engrave::RotaryVector EngFlat::makeRotary( float wheelDia, float scale )
{
}

} /* namespace heidenhersh */
