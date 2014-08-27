/*
 * Direction.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef DIRECTION_H_
#define DIRECTION_H_

#include "Field.h"

namespace TNC150
{

class Direction : public Field<char>
{
	public:
		Direction();
		Direction( const Dir dir );
		~Direction();
};

} /* namespace TNC150 */

#endif /* DIRECTION_H_ */
