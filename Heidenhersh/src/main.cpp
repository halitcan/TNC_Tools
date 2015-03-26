#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <chrono>
#include <thread>
#include <locale>
#include <fstream>

#include <Heidenhersh/EngFlat.h>
#include <Hersh/Font.h>

using namespace std;

void handle_arguments( int argc, char **argv );
void print_usage();

/********************************************************
 *  Global variables
 */
extern string gitversion;

string g_pgm_file{ "pgm.txt" };
double g_height = 0.0f;
double g_spacing = 0.0f;
bool g_mirror = true;
double g_groove_radius = 0.0f;
double g_groove_offs = 0.0f;
wstring g_eng_text;
double g_wheel_dia = 0.0f;
string g_font_path{ "../fonts/rowmans.jhf" };
string g_font_map_path{ "../font_maps/rowmans.hmp" };
int g_feed = 30;
double g_depth = -0.3f;
int g_n_cuts = 2;

int main( int argc, char **argv )
{
	handle_arguments( argc, argv );

	hersh::Font font{ g_font_path };
	hersh::FontMap fmap{ g_font_map_path };
	hersh::GlyphSet gs = font.getGlyphs( g_eng_text, fmap );

	ofstream pgm_file( g_pgm_file, ofstream::trunc );
	if( !pgm_file.is_open() )
	{
		cerr << "Failed to open " << g_pgm_file << " for writing." << endl;
		return EXIT_FAILURE;
	}

	heidenhersh::Engrave::ProgramVector programs;
	vector<float> angles;

	if( g_groove_radius <= 0.0f )
	{
		heidenhersh::EngFlat e( gs, g_feed, 0.2f, g_depth );

		if( g_wheel_dia > 0.0f )
		{
			heidenhersh::Engrave::RotaryVector rv = e.makeRotary( g_wheel_dia );
			programs = rv.first;
			angles = rv.second;
		}
		else
		{
			programs = e.makeLinear();
		}
	}
	else
	{
		//TODO groove engraving
	}

	for( auto p : programs )
		pgm_file << p.toString();

	for( auto a : angles )
		cout << a << ';';
	cout << endl;

	pgm_file.close();

	return EXIT_SUCCESS;
}

void print_usage()
{
	cout << "Heidenhersh " << gitversion << endl
		 << endl
		 << "-u\t\t\tPrint usage information." << endl
		 << endl
		 << "-height [FLOAT]\t\tText height in millimeters" << endl
		 << "-spacing [FLOAT]\tText spacing in millimeters" << endl
		 << "-o [PATH]\t\tOutput filename" << endl
		 << "-m\t\t\tMirror text" << endl
		 << "-groove [FLOAT]\tEngrave in groove with radius=[FLOAT]" << endl
		 << "-yzoffs [FLOAT]\tY-Z Offset for groove centerpoint" << endl
		 << "-wheel-dia [FLOAT]\tWheel diameter for rotary engraving" << endl
		 << "-font [PATH]\t\tPath to Hershey font" << endl
		 << "-font-map [PATH]\tPath to Hershey font map file" << endl
		 << endl
		 << "-feed [INT]\t\tFeed while machining in mm/min" << endl
		 << "-depth [FLOAT]\tCutting depth in mm" << endl
		 << "-cuts [INT]\t\tNumber of cuts in wich to reach depth." << endl;
}

void handle_arguments( int argc, char **argv )
{
	vector<string> arguments{ argv, argv + argc };
	bool error = false;
	bool had_groove = false;

	for( auto a = arguments.begin() + 1; a != arguments.end(); a++ )
	{
		if( *a == "-u" )
		{
			print_usage();
		}
		else if( *a == "-height" )
		{
			g_height = stod( *(++a) );
		}
		else if( *a == "-spacing" )
		{
			g_spacing = stod( *(++a) );
		}
		else if( *a == "-o" )
		{
			g_pgm_file = *(++a);
		}
		else if( *a == "-m" )
		{
			g_mirror = true;
		}
		else if( *a == "-groove" )
		{
			g_groove_radius = stod( *(++a) );
			had_groove = true;
		}
		else if( *a == "-yzoffs" )
		{
			g_groove_offs = stod( *(++a) );
		}
		else if( *a == "-wheel-dia" )
		{
			g_wheel_dia = stod( *(++a) );
		}
		else
		{
			for( auto c : *a )
				g_eng_text.push_back( wchar_t( c ) );
		}
	}

	if( g_eng_text.size() == 0 )
	{
		cerr << "No text to engrave." << endl;
		error = true;
	}

	if( g_wheel_dia < 0.0f )
	{
		cerr << "Invalid wheel diameter." << endl;
		error = true;
	}

	if( g_height <= 0.0f )
	{
		cerr << "Invalid text height." << endl;
		error = true;
	}

	if( g_spacing < 0.0f )
	{
		cerr << "Invalid text spacing." << endl;
		error = true;
	}

	if( g_groove_radius <= 0.0f && had_groove )
	{
		cerr << "Invalid groove radius." << endl;
		error = true;
	}

	if( g_depth > 0.0f )
	{
		cerr << "Positive depth." << endl;
		error = true;
	}

	if( error )
	{
		//Delay main thread so not to get stderr mixed with stdout
		this_thread::sleep_for( chrono::milliseconds( 100 ) );
		cout << endl;
		print_usage();
		exit( EXIT_FAILURE );
	}
}
