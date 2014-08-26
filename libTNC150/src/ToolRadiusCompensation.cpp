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

ToolRadiusCompensation::ToolRadiusCompensation( Compensation comp ) : Field<char>{ "R" }
{
	if( comp == Compensation::Right )
		setValue( 'R' );
	else
		setValue( 'L' );
}

ToolRadiusCompensation::~ToolRadiusCompensation() { }

} /* namespace TNC150 */
