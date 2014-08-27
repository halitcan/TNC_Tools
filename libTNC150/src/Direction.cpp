/*
 * Direction.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "Direction.h"

namespace TNC150
{

Direction::Direction() : Field<char>{ "DR" }
{
}

Direction::Direction( const Dir dir) : Field<char>{ "DR" }
{
	if( dir == Dir::Positive )
		setValue( '+' );
	else
		setValue( '-' );
}

Direction::~Direction() { }

} /* namespace TNC150 */
