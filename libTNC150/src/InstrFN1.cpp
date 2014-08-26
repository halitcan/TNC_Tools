/*
 * InstrFN0.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "InstrFN2.h"

namespace TNC150
{

InstrFN2::InstrFN2( uint8_t q, float lvalue, float rvalue )
		 : _q{ "Q", q }, _lvalue{ new Field<float>{ "", lvalue } }, _rvalue{ new Field<float>{ "", rvalue } }
{
}

InstrFN2::InstrFN2( uint8_t q, uint8_t lQvalue, uint8_t rQvalue )
		 : _q{ "Q", q }, _qlvalue{ new Field<uint8_t>{ "Q", lQvalue } }, _qrvalue{ new Field<uint8_t>{ "Q", rQvalue } }
{
}

InstrFN2::InstrFN2( uint8_t q, float lvalue, uint8_t rQvalue )
		 : _q{ "Q", q }, _lvalue{ new Field<float>{ "", lvalue } }, _qrvalue{ new Field<uint8_t>{ "Q", rQvalue } }
{
}

InstrFN2::InstrFN2( uint8_t q, uint8_t lQvalue, float rvalue )
		 : _q{ "Q", q }, _qlvalue{ new Field<uint8_t>{ "Q", lQvalue } }, _rvalue{ new Field<float>{ "", rvalue } }
{
}

InstrFN2::~InstrFN2()
{
}

std::string InstrFN2::toString( uint16_t row )
{
	std::string lval, rval;

	if( _lvalue != nullptr )
		lval = _lvalue->toString();
	else if( _qlvalue != nullptr )
		lval = _qlvalue->toString();
	if( _rvalue != nullptr )
		rval = _rvalue->toString();
	else if( _qrvalue != nullptr )
		rval = _qrvalue->toString();

	return "FN 2 : " + _q.toString() + " = " + lval + " - " + rval;
}

} /* namespace TNC150 */
