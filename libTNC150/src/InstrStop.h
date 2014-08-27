/*
 * InstrStop.h
 *
 *  Created on: Aug 28, 2014
 *      Author: john
 */

#ifndef INSTRSTOP_H_
#define INSTRSTOP_H_

#include "AbstractInstruction.h"
#include "MFunction.h"

namespace TNC150
{

class InstrStop : public AbstractInstruction
{
	public:
		InstrStop();
		InstrStop( const uint8_t m );
		virtual ~InstrStop();
		std::string toString( const uint16_t row );
		unsigned int rowCount();
		bool isValid();

	private:
		MFunction _m;
};

} /* namespace TNC150 */

#endif /* INSTRSTOP_H_ */
