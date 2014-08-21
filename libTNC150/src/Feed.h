/*
 * Feed.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef FEED_H_
#define FEED_H_

#include <memory>
#include <string>

extern "C"
{
#include <inttypes.h>
}

namespace TNC150
{

class Feed
{
	public:
		Feed();
		Feed( uint16_t value );
		virtual ~Feed();
		std::string toString();

	private:
		std::unique_ptr<uint16_t> _value;
};

} /* namespace TNC150 */

#endif /* FEED_H_ */
