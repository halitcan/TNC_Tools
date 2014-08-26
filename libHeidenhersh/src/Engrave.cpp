/*
 * Engrave.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "Engrave.h"

namespace heidenhersh
{

Engrave::Engrave() : _glyphs{ nullptr }
{
}

Engrave::Engrave( hersh::Glyph::GlyphVector &glyphs ) : _glyphs{ &glyphs }
{
}

Engrave::~Engrave()
{
}

} /* namespace heidenhersh */
