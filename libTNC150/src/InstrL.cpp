/*
 * InstrL.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "InstrL.h"

namespace TNC150
{

InstrL::InstrL( const uint8_t mFunction ) : _m_func{ new uint8_t{ mFunction } }
{
}

InstrL::InstrL( const Axis axis ) : _axis1{ new Axis{ axis } }
{
}

InstrL::InstrL( const Axis axis, const uint8_t mFunction ) : _axis1{ new Axis{ axis } }, _m_func{ new uint8_t{ mFunction } }
{
}

InstrL::InstrL( const Axis axis1, const Axis axis2 ) : _axis1{ new Axis{ axis1 } }, _axis2{ new Axis{ axis2 } }
{
}

InstrL::InstrL( const Axis axis1, const Axis axis2, const uint8_t mFunction )
	   : _axis1{ new Axis{ axis1 } }, _axis2{ new Axis{ axis2 } }, _m_func{ new uint8_t{ mFunction } }
{
}

InstrL::InstrL( const Axis axis1, const Axis axis2, const Axis axis3 )
	   : _axis1{ new Axis{ axis1 } }, _axis2{ new Axis{ axis2 } }, _axis3{ new Axis{ axis3 } }
{
}

InstrL::InstrL( const Axis axis1, const Axis axis2, const Axis axis3, const uint8_t mFunction )
	   : _axis1{ new Axis{ axis1 } }, _axis2{ new Axis{ axis2 } }, _axis3{ new Axis{ axis3 } },
	     _m_func{ new uint8_t{ mFunction } }
{
}

InstrL::~InstrL() { }

std::string InstrL::toString()
{
	return 'L' + axis1String() + axis2String() + axis3String() + mFuncString();
}

unsigned int InstrL::rowCount()
{
	return 1;
}

bool InstrL::isValid()
{
	if( _axis1 == nullptr && _axis2 == nullptr && _axis3 == nullptr && _m_func == nullptr )
		return false;

	return true;
}

std::string InstrL::axis1String()
{
	if( _axis1 != nullptr )
		return ' ' + _axis1->toString();

	return std::string();
}

std::string InstrL::axis2String()
{
	if( _axis2 != nullptr )
		return ' ' + _axis2->toString();

	return std::string();
}

std::string InstrL::axis3String()
{
	if( _axis3 != nullptr )
		return ' ' + _axis3->toString();

	return std::string();
}

std::string InstrL::mFuncString()
{
	if( _m_func != nullptr )
		return " M" + std::to_string( *_m_func );

	return " M";
}

} /* namespace TNC150 */
