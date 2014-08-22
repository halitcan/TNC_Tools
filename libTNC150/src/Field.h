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
		Field();
		Field( std::string label );
		Field( std::string label, F value );
		Field( const Field &other );
		virtual ~Field();
		std::string toString();
		void setValue( const F value );
		void setLabel( const std::string label );
		F value();
		std::string label();

	private:
		std::string _label;
		std::unique_ptr<F> _value;
};

} /* namespace TNC150 */

#endif /* FIELD_H_ */
