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

		Engrave( hersh::GlyphSet &glyphs, uint16_t feed, float zsafe );
		Engrave( hersh::GlyphSet &glyphs, uint16_t feed, float zsafe, uint8_t n_cuts );
		virtual ~Engrave();
		virtual ProgramVector makeLinear() = 0;
		virtual RotaryVector makeRotary( float dia ) = 0;
		void setNCuts( const uint8_t value );
		void setSpacing( const float value );
		void setFastFeed( const uint16_t value );
		void scale( const float s );
		void mirror( const bool mirror_x, const bool mirror_y );

	protected:
		hersh::GlyphSet *_glyphs;
		LinearVector glyph2l( hersh::Glyph g );
		uint16_t _wfeed;
		uint16_t _ffeed;
		float _zsafe;
		uint8_t _n_cuts;
		float _spacing;
		Engrave();

	private:
};

} /* namespace heidenhersh */

#endif /* ENGRAVE_H_ */
