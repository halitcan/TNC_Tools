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
		EngFlat( std::vector<hersh::Glyph> &glyphs );
		virtual ~EngFlat();
		Engrave::LinearVector makeLinear( float scale, float spacing );
		Engrave::RotaryVector makeRotary( float wheelDia, float scale );

	private:
};

} /* namespace heidenhersh */

#endif /* ENGFLAT_H_ */
