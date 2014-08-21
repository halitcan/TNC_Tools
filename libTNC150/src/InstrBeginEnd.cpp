/*
 * InstrBeginEnd.cpp
 *
 *  Created on: Aug 20, 2014
 *      Author: john
 */

#include "InstrBeginEnd.h"
#include <sstream>

namespace TNC150
{

InstrBeginEnd::InstrBeginEnd( const BeginEnd be, const uint8_t pgmNo ) : _be{ be }, _pgm_no{ pgmNo }, _unit{ Units::MM }
{
}

InstrBeginEnd::InstrBeginEnd( const BeginEnd be, const Units unit ) : _be{ be }, _pgm_no{ 1 }, _unit{ unit }
{
}

InstrBeginEnd::InstrBeginEnd( const BeginEnd be, const uint8_t pgmNo, const Units unit ) : _be{ be }, _pgm_no{ pgmNo }, _unit{ unit }
{
}

InstrBeginEnd::~InstrBeginEnd() { }

std::string InstrBeginEnd::toString( const uint16_t row )
{
	std::string be = _be == BeginEnd::Begin ? "BEGIN PGM " : "END PGM ";
	std::string u = _unit == Units::MM ? "MM" : "INCH";
	std::stringstream ret;
	ret << std::to_string( row ) << ' ' << be << std::to_string( _pgm_no ) << ' ' << u;

	return ret.str();
}

unsigned int InstrBeginEnd::rowCount()
{
	return 1;
}

bool InstrBeginEnd::isValid()
{
	if( _pgm_no < 1 )
		return false;
	else if( _pgm_no > 99 )
		return false;
	else if( _unit != Units::MM && _unit != Units::INCH )
		return false;
	else if( _be != BeginEnd::Begin && _be != BeginEnd::End )
		return false;

	return true;
}

} /* namespace TNC150 */
