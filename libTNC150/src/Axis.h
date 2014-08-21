/*
 * Axis.h
 *
 *  Created on: Aug 20, 2014
 *      Author: john
 */

#ifndef AXIS_H_
#define AXIS_H_

#include <string>

namespace TNC150
{

class Axis
{
	public:
		enum class Name{ X, Y, Z, IV };
		enum class UnknownAxisName { };
		Axis( const Name name, const float value );
		Axis( const Name name, const float value, const bool incremental );
		Axis( const Axis &other );
		virtual ~Axis();
		std::string toString();

	private:
		Name _name;
		float _value;
		std::string nameString();
		bool _inc;
};

} /* namespace TNC150 */

#endif /* AXIS_H_ */
