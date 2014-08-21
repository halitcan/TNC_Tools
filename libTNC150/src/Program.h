/*
 * Program.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <vector>
#include "InstrBeginEnd.h"

extern "C"
{
#include <inttypes.h>
}

namespace TNC150
{

class Program
{
	public:
		Program();
		Program( uint8_t pgmNo );
		virtual ~Program();
		std::string toString();

	private:
		uint8_t _pgm_no;
		InstrBeginEnd::Units _unit;
		std::vector<AbstractInstruction> _instructions;
};

} /* namespace TNC150 */

#endif /* PROGRAM_H_ */
