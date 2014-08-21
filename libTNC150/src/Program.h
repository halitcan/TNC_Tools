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
#include <memory>

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
		Program( uint8_t pgmNo, InstrBeginEnd::Units unit );
		virtual ~Program();
		std::string toString();
		void addInstruction( std::shared_ptr<AbstractInstruction> instr );
		void addInstructions( std::vector<std::shared_ptr<AbstractInstruction>> &instr );

	private:
		uint8_t _pgm_no;
		InstrBeginEnd::Units _unit;
		std::vector<std::shared_ptr<AbstractInstruction>> _instructions;
};

} /* namespace TNC150 */

#endif /* PROGRAM_H_ */
