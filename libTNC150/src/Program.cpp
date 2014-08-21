/*
 * Program.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "Program.h"
#include <sstream>

namespace TNC150
{

Program::Program() : _pgm_no{ 1 }, _unit{ InstrBeginEnd::Units::MM }
{
}

Program::Program( uint8_t pgmNo ) : _pgm_no{ pgmNo }, _unit{ InstrBeginEnd::Units::MM }
{
}

Program::Program( uint8_t pgmNo, InstrBeginEnd::Units unit ) : _pgm_no{ pgmNo }, _unit{ unit }
{
}

std::string Program::toString()
{
	std::stringstream ret;
	unsigned int row = 0;

	ret << std::to_string( row++ ) << ' '
		<< InstrBeginEnd{ InstrBeginEnd::BeginEnd::Begin, _pgm_no, _unit }.toString() << '\n';

	for( auto &i : _instructions )
		ret << std::to_string( row++ ) << ' ' << i->toString() << '\n';

	ret << std::to_string( row++ ) << ' '
		<< InstrBeginEnd{ InstrBeginEnd::BeginEnd::End, _pgm_no, _unit }.toString() << '\n';

	return ret.str();
}

Program::~Program() { }

void Program::addInstruction( AbstractInstruction *instr )
{
	_instructions.push_back( std::shared_ptr<AbstractInstruction>( instr ) );
}

void Program::addInstruction( std::shared_ptr<AbstractInstruction> instr )
{
	_instructions.push_back( instr );
}

void Program::addInstructions( std::vector<std::shared_ptr<AbstractInstruction>> &instr )
{
	_instructions.insert( _instructions.end(), instr.begin(), instr.end() );
}

} /* namespace TNC150 */
