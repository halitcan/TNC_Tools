/*
 * ToolRadiusCompensation.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "ToolRadiusCompensation.h"

namespace TNC150
{

ToolRadiusCompensation::ToolRadiusCompensation()
{
}

ToolRadiusCompensation::ToolRadiusCompensation( Dir dir ) : _dir{ new Dir{ dir } }
{
}

ToolRadiusCompensation::~ToolRadiusCompensation() { }

std::string ToolRadiusCompensation::toString()
{
	if( _dir == nullptr )
		return "R";

	if( *_dir == Dir::Plus )
		return "R+";

	return "R-";
}

} /* namespace TNC150 */
