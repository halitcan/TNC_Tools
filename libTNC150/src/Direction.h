/*
 * Direction.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef DIRECTION_H_
#define DIRECTION_H_

#include <string>

namespace TNC150
{

class Direction
{
	public:
		enum class Dir{ Positive, Negative };
		Direction();
		Direction( Dir dir );
		virtual ~Direction();
		std::string toString();

	private:
		Dir _dir;
};

} /* namespace TNC150 */

#endif /* DIRECTION_H_ */
