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
Field<F>::Field() : _qdir{ Dir::Positive }
{
}

template<class F>
Field<F>::Field( const std::string label ) : _label{ label }, _qdir{ Dir::Positive }
{
}

template<class F>
Field<F>::Field( const std::string label, const F value ) : _label{ label }, _value{ new F{ value } }, _qdir{ Dir::Positive }
{
}

template<class F>
Field<F>::Field( const Field &other ) : _label{ other._label }, _qdir{ other._qdir }
{
	if( other._value != nullptr )
		_value = std::unique_ptr<F>{ new F{ *other._value } };
	if( other._q != nullptr )
		_q = std::unique_ptr<uint8_t>{ new uint8_t{ *other._q } };
}

template<class F>
Field<F>::Field( const std::string label, const uint8_t q, const Dir dir ) : _label{ label }, _q{ new uint8_t{ q } }, _qdir{ dir }
{
}

template<class F>
Field<F>::Field( const uint8_t q, const Dir dir ) : _q{ new uint8_t{ q } }, _qdir{ dir }
{
}

template<class F>
Field<F>::~Field()
{
}

template<>
std::string Field<uint8_t>::toString()
{
	if( _q != nullptr )
		return qString();
	if( _value != nullptr )
		return _label + std::to_string( *_value );

	return _label;
}

template<>
std::string Field<uint16_t>::toString()
{
	if( _q != nullptr )
		return qString();
	if( _value != nullptr )
		return _label + std::to_string( *_value );

	return _label;
}

template<>
std::string Field<float>::toString()
{
	if( _q != nullptr )
		return _label + qString();
	std::stringstream ret;
	ret << _label;

	if( _value != nullptr )
		ret << std::setprecision( 3 ) << std::fixed << std::showpos << *_value;

	return ret.str();
}

template <>
std::string Field<std::string>::toString()
{
	if( _q != nullptr )
		return qString();
	if( _value != nullptr )
		return _label + *_value;

	return _label;
}

template <>
std::string Field<char>::toString()
{
	if( _q != nullptr )
		return qString();
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

template<class F>
bool Field<F>::hasValue()
{
	return _value != nullptr;
}

template<class F>
std::string Field<F>::qString()
{
	if( _q == nullptr )
		return std::string();

	std::string s = _qdir == Dir::Positive ? "+Q" : "-Q";
	return s + std::to_string( *_q );
}

template class Field<uint8_t>;
template class Field<uint16_t>;
template class Field<float>;
template class Field<std::string>;
template class Field<char>;

} /* namespace TNC150 */
