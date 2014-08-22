/*
 * Field.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "Field.h"
#include <sstream>
#include <iomanip>

namespace TNC150
{

template<class F>
Field<F>::Field()
{
}

template<class F>
Field<F>::Field( std::string label ) : _label{ label }
{
}

template<class F>
Field<F>::Field( std::string label, F value ) : _label{ label }, _value{ new F{ value } }
{
}

template<class F>
Field<F>::Field( const Field &other ) : _label{ other._label }
{
	if( other._value != nullptr )
		_value = std::unique_ptr<F>( new F{ *other._value } );
}

template<class F>
Field<F>::~Field()
{
}

template<>
std::string Field<uint8_t>::toString()
{
	if( _value != nullptr )
		return _label + std::to_string( *_value );

	return _label;
}

template<>
std::string Field<uint16_t>::toString()
{
	if( _value != nullptr )
		return _label + std::to_string( *_value );

	return _label;
}

template<>
std::string Field<float>::toString()
{
	std::stringstream ret;
//	ret << _label;

	if( _value != nullptr )
		ret << std::setprecision( 3 ) << std::fixed << std::showpos << *_value;

	return ret.str();
}

template <>
std::string Field<std::string>::toString()
{
	if( _value != nullptr )
		return _label + *_value;

	return _label;
}

template <>
std::string Field<char>::toString()
{
	if( _value != nullptr )
		return _label + *_value;

	return _label;
}

template<class F>
void Field<F>::setValue( const F value )
{
	_value = std::unique_ptr<F>{ new F{ value } };
}

template<class F>
void Field<F>::setLabel( const std::string label )
{
	_label = label;
}

template<class F>
F Field<F>::value()
{
	if( _value != nullptr )
		return *_value;

	return F{};
}

template<class F>
std::string Field<F>::label()
{
	return _label;
}

template class Field<uint8_t>;
template class Field<uint16_t>;
template class Field<float>;
template class Field<std::string>;
template class Field<char>;

} /* namespace TNC150 */
