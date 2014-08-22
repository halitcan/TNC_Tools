/*
 * Axis.cpp
 *
 *  Created on: Aug 20, 2014
 *      Author: john
 */

#include "Axis.h"
#include <sstream>
#include <iomanip>

#include <iostream>

namespace TNC150
{

Axis::Axis() : _name{ Name::X }, _inc{ false }
{
}

Axis::Axis( const Name name, const float value ) : _name{ name }, _inc{ false }
{
	setLabel( axisName() );
	setValue( value );
}

Axis::Axis( const Name name, const float value, const bool incremental ) : _name{ name }, _inc{ incremental }
{
	setLabel( axisName() );
	setValue( value );
}

Axis::Axis( const Axis &other ) : Field{ other }, _name{ other._name }, _inc{ other._inc }
{
}

Axis::~Axis() { }


std::string Axis::axisName()
{
	std::string ret;
	if( _inc )
		ret = 'I';

	switch( _name )
	{
		case Name::X:
			ret.push_back( 'X' );
			break;
		case Name::Y:
			ret.push_back( 'Y' );
			break;
		case Name::Z:
			ret.push_back( 'Z' );
			break;
		case Name::IV:
			ret.push_back( 'I' );
			ret.push_back( 'V' );
			break;
		default:
			break;
	}

	return ret;
}

} /* namespace TNC150 */
