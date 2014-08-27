/*
 * InstrFN7.h
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#ifndef InstrFN7_H_
#define InstrFN7_H_

#include "AbstractInstruction.h"
#include "Field.h"
#include <memory>

namespace TNC150
{

class InstrFN7 : public AbstractInstruction
{
	public:
		InstrFN7( uint8_t q, float value );
		InstrFN7( uint8_t q, uint8_t qvalue );
		virtual ~InstrFN7();
		std::string toString( uint16_t row );

	private:
		Field<uint8_t> _q;
		std::unique_ptr<Field<float>> _value;
		std::unique_ptr<Field<uint8_t>> _qvalue;
};

} /* namespace TNC150 */

#endif /* InstrFN7_H_ */
