/*
 * InstrStop.cpp
 *
 *  Created on: Aug 28, 2014
 *      Author: john
 */

#include "InstrStop.h"

namespace TNC150
{

InstrStop::InstrStop()
{
}

InstrStop::InstrStop( const uint8_t m ) : _m{ m }
{
}

InstrStop::~InstrStop()
{
}

std::string InstrStop::toString( const uint16_t row )
{
	return std::to_string( row ) + " STOP " + _m.toString();
}

unsigned int InstrStop::rowCount()
{
	return 1;
}

bool InstrStop::isValid()
{
	return true;
}

} /* namespace TNC150 */
