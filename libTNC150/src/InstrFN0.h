/*
 * InstrFN0.h
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#ifndef INSTRFN0_H_
#define INSTRFN0_H_

#include "AbstractInstruction.h"
#include "Field.h"

namespace TNC150
{

class InstrFN0 : public AbstractInstruction
{
	public:
		InstrFN0( uint8_t q, float value );
		virtual ~InstrFN0();
		std::string toString( uint16_t row );

	private:
		Field<uint8_t> _q;
		Field<float> _value;
};

} /* namespace TNC150 */

#endif /* INSTRFN0_H_ */
