/*
 * Engrave.h
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#ifndef ENGRAVE_H_
#define ENGRAVE_H_

#include <vector>
#include <Hersh/GlyphSet.h>
#include <TNC150/InstrL.h>
#include <TNC150/Program.h>


namespace heidenhersh
{

class Engrave
{
	public:
		typedef std::vector<TNC150::InstrL> LinearVector;
		typedef std::pair<std::vector<TNC150::Program>, std::vector<float>> RotaryVector;
		typedef std::vector<TNC150::Program> ProgramVector;

		Engrave( uint16_t feed );
		Engrave( hersh::GlyphSet &glyphs, uint16_t feed );
		virtual ~Engrave();
		virtual ProgramVector makeLinear( float spacing ) = 0;
		virtual RotaryVector makeRotary( float spacing, float dia ) = 0;

	protected:
		hersh::GlyphSet *_glyphs;
		LinearVector glyph2l( hersh::Glyph g );
		uint16_t _wfeed;
		uint16_t _ffeed;
		Engrave();

	private:
};

} /* namespace heidenhersh */

#endif /* ENGRAVE_H_ */
