/*
 * MFunction.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "MFunction.h"
#include <sstream>
#include <iomanip>

namespace TNC150
{

MFunction::MFunction()
{
}

MFunction::MFunction( uint8_t value ) : _value{ new uint8_t{ value } }
{
}

MFunction::~MFunction() { }

std::string MFunction::toString()
{
	std::stringstream ret;
	ret << "M";

	if( _value != nullptr )
		ret << std::setfill( '0' ) << std::setw( 2 ) << *_value;

	return ret.str();
}

} /* namespace TNC150 */
