/*
 * FontMap.cpp
 *
 *  Created on: Aug 13, 2014
 *      Author: john
 */

#include "FontMap.h"
#include <fstream>

#include <iostream>

namespace hersh
{

FontMap::FontMap()
{
}

/** @param filepath Path to font map file
 */
FontMap::FontMap( std::string filepath )
{
	load( filepath );
}

FontMap::~FontMap()
{
}

/** Load a fontmap file
 * @param filepath Path to font map file
 */
void FontMap::load( std::string filepath)
{
	map.clear();

	std::vector<std::string> f_lines;
	std::ifstream file( filepath );

	if( file.is_open() )
	{
		std::string line;
		while( std::getline( file, line ) )
			f_lines.push_back( line );

		file.close();
	}
	else
	{
		throw FileError();
		return;
	}

	std::vector<std::string> gn_lines = split_num_strings( f_lines );
	if( gn_lines.size() < 37 )
		throw FontMapError::InvalidFile;

	map_chars( gn_lines );
}

/** Remove whitespaces and copy numeric values to resulting vector of strings
 * @param in The entire font map file in a vector of strings
 */
std::vector<std::string> FontMap::split_num_strings( std::vector<std::string>& in )
{
	std::vector<std::string> ret;

	for( auto &s : in )
	{
		std::string cn;
		for( auto &c : s )
		{
			if( c == ' ' && cn.size() > 0 )
			{
				ret.push_back( cn );
				cn.clear();
			}
			else if( char_is_num_or_dash( c ) )
			{
				cn.push_back( c );
			}
		}
		if( cn.size() > 0 )
			ret.push_back( cn );
	}

	return ret;
}

/** Test if character is numeric or dash
 * @param c Character to test
 */
bool FontMap::char_is_num_or_dash( char c )
{
	if( (c >= '0' && c <= '9') || c == '-' )
		return true;

	return false;
}

void FontMap::map_chars( std::vector<std::string> in )
{
	//Standard chars
	if( in.size() >= 37 )
	{
		map.push_back( std::pair<wchar_t, int>( L' ', std::stoi( in[0] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'!', std::stoi( in[1] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'"', std::stoi( in[2] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'#', std::stoi( in[3] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'$', std::stoi( in[4] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'%', std::stoi( in[5] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'&', std::stoi( in[6] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'\'', std::stoi( in[7] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'(', std::stoi( in[8] ) ) );
		map.push_back( std::pair<wchar_t, int>( L')', std::stoi( in[9] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'*', std::stoi( in[10] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'+', std::stoi( in[11] ) ) );
		map.push_back( std::pair<wchar_t, int>( L',', std::stoi( in[12] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'-', std::stoi( in[13] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'.', std::stoi( in[14] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'`', std::stoi( in[15] ) ) );

		//Numerical chars
		int cgn = std::stoi( get_range_start( in[16] ) );
		for( char c = '0'; c <= '9'; c++, cgn++ )
			map.push_back( std::pair<wchar_t, int>( c, cgn ) );

		map.push_back( std::pair<wchar_t, int>( L':', std::stoi( in[17] ) ) );
		map.push_back( std::pair<wchar_t, int>( L';', std::stoi( in[18] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'<', std::stoi( in[19] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'=', std::stoi( in[20] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'>', std::stoi( in[21] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'?', std::stoi( in[22] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'@', std::stoi( in[23] ) ) );

		//Capital letters
		cgn = std::stoi( get_range_start( in[24] ) );
		for( wchar_t c = L'A'; c <= L'Z'; c++, cgn++ )
			map.push_back( std::pair<wchar_t, int>( c, cgn ) );

		map.push_back( std::pair<wchar_t, int>( L'[', std::stoi( in[25] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'\\', std::stoi( in[26] ) ) );
		map.push_back( std::pair<wchar_t, int>( L']', std::stoi( in[27] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'↑', std::stoi( in[28] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'_', std::stoi( in[29] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'\'', std::stoi( in[30] ) ) );

		//Lowercase letters
		cgn = std::stoi( get_range_start( in[31] ) );
		for( wchar_t c = L'a'; c <= L'z'; c++, cgn++ )
			map.push_back( std::pair<wchar_t, int>( c, cgn ) );

		map.push_back( std::pair<wchar_t, int>( L'{', std::stoi( in[32] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'|', std::stoi( in[33] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'}', std::stoi( in[34] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'~', std::stoi( in[35] ) ) );
		map.push_back( std::pair<wchar_t, int>( L'°', std::stoi( in[36] ) ) );
	}
}

int FontMap::getGlyphNumber( wchar_t c )
{
	for( auto p : map )
		if( p.first == c )
			return p.second;

	return -1;
}

std::string FontMap::get_range_start( std::string in )
{
	std::string ret;
	for( auto &c : in )
	{
		if( c >= '0' && c <= '9' )
			ret.push_back( c );
		else
			break;
	}

	return ret;
}

} //namespace Hersh
