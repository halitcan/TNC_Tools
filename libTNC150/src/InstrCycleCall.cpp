/*
 * InstrCycleCall.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "InstrCycleCall.h"

namespace TNC150
{

InstrCycleCall::InstrCycleCall()
{
}

InstrCycleCall::InstrCycleCall( uint8_t mFunc ) : _m_func{ mFunc }
{
}

InstrCycleCall::~InstrCycleCall() { }

std::string InstrCycleCall::toString( const uint16_t row )
{
	return std::to_string( row ) + " CYCLE CALL " + _m_func.toString();
}

unsigned int InstrCycleCall::rowCount()
{
	return 1;
}

bool InstrCycleCall::isValid()
{
	return true;
}

} /* namespace TNC150 */
