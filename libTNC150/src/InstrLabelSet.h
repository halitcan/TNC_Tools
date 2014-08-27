/*
 * InstrLabelSet.h
 *
 *  Created on: Aug 27, 2014
 *      Author: john
 */

#ifndef INSTRLABELSET_H_
#define INSTRLABELSET_H_

#include "AbstractInstruction.h"
#include "Field.h"

namespace TNC150
{

class InstrLabelSet : public AbstractInstruction
{
	public:
		InstrLabelSet();
		InstrLabelSet( uint8_t lblNo );
		virtual ~InstrLabelSet();
		std::string toString( const uint16_t row );
		unsigned int rowCount();
		bool isValid();

	private:
		Field<uint8_t> _lblNo;
};

} /* namespace TNC150 */

#endif /* INSTRLABELSET_H_ */
