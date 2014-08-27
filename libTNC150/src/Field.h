/*
 * Field.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <memory>
#include <string>

namespace TNC150
{

template<class F>
class Field
{
	public:
		enum class Dir{ Positive, Negative };
		Field();
		Field( const std::string label );
		Field( const std::string label, const F value );
		Field( const Field &other );
		Field( const std::string label, const uint8_t q, const Dir dir );
		Field( const uint8_t q, const Dir dir );
		~Field();
		std::string toString();
		void setValue( const F value );
		void setLabel( const std::string label );
		F value();
		std::string label();
		bool hasValue();

	private:
		std::string _label;
		std::unique_ptr<F> _value;
		std::unique_ptr<uint8_t> _q;
		Dir _qdir;
		std::string qString();
};

} /* namespace TNC150 */

#endif /* FIELD_H_ */
