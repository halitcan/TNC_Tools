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
		EngFlat( hersh::GlyphSet &glyphs, const uint16_t feed );
		virtual ~EngFlat();
		ProgramVector makeLinear( float spacing );
		Engrave::RotaryVector makeRotary( float spacing, float dia );
		void scale( const float s );
		void mirror( const bool mirror_x, const bool mirror_y );

	private:
		EngFlat();
};

} /* namespace heidenhersh */

#endif /* ENGFLAT_H_ */
