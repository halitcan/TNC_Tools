/*
 * InstrLabelSet.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: john
 */

#include "InstrLabelSet.h"

namespace TNC150
{

InstrLabelSet::InstrLabelSet()
{
}

InstrLabelSet::InstrLabelSet( uint8_t lblNo ) : _lblNo{ "LBL ", lblNo }
{
}

InstrLabelSet::~InstrLabelSet()
{
}

std::string InstrLabelSet::toString( const uint16_t row )
{
	return std::to_string( row ) + ' ' + _lblNo.toString();
}

unsigned int InstrLabelSet::rowCount()
{
	return 1;
}

bool InstrLabelSet::isValid()
{
	return true;
}

} /* namespace TNC150 */
