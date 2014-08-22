/*
 * MFunction.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef MFUNCTION_H_
#define MFUNCTION_H_

#include "Field.h"

namespace TNC150
{

class MFunction : public Field<uint8_t>
{
	public:
		MFunction();
		MFunction( uint8_t value );
		virtual ~MFunction();
};

} /* namespace TNC150 */

#endif /* MFUNCTION_H_ */
