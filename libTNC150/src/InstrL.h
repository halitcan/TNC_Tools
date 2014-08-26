/*
 * InstrL.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef INSTRL_H_
#define INSTRL_H_

#include "AbstractInstruction.h"
#include <memory>
#include "Axis.h"
#include "ToolRadiusCompensation.h"
#include "Feed.h"
#include "MFunction.h"

namespace TNC150
{

class InstrL : public AbstractInstruction
{
	public:
		InstrL( const uint8_t mFunction );
		InstrL( const Axis axis );
		InstrL( const Axis axis, const uint8_t mFunction );
		InstrL( const Axis axis1, const Axis axis2 );
		InstrL( const Axis axis1, const Axis axis2, const uint8_t mFunction );
		InstrL( const Axis axis1, const Axis axis2, const Axis axis3 );
		InstrL( const Axis axis1, const Axis axis2, const Axis axis3, const uint8_t mFunction );
		InstrL( const InstrL &other );
		~InstrL();
		std::string toString( const uint16_t row );
		unsigned int rowCount();
		bool isValid();

	private:
		std::unique_ptr<Axis> _axis1;
		std::unique_ptr<Axis> _axis2;
		std::unique_ptr<Axis> _axis3;
		MFunction _m_func;
		ToolRadiusCompensation _trc;
		Feed _feed;

		std::string axis1String();
		std::string axis2String();
		std::string axis3String();
};

} /* namespace TNC150 */

#endif /* INSTRL_H_ */
