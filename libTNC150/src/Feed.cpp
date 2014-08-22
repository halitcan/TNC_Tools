/*
 * Feed.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "Feed.h"

namespace TNC150
{

Feed::Feed() : Field<uint16_t>{ "F" }
{
}

Feed::Feed( uint16_t value ) : Field<uint16_t>{ "F" }
{
	setValue( value );
}

Feed::~Feed() { }


} /* namespace TNC150 */
