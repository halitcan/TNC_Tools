/*
 * InstrBegin.cpp
 *
 *  Created on: Aug 20, 2014
 *      Author: john
 */

#include "InstrBegin.h"
#include <sstream>

namespace TNC150
{

InstrBegin::InstrBegin() : _pgm_no{ 1 }, _unit{ Units::MM }
{
}

InstrBegin::InstrBegin( const uint8_t pgmNo ) : _pgm_no{ pgmNo }, _unit{ Units::MM }
{
}

InstrBegin::InstrBegin( Units unit ) : _pgm_no{ 1 }, _unit{ unit }
{
}

InstrBegin::InstrBegin( const uint8_t pgmNo, const Units unit ) : _pgm_no{ pgmNo }, _unit{ unit }
{
}

InstrBegin::~InstrBegin() { }

std::string InstrBegin::toString()
{
	std::string u = _unit == Units::MM ? "MM" : "INCH";
	std::stringstream ret;
	ret << "BEGIN PGM" << _pgm_no << ' ' << u;

	return ret.str();
}

} /* namespace TNC150 */
