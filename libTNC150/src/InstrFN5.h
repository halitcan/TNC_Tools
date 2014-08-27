/*
 * InstrFN5.h
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#ifndef INSTRFN5_H_
#define INSTRFN5_H_

#include "AbstractInstruction.h"
#include "Field.h"
#include <memory>

namespace TNC150
{

class InstrFN5 : public AbstractInstruction
{
	public:
		InstrFN5( uint8_t q, float value );
		InstrFN5( uint8_t q, uint8_t qvalue );
		virtual ~InstrFN5();
		std::string toString( uint16_t row );

	private:
		Field<uint8_t> _q;
		std::unique_ptr<Field<float>> _value;
		std::unique_ptr<Field<uint8_t>> _qvalue;
};

} /* namespace TNC150 */

#endif /* INSTRFN5_H_ */
