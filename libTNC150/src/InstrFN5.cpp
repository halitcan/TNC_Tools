/*
 * InstrFN5.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "InstrFN5.h"

namespace TNC150
{

InstrFN5::InstrFN5( uint8_t q, float value ) : _q{ "Q", q }, _value{ new Field<float>{ "", value } }
{
}

InstrFN5::InstrFN5( uint8_t q, uint8_t qvalue ) : _q{ "Q", q }, _qvalue{ new Field<uint8_t>{ "Q", qvalue } }
{
}

InstrFN5::~InstrFN5()
{
}

std::string InstrFN5::toString( uint16_t row )
{
	std::string value;
	if( _value != nullptr )
		value = _value->toString();
	else if( _qvalue != nullptr )
		value = _qvalue->toString();

	return std::to_string( row ) + " FN 5 : " + _q.toString() + " = SQRT " + value;
}

} /* namespace TNC150 */
