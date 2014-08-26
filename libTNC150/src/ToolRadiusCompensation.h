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
		enum Compensation{ Right, Left };
		ToolRadiusCompensation();
		ToolRadiusCompensation( Compensation comp );
		~ToolRadiusCompensation();
};

} /* namespace TNC150 */

#endif /* TOOLRADIUSCOMPENSATION_H_ */
