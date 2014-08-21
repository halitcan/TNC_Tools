/*
 * ToolRadiusCompensation.h
 *
 *  Created on: Aug 21, 2014
 *      Author: john
 */

#ifndef TOOLRADIUSCOMPENSATION_H_
#define TOOLRADIUSCOMPENSATION_H_

#include <memory>
#include <string>

namespace TNC150
{

class ToolRadiusCompensation
{
	public:
		enum class Dir{ Plus, Minus };
		ToolRadiusCompensation();
		ToolRadiusCompensation( Dir dir );
		virtual ~ToolRadiusCompensation();
		std::string toString();

	private:
		std::unique_ptr<Dir> _dir;
};

} /* namespace TNC150 */

#endif /* TOOLRADIUSCOMPENSATION_H_ */
