/*
 * FontMap.h
 *
 *  Created on: Aug 13, 2014
 *      Author: john
 */

#ifndef FONTMAP_H_
#define FONTMAP_H_

#include <string>
#include <vector>

namespace hersh
{
class FontMap
{
	public:
		enum class FileError { };
		enum class FontMapError
		{
			InvalidFile, InvalidRange
		};

		FontMap();
		FontMap( std::string filepath );
		virtual ~FontMap();
		void load( std::string filepath );
		int getGlyphNumber( wchar_t c );

	private:
		std::vector<std::pair<wchar_t, int>> map;
		std::vector<std::string> split_num_strings( std::vector<std::string> &in );
		bool char_is_num_or_dash( char c );
		void map_chars( std::vector<std::string> in );
		std::string get_range_start( std::string in );
};

} //namespace Hersh
#endif /* FONTMAP_H_ */
