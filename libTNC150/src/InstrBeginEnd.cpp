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

InstrBeginEnd::InstrBeginEnd( const BeginEnd be, const uint8_t pgmNo ) : _be{ be }, _pgm_no{ "PGM ", pgmNo }, _unit{ Units::MM }
{
}

InstrBeginEnd::InstrBeginEnd( const BeginEnd be, const Units unit ) : _be{ be }, _pgm_no{ "PGM ", 1 }, _unit{ unit }
{
}

InstrBeginEnd::InstrBeginEnd( const BeginEnd be, const uint8_t pgmNo, const Units unit ) : _be{ be }, _pgm_no{ "PGM ", pgmNo }, _unit{ unit }
{
}

InstrBeginEnd::~InstrBeginEnd() { }

std::string InstrBeginEnd::toString( const uint16_t row )
{
	std::string be = _be == BeginEnd::Begin ? "BEGIN " : "END ";
	std::string u = _unit == Units::MM ? "MM" : "INCH";

	return std::to_string( row ) + ' ' + be + _pgm_no.toString() + ' ' + u;
}

unsigned int InstrBeginEnd::rowCount()
{
	return 1;
}

bool InstrBeginEnd::isValid()
{
	if( _pgm_no.value() < 1 )
		return false;
	else if( _pgm_no.value() > 99 )
		return false;
	else if( _unit != Units::MM && _unit != Units::INCH )
		return false;
	else if( _be != BeginEnd::Begin && _be != BeginEnd::End )
		return false;

	return true;
}

} /* namespace TNC150 */
