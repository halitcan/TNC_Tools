/*
 * Engrave.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "Engrave.h"

namespace heidenhersh
{

Engrave::Engrave( uint16_t feed ) : _glyphs{ nullptr }, _wfeed{ feed }, _ffeed{ 6000 }
{
}

Engrave::Engrave( hersh::Glyph::GlyphVector &glyphs, uint16_t feed ) : _glyphs{ &glyphs }, _wfeed{ feed }, _ffeed{ 6000 }
{
}

Engrave::Engrave() : _glyphs{ nullptr }, _wfeed{ 30 }, _ffeed{ 6000 }
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

} /* namespace heidenhersh */

