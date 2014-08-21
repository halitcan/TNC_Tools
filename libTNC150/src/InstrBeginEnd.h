/*
 * InstrBegin.h
 *
 *  Created on: Aug 20, 2014
 *      Author: john
 */

#ifndef INSTRBEGIN_H_
#define INSTRBEGIN_H_

#include "AbstractInstruction.h"

namespace TNC150
{

class InstrBeginEnd : public AbstractInstruction
{
	public:
		enum class Units { MM, INCH };
		enum class BeginEnd{ Begin, End };
		InstrBeginEnd( const BeginEnd be, const uint8_t pgmNo );
		InstrBeginEnd( const BeginEnd be, const Units unit );
		InstrBeginEnd( const BeginEnd be, const uint8_t pgmNo, const Units unit );
		virtual ~InstrBeginEnd();
		std::string toString( const uint16_t row );
		unsigned int rowCount();
		bool isValid();

	private:
		BeginEnd _be;
		uint8_t _pgm_no;
		Units _unit;
};

} /* namespace TNC150 */

#endif /* INSTRBEGIN_H_ */
