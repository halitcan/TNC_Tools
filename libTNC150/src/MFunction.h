/*
 * MFunction.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef MFUNCTION_H_
#define MFUNCTION_H_

#include <string>
#include <memory>
extern "C"
{
#include <inttypes.h>
}

namespace TNC150
{

class MFunction
{
	public:
		MFunction();
		MFunction( uint8_t value );
		virtual ~MFunction();
		std::string toString();

	private:
		std::unique_ptr<uint8_t> _value;
};

} /* namespace TNC150 */

#endif /* MFUNCTION_H_ */
