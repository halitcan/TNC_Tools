/*
 * InstrCC.h
 *
 *  Created on: Aug 20, 2014
 *      Author: john
 */

#ifndef INSTRCC_H_
#define INSTRCC_H_

#include "AbstractInstruction.h"
#include "Axis.h"

namespace TNC150
{

class InstrCC : public AbstractInstruction
{
	public:
		InstrCC( Axis first, Axis second );
		~InstrCC();
		std::string toString( const uint16_t row );
		unsigned int rowCount();
		bool isValid();

	private:
		Axis _axis1;
		Axis _axis2;
};

} /* namespace TNC150 */

#endif /* INSTRCC_H_ */
