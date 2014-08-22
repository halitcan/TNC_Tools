/*
 * ToolRadiusCompensation.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "ToolRadiusCompensation.h"

namespace TNC150
{

ToolRadiusCompensation::ToolRadiusCompensation() : Field<char>{ "R" }
{
}

ToolRadiusCompensation::ToolRadiusCompensation( Dir dir ) : Field<char>{ "R" }
{
	if( dir == Dir::Positive )
		setValue( '+' );
	else
		setValue( '-' );
}

ToolRadiusCompensation::~ToolRadiusCompensation() { }

} /* namespace TNC150 */
