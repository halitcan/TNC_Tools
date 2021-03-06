/*
 * InstrFN0.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "InstrFN0.h"

namespace TNC150
{

InstrFN0::InstrFN0( uint8_t q, float value ) : _q{ "Q", q }, _value{ "", value }
{
}

InstrFN0::InstrFN0( uint8_t q, uint8_t rvalue, Field<float>::Dir rdir ) : _q{ "Q", q }, _value{ "", rvalue, rdir }
{
}

InstrFN0::~InstrFN0()
{
}

std::string InstrFN0::toString( uint16_t row )
{
	return "FN 0 : " + _q.toString() + " = " + _value.toString();
}

} /* namespace TNC150 */

unsigned int TNC150::InstrFN0::rowCount()
{
	return 1;
}

bool TNC150::InstrFN0::isValid()
{
	return true;
}
