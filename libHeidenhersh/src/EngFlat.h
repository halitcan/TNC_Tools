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
		EngFlat( hersh::GlyphSet &glyphs, const uint16_t feed, float zsafe, float zfinish, uint8_t n_cuts );
		virtual ~EngFlat();
		ProgramVector makeLinear( float spacing );
		Engrave::RotaryVector makeRotary( float spacing, float dia );
		void scale( const float s );
		void mirror( const bool mirror_x, const bool mirror_y );

	private:
		EngFlat();
		float _zsafe;
		float _zfinish;
		uint8_t _n_cuts;
};

} /* namespace heidenhersh */

#endif /* ENGFLAT_H_ */
