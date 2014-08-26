/*
 * Engrave.h
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#ifndef ENGRAVE_H_
#define ENGRAVE_H_

#include <vector>
#include <Hersh/Glyph.h>
#include <TNC150/InstrL.h>


namespace heidenhersh
{

class Engrave
{
	public:
		typedef std::vector<TNC150::InstrL> LinearVector;
		typedef std::pair<std::vector<TNC150::InstrL>, std::vector<float>> RotaryVector;

		Engrave();
		Engrave( hersh::Glyph::GlyphVector &glyphs );
		virtual ~Engrave();
		virtual LinearVector makeLinear( float scale, float spacing ) = 0;
		virtual RotaryVector makeRotary( float wheelDia, float scale ) = 0;

	protected:
		std::vector<hersh::Glyph> *_glyphs;
};

} /* namespace heidenhersh */

#endif /* ENGRAVE_H_ */
