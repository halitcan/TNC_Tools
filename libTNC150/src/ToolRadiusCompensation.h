/*
 * ToolRadiusCompensation.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef TOOLRADIUSCOMPENSATION_H_
#define TOOLRADIUSCOMPENSATION_H_

#include "Field.h"

namespace TNC150
{

class ToolRadiusCompensation : public Field<char>
{
	public:
		enum class Dir{ Positive, Negative };
		ToolRadiusCompensation();
		ToolRadiusCompensation( Dir dir );
		virtual ~ToolRadiusCompensation();
};

} /* namespace TNC150 */

#endif /* TOOLRADIUSCOMPENSATION_H_ */
