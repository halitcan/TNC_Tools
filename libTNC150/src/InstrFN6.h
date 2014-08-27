/*
 * InstrFN6.h
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#ifndef InstrFN6_H_
#define InstrFN6_H_

#include "AbstractInstruction.h"
#include "Field.h"
#include <memory>

namespace TNC150
{

class InstrFN6 : public AbstractInstruction
{
	public:
		InstrFN6( uint8_t q, float value );
		InstrFN6( uint8_t q, uint8_t qvalue );
		virtual ~InstrFN6();
		std::string toString( uint16_t row );

	private:
		Field<uint8_t> _q;
		std::unique_ptr<Field<float>> _value;
		std::unique_ptr<Field<uint8_t>> _qvalue;
};

} /* namespace TNC150 */

#endif /* InstrFN6_H_ */
