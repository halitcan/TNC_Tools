/*
 * InstrCycleCall.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef INSTRCYCLECALL_H_
#define INSTRCYCLECALL_H_

#include "AbstractInstruction.h"
#include "MFunction.h"

namespace TNC150
{

class InstrCycleCall : public AbstractInstruction
{
	public:
		InstrCycleCall();
		InstrCycleCall( uint8_t mFunc );
		virtual ~InstrCycleCall();
		std::string toString( uint16_t row );
		unsigned int rowCount();
		bool isValid();

	private:
		MFunction _m_func;
};

} /* namespace TNC150 */

#endif /* INSTRCYCLECALL_H_ */
