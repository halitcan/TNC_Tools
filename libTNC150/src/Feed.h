/*
 * Feed.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef FEED_H_
#define FEED_H_

#include "Field.h"

namespace TNC150
{

class Feed : public Field<uint16_t>
{
	public:
		Feed();
		Feed( uint16_t value );
		~Feed();
};

} /* namespace TNC150 */

#endif /* FEED_H_ */
