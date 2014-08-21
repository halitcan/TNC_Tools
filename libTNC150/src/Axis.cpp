/*
 * Axis.cpp
 *
 *  Created on: Aug 20, 2014
 *      Author: john
 */

#include "Axis.h"
#include <sstream>

namespace TNC150
{

Axis::Axis( const Name name, const float value ) : _name{ name }, _value{ value }, _inc{ false }
{
}

Axis::Axis( const Name name, const float value, const bool incremental ) : _name{ name }, _value{ value }, _inc{ incremental }
{
}

Axis::~Axis() { }

std::string Axis::toString()
{
	char sign = _value >= 0 ? '+' : '\0';
	std::stringstream ret;
	ret << nameString() << sign << _value;

	return ret.str();
}

std::string Axis::nameString()
{
	std::string i = _inc ? "I" : std::string();
	switch( _name )
	{
		case Name::X:
			return i + "X";
		case Name::Y:
			return i + "Y";
		case Name::IV:
			return i + "IV";
		default:
			throw UnknownAxisName();
			break;
	}

	return std::string();
}

} /* namespace TNC150 */
