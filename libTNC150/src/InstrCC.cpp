/*
 * InstrCC.cpp
 *
 *  Created on: Aug 20, 2014
 *      Author: john
 */

#include "InstrCC.h"
#include <sstream>

namespace TNC150
{

InstrCC::InstrCC( Axis first, Axis second ) : _axis1{ first }, _axis2{ second }
{
}

InstrCC::~InstrCC() { }

std::string InstrCC::toString()
{
	return "CC " + _axis1.toString() + _axis2.toString();
}

unsigned int InstrCC::rowCount()
{
	return 1;
}

bool InstrCC::isValid()
{
	return true;
}

} /* namespace TNC150 */
