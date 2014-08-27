/*
 * InstrFN0.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "InstrFN1.h"

namespace TNC150
{

InstrFN1::InstrFN1( uint8_t q, float lvalue, float rvalue )
		 : _q{ "Q", q }, _lvalue{ new Field<float>{ "", lvalue } }, _rvalue{ new Field<float>{ "", rvalue } }
{
}

InstrFN1::InstrFN1( uint8_t q, uint8_t lQvalue, Field<float>::Dir lDir, uint8_t rQvalue, Field<float>::Dir rDir )
		 : _q{ "Q", q }, _lvalue{ new Field<float>{ "", lQvalue, lDir } }, _rvalue{ new Field<float>{ "Q", rQvalue, rDir } }
{
}

InstrFN1::InstrFN1( uint8_t q, float lvalue, uint8_t rQvalue, Field<float>::Dir rDir )
		 : _q{ "Q", q }, _lvalue{ new Field<float>{ "", lvalue } }, _rvalue{ new Field<float>{ "Q", rQvalue, rDir } }
{
}

InstrFN1::InstrFN1( uint8_t q, uint8_t lQvalue, Field<float>::Dir lDir, float rvalue )
		 : _q{ "Q", q }, _lvalue{ new Field<float>{ "Q", lQvalue, lDir } }, _rvalue{ new Field<float>{ "", rvalue } }
{
}

InstrFN1::~InstrFN1()
{
}

std::string InstrFN1::toString( uint16_t row )
{
	return std::to_string( row ) + " FN 2 : " + _q.toString() + " = " + _lvalue->toString() + " + " + _rvalue->toString();
}

} /* namespace TNC150 */
