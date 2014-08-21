/*
 * InstrBegin.h
 *
 *  Created on: Aug 20, 2014
 *      Author: john
 */

#ifndef INSTRBEGIN_H_
#define INSTRBEGIN_H_

#include "AbstractInstruction.h"

extern "C"
{
#include <inttypes.h>
}

namespace TNC150
{

class InstrBegin : public AbstractInstruction
{
	public:
		enum class Units { MM, INCH };
		InstrBegin();
		InstrBegin( const uint8_t pgmNo );
		InstrBegin( Units unit );
		InstrBegin( const uint8_t pgmNo, const Units unit );
		virtual ~InstrBegin();
		std::string toString();

	private:
		uint8_t _pgm_no;
		Units _unit;
};

} /* namespace TNC150 */

#endif /* INSTRBEGIN_H_ */
