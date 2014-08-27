/*
 * InstrL.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "InstrL.h"

namespace TNC150
{

InstrL::InstrL( const uint8_t mFunction ) : _m_func{ mFunction }
{
}

InstrL::InstrL( const uint8_t mFunction, const uint16_t feed ) : _m_func{ mFunction }, _feed{ feed }
{
}

InstrL::InstrL( const Axis axis ) : _axis1{ new Axis{ axis } }
{
}

InstrL::InstrL( const Axis axis, const uint16_t feed ) : _axis1{ new Axis{ axis } }, _feed{ feed }
{
}

InstrL::InstrL( const Axis axis, const uint8_t mFunction ) : _axis1{ new Axis{ axis } }, _m_func{ mFunction }
{
}

InstrL::InstrL( const Axis axis, const uint8_t mFunction, const uint16_t feed ) : _axis1{ new Axis{ axis } }, _m_func{ mFunction }, _feed{ feed }
{
}

InstrL::InstrL( const Axis axis1, const Axis axis2 ) : _axis1{ new Axis{ axis1 } }, _axis2{ new Axis{ axis2 } }
{
}

InstrL::InstrL( const Axis axis1, const Axis axis2, const uint16_t feed ) : _axis1{ new Axis{ axis1 } }, _axis2{ new Axis{ axis2 } }, _feed{ feed }
{
}

InstrL::InstrL( const Axis axis1, const Axis axis2, const uint8_t mFunction )
	   : _axis1{ new Axis{ axis1 } }, _axis2{ new Axis{ axis2 } }, _m_func{ mFunction }
{
}

InstrL::InstrL( const Axis axis1, const Axis axis2, const uint8_t mFunction, const uint16_t feed )
	   : _axis1{ new Axis{ axis1 } }, _axis2{ new Axis{ axis2 } }, _m_func{ mFunction }, _feed{ feed }
{
}

InstrL::InstrL( const Axis axis1, const Axis axis2, const Axis axis3 )
	   : _axis1{ new Axis{ axis1 } }, _axis2{ new Axis{ axis2 } }, _axis3{ new Axis{ axis3 } }
{
}

InstrL::InstrL( const Axis axis1, const Axis axis2, const Axis axis3, const uint16_t feed )
	   : _axis1{ new Axis{ axis1 } }, _axis2{ new Axis{ axis2 } }, _axis3{ new Axis{ axis3 } }, _feed{ feed }
{
}

InstrL::InstrL( const Axis axis1, const Axis axis2, const Axis axis3, const uint8_t mFunction )
	   : _axis1{ new Axis{ axis1 } }, _axis2{ new Axis{ axis2 } }, _axis3{ new Axis{ axis3 } },
	     _m_func{ mFunction }
{
}

InstrL::InstrL( const Axis axis1, const Axis axis2, const Axis axis3, const uint8_t mFunction, const uint16_t feed )
	   : _axis1{ new Axis{ axis1 } }, _axis2{ new Axis{ axis2 } }, _axis3{ new Axis{ axis3 } },
	     _m_func{ mFunction }, _feed{ feed }
{
}

InstrL::InstrL( const InstrL &other ) : _m_func{ other._m_func }, _trc{ other._trc }, _feed{ other._feed }
{
	if( other._axis1 != nullptr )
		_axis1 = std::unique_ptr<Axis>{ new Axis{ *other._axis1 } };
	if( other._axis2 != nullptr )
		_axis2 = std::unique_ptr<Axis>{ new Axis{ *other._axis2 } };
	if( other._axis3 != nullptr )
		_axis3 = std::unique_ptr<Axis>{ new Axis{ *other._axis3 } };
}

InstrL::~InstrL() { }

std::string InstrL::toString( const uint16_t row )
{
	return std::to_string( row ) + " L" + axis1String() + axis2String() + axis3String() + ' ' +
			_trc.toString() + ' ' +	_feed.toString() + ' ' + _m_func.toString();
}

unsigned int InstrL::rowCount()
{
	return 1;
}

bool InstrL::isValid()
{
	if( _axis1 == nullptr && _axis2 == nullptr && _axis3 == nullptr )
		return false;

	return true;
}

void InstrL::setFeed( uint16_t f )
{
	_feed.setValue( f );
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

} /* namespace TNC150 */
