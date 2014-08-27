/*
 * Program.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "Program.h"
#include "InstrBeginEnd.h"

namespace TNC150
{

Program::Program() : _pgm_no{ 1 }
{
	makeBegEnd();
}

Program::Program( uint16_t pgmNo ) : _pgm_no{ pgmNo }
{
	makeBegEnd();
}

Program::~Program()
{
}

void Program::insert( ProgramEntry i )
{
	if( _instructions.size() > 0 )
		_instructions.insert( _instructions.end() - 1, i );
}

std::string Program::toString()
{
	std::string ret;

	int row = 0;
	for( auto &i : _instructions )
		ret += (i->toString( row++ ) + '\n');

	return ret;
}

size_t Program::size()
{
	return _instructions.size();
}

void Program::makeBegEnd()
{
	_instructions.clear();
	_instructions.push_back( ProgramEntry{ new InstrBeginEnd( InstrBeginEnd::BeginEnd::Begin, _pgm_no ) } );
	_instructions.push_back( ProgramEntry{ new InstrBeginEnd( InstrBeginEnd::BeginEnd::End, _pgm_no ) } );
}

} /* namespace TNC150 */
