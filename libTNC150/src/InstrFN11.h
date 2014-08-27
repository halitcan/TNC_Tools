/*
 * InstrFN11.h
 *
 *  Created on: Aug 27, 2014
 *      Author: john
 */

#ifndef INSTRFN11_H_
#define INSTRFN11_H_

#include "AbstractInstruction.h"
#include "Field.h"

namespace TNC150
{

class InstrFN11 : public AbstractInstruction
{
	public:
		InstrFN11( uint8_t q, float value, uint8_t lbl );
		InstrFN11( uint8_t q, uint8_t qvalue, Field<float>::Dir qdir, uint8_t lbl );
		virtual ~InstrFN11();
		std::string toString( const uint16_t row );
		unsigned int rowCount();
		bool isValid();

	private:
		InstrFN11();
		Field<uint8_t> _q;
		Field<float> _value;
		Field<uint8_t> _lbl;

};

} /* namespace TNC150 */

#endif /* INSTRFN11_H_ */
