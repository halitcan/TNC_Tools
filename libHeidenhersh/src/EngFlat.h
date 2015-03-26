/*
 * EngFlat.h
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#ifndef ENGFLAT_H_
#define ENGFLAT_H_

#include "Engrave.h"

namespace heidenhersh
{

class EngFlat : public Engrave
{
	public:
		EngFlat( hersh::GlyphSet &glyphs, const uint16_t feed, float zsafe, float zfinish );
		EngFlat( hersh::GlyphSet &glyphs, const uint16_t feed, float zsafe, float zfinish, uint8_t n_cuts );
		virtual ~EngFlat();
		ProgramVector makeLinear();
		Engrave::RotaryVector makeRotary( float dia );

	private:
		EngFlat();
		float _zfinish;
};

} /* namespace heidenhersh */

#endif /* ENGFLAT_H_ */
