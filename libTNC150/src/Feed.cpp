/*
 * Feed.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "Feed.h"

namespace TNC150
{

Feed::Feed()
{
}

Feed::Feed( uint16_t value ) : _value{ new uint16_t{ value } }
{
}

Feed::~Feed() { }

std::string Feed::toString()
{
	if( _value == nullptr )
		return "F";

	return 'F' + std::to_string( *_value );
}

} /* namespace TNC150 */
