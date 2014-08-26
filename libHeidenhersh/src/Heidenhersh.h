/*
 * Heidenhersh.h
 *
 *  Created on: Aug 26, 2014
 *      Author: john
 */

#ifndef HEIDENHERSH_H_
#define HEIDENHERSH_H_

#include <Hersh/Font.h>
#include <Hersh/FontMap.h>

namespace heidenhersh
{

class Heidenhersh
{
	public:
		typedef struct
		{
			float zsafe;
			float zfinish;
		}eng_linear_t;

		typedef struct
		{
			float zsafe;
			float zoffs;
			float radius;
		}eng_groove_t;

		Heidenhersh( hersh::Font &font, hersh::FontMap &fontMap );
		virtual ~Heidenhersh();

	private:
		hersh::Font *_font;
		hersh::FontMap *_font_map;
};

} /* namespace heidenhersh */

#endif /* HEIDENHERSH_H_ */
