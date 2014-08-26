/*
 * InstrCycle5.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef INSTRCYCLE5_H_
#define INSTRCYCLE5_H_

#include "AbstractInstruction.h"
#include "Feed.h"
#include "Direction.h"
#include "Field.h"

namespace TNC150
{

class InstrCycle5 : public AbstractInstruction
{
	public:
		InstrCycle5( float safe, float depth, float wdepth, uint16_t plungeFeed,
				     float radius, uint16_t feed, Direction::Dir dir );
		~InstrCycle5();
		std::string toString( const uint16_t row );
		unsigned int rowCount();
		bool isValid();

	private:
		Field<float> _safe;
		Field<float> _depth;
		Field<float> _w_depth;
		Field<float> _radius;
		Feed _plunge_feed;
		Feed _work_feed;
		Direction _dir;
};

} /* namespace TNC150 */

#endif /* INSTRCYCLE5_H_ */
