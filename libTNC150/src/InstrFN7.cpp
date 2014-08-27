/*
 * InstrFN7.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "InstrFN7.h"

namespace TNC150
{

InstrFN7::InstrFN7( uint8_t q, float value ) : _q{ "Q", q }, _value{ new Field<float>{ "", value } }
{
}

InstrFN7::InstrFN7( uint8_t q, uint8_t qvalue ) : _q{ "Q", q }, _qvalue{ new Field<uint8_t>{ "Q", qvalue } }
{
}

InstrFN7::~InstrFN7()
{
}

std::string InstrFN7::toString( uint16_t row )
{
	std::string value;
	if( _value != nullptr )
		value = _value->toString();
	else if( _qvalue != nullptr )
		value = _qvalue->toString();

	return std::to_string( row ) + " FN 6 : " + _q.toString() + " = COS " + value;
}

} /* namespace TNC150 */
