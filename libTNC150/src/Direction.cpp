/*
 * Direction.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "Direction.h"

namespace TNC150
{

Direction::Direction() : _dir{ Dir::Positive }
{
}

Direction::Direction( Dir dir) : _dir{ dir }
{
}

Direction::~Direction() { }

std::string Direction::toString()
{
	if( _dir == Dir::Positive )
		return "DR+";

	return "DR-";
}

} /* namespace TNC150 */
