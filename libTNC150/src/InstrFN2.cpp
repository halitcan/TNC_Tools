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

InstrFN2::InstrFN2( uint8_t q, uint8_t lQvalue, Field<float>::Dir ldir, uint8_t rQvalue, Field<float>::Dir rdir )
		 : _q{ "Q", q }, _lvalue{ new Field<float>{ "Q", lQvalue, ldir } }, _rvalue{ new Field<float>{ "Q", rQvalue, rdir } }
{
}

InstrFN2::InstrFN2( uint8_t q, float lvalue, uint8_t rQvalue, Field<float>::Dir rdir )
		 : _q{ "Q", q }, _lvalue{ new Field<float>{ "", lvalue } }, _rvalue{ new Field<float>{ "Q", rQvalue, rdir } }
{
}

InstrFN2::InstrFN2( uint8_t q, uint8_t lQvalue, Field<float>::Dir ldir, float rvalue )
		 : _q{ "Q", q }, _lvalue{ new Field<float>{ "Q", lQvalue, ldir } }, _rvalue{ new Field<float>{ "", rvalue } }
{
}

InstrFN2::~InstrFN2()
{
}

std::string InstrFN2::toString( uint16_t row )
{
	return std::to_string( row ) + " FN 2 : " + _q.toString() + " = " + _lvalue->toString() + " + " + _rvalue->toString();
}

} /* namespace TNC150 */
