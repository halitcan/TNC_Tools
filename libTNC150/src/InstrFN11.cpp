/*
 * InstrFN11.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: john
 */

#include "InstrFN11.h"

namespace TNC150
{

InstrFN11::InstrFN11()
{
}

InstrFN11::InstrFN11( uint8_t q, float value, uint8_t lbl ) : _q{ "Q", q }, _value{ "", value }, _lbl{ "LBL ", lbl }
{
}

InstrFN11::InstrFN11( uint8_t q, uint8_t qvalue, Field<float>::Dir qdir, uint8_t lbl ) : _q{ "Q", q }, _value{ "", qvalue, qdir }, _lbl{ "LBL ", lbl }
{
}

InstrFN11::~InstrFN11()
{
}

std::string InstrFN11::toString( const uint16_t row )
{
	return std::to_string( row ) + " FN 11 : IF " + _q.toString() + " GT " + _value.toString() + " GOTO " + _lbl.toString();
}

unsigned int InstrFN11::rowCount()
{
	return 1;
}

bool InstrFN11::isValid()
{
	return true;
}

} /* namespace TNC150 */
