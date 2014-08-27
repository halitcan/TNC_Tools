/*
 * Program.h
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <memory>
#include "AbstractInstruction.h"
#include <vector>

namespace TNC150
{

class Program
{
	public:
		typedef std::shared_ptr<AbstractInstruction> ProgramEntry;
		Program();
		Program( uint16_t pgmNo );
		virtual ~Program();
		void insert( ProgramEntry i );
		std::string toString();
		size_t size();

	private:
		std::vector<std::shared_ptr<AbstractInstruction>> _instructions;
		uint16_t _pgm_no;
		void makeBegEnd();
};

} /* namespace TNC150 */

#endif /* PROGRAM_H_ */
