/*
 * Axis.h
 *
 *  Created on: Aug 20, 2014
 *      Author: john
 */

#ifndef AXIS_H_
#define AXIS_H_

#include "Field.h"

namespace TNC150
{

class Axis : public Field<float>
{
	public:
		enum class Name{ X, Y, Z, IV };
		Axis( const Name name, const float value );
		Axis( const Name name, const float value, const bool incremental );
		Axis( const Name name, const uint8_t q, const Dir qdir );
		Axis( const Axis &other );
		~Axis();
		Name name();
		bool isIncremental();

	private:
		Axis();
		Name _name;
		bool _inc;
		std::string axisName();
};

} /* namespace TNC150 */

#endif /* AXIS_H_ */
