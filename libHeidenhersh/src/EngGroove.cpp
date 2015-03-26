/*
 * EngGroove.cpp
 *
 *  Created on: Mar 26, 2015
 *      Author: john
 */

#include "EngGroove.h"

namespace heidenhersh
{

EngGroove::EngGroove( hersh::GlyphSet &glyphs, const uint16_t feed, float zsafe, float depth )
	     : Engrave{ glyphs, feed, zsafe }, _depth{ depth }
{

}

EngGroove::EngGroove( hersh::GlyphSet &glyphs, const uint16_t feed, float zsafe, float depth, uint8_t n_cuts )
	     : Engrave{ glyphs, feed, zsafe, n_cuts }, _depth{ depth }
{

}

EngGroove::EngGroove() : _depth{ -0.3f }
{
}

EngGroove::~EngGroove()
{
}

Engrave::ProgramVector EngGroove::makeLinear()
{
	ProgramVector ret;

	return ret;
}

Engrave::RotaryVector EngGroove::makeRotary( float dia )
{
	ProgramVector pgm_ret;
	std::vector<float> angle_ret;

	if( _glyphs == nullptr )
		return RotaryVector{ pgm_ret, angle_ret };

	return RotaryVector{ pgm_ret, angle_ret };
}


} //namespace
