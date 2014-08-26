/*
 * Heidenhersh.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#include "Heidenhersh.h"

namespace heidenhersh
{

Heidenhersh::Heidenhersh( hersh::Font &font, hersh::FontMap &fontMap ) : _font{ &font }, _font_map{ &fontMap }
{
}

Heidenhersh::~Heidenhersh()
{
}

} /* namespace heidenhersh */
