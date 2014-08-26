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
#include <memory>

namespace TNC150
{

class InstrFN2 : public AbstractInstruction
{
	public:
		InstrFN2( uint8_t q, float lvalue, float rvalue );
		InstrFN2( uint8_t q, uint8_t lQvalue, uint8_t rQvalue );
		InstrFN2( uint8_t q, float lvalue, uint8_t rQvalue );
		InstrFN2( uint8_t q, uint8_t lQvalue, float rvalue );
		virtual ~InstrFN2();
		std::string toString( uint16_t row );

	private:
		Field<uint8_t> _q;
		std::unique_ptr<Field<float>> _lvalue;
		std::unique_ptr<Field<uint8_t>> _qlvalue;
		std::unique_ptr<Field<float>> _rvalue;
		std::unique_ptr<Field<uint8_t>> _qrvalue;
};

} /* namespace TNC150 */

#endif /* INSTRFN0_H_ */
