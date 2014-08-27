/*
 * InstrFN2.h
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#ifndef InstrFN2_H_
#define InstrFN2_H_

#include "AbstractInstruction.h"
#include "Field.h"

namespace TNC150
{

class InstrFN2 : public AbstractInstruction
{
	public:
		InstrFN2( uint8_t q, float lvalue, float rvalue );
		InstrFN2( uint8_t q, uint8_t lQvalue, Field<float>::Dir ldir, uint8_t rQvalue, Field<float>::Dir rdir );
		InstrFN2( uint8_t q, uint8_t lQvalue, Field<float>::Dir ldir, float rvalue );
		virtual ~InstrFN2();
		std::string toString( uint16_t row );
		unsigned int rowCount();
		bool isValid();

	private:
		Field<uint8_t> _q;
		Field<float> _lvalue;
		Field<float> _rvalue;
};

} /* namespace TNC150 */

#endif /* InstrFN2_H_ */
