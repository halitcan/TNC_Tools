/*
 * InstrCycle5.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#include "InstrCycle5.h"
#include <sstream>
#include <iomanip>

namespace TNC150
{

InstrCycle5::InstrCycle5( float safe, float depth, float wdepth, uint16_t plungeFeed, float radius,
		                  uint16_t feed, Direction::Dir dir )
			: _safe{ safe }, _depth{ depth }, _w_depth{ wdepth }, _radius{ radius }, _plunge_feed{ plungeFeed },
			  _work_feed{ feed }, _dir{ dir }
{
}

InstrCycle5::~InstrCycle5() { }

std::string InstrCycle5::toString( const uint16_t row )
{
	std::stringstream ret;
	ret << std::setprecision( 3 ) << std::fixed << std::showpos
		<< std::to_string( row + 0 ) << " CYCL DEF 5.0 CIRKELURFRAESN\n"
		<< std::to_string( row + 1 ) << " CYCL DEF 5.1 AVST " << _safe << '\n'
		<< std::to_string( row + 2 ) << " CYCL DEF 5.2 DJUP " << _depth << '\n'
		<< std::to_string( row + 3 ) << " CYCL DEF 5.3 ARB DJ" << _w_depth << ' ' << _plunge_feed.toString() << '\n'
		<< std::to_string( row + 4 ) << " CYCL DEF 5.4 RADIE " << _radius << '\n'
		<< std::to_string( row + 5 ) << " CYCL DEF 5.5 " << _work_feed.toString() << ' ' << _dir.toString();

	return ret.str();
}

unsigned int InstrCycle5::rowCount()
{
	return 6;
}

bool InstrCycle5::isValid()
{
	if( _safe > 0.0f || _depth >= 0.0f || _w_depth >= 0.0f || _radius <= 0.0f )
		return false;

	return true;
}

} /* namespace TNC150 */
