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

MFunction::MFunction() : Field<uint8_t>{ "M" }
{
}

MFunction::MFunction( uint8_t value ) : Field<uint8_t>{ "M" }
{
	setValue( value );
}

MFunction::~MFunction() { }

} /* namespace TNC150 */
