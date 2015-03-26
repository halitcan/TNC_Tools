/*
 * EngGroove.h
 *
 *  Created on: Mar 26, 2015
 *      Author: john
 */

#ifndef ENGGROOVE_H_
#define ENGGROOVE_H_

#include "Engrave.h"

namespace heidenhersh
{
class EngGroove : public Engrave
{
public:
	EngGroove( hersh::GlyphSet &glyphs, const uint16_t feed, float zsafe, float depth );
	EngGroove( hersh::GlyphSet &glyphs, const uint16_t feed, float zsafe, float depth, uint8_t n_cuts );
	virtual ~EngGroove();
	ProgramVector makeLinear();
	Engrave::RotaryVector makeRotary( float dia );

private:
	EngGroove();
	float _depth;
};

}
#endif /* ENGGROOVE_H_ */
