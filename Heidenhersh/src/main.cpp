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
#include <Heidenhersh/EngGroove.h>
#include <Hersh/Font.h>

using namespace std;

/* Function prototypes
 *
 */
void handle_arguments( int argc, char **argv );
void print_usage();

/* Global variables
 *
 */
extern wstring gitversion;

string g_pgm_file{ "pgm.txt" };
double g_height = 0.0f;									//Height of text to engrave
double g_spacing = 0.0f;								//Spacing between letters
bool g_mirror = true;									//Mirror text?
double g_groove_radius = 0.0f;							//Radius of groove in wich to engrave text
double g_groove_offs = 0.0f;							//Offset of radius centerpoint in YZ coordinates
double g_seg_len = 0.0f;								//Maximum length of line segments.
wstring g_eng_text;										//Text to be engraved
double g_wheel_dia = 0.0f;								//Diameter of the wheel to engrave onto.
string g_font_path{ "../fonts/rowmans.jhf" };			//Path to font file.
string g_font_map_path{ "../font_maps/rowmans.hmp" };	//Path to fontmap file.
int g_feed = 30;										//Feed while engraving.
double g_depth = -0.3f;									//Finished depth of engraving.
uint8_t g_n_cuts = 2;									//Number of cuts in wich to finish engraving.

/* Main
 *
 */
int main( int argc, char **argv )
{
	handle_arguments( argc, argv );

	wcout << L"Text to engrave: " << g_eng_text << endl;

	hersh::Font font{ g_font_path };
	hersh::FontMap fmap{ g_font_map_path };
	hersh::GlyphSet gs = font.getGlyphs( g_eng_text, fmap );

	gs.scale( g_height );
	gs.mirror( g_mirror, false );

	ofstream pgm_file( g_pgm_file, ofstream::trunc );
	if( !pgm_file.is_open() )
	{
		wcerr << L"Failed to open program file for writing." << endl;
		return EXIT_FAILURE;
	}

	heidenhersh::Engrave::ProgramVector programs;
	vector<float> angles;

	if( g_groove_radius <= 0.0f )	//Engrave on a flat surface
	{
		heidenhersh::EngFlat e( gs, g_feed, 0.2f, g_depth, g_n_cuts );

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
	else	//Engrave inside a groove
	{
		heidenhersh::EngGroove e( gs, g_feed, 0.2f, g_depth, g_n_cuts );

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

	for( auto p : programs )
		pgm_file << p.toString();

	wcout << L"Angles: ";
	for( auto a : angles )
		wcout << a << ';';
	wcout << endl;

	pgm_file.close();

	return EXIT_SUCCESS;
}

/* print_usage
 * Prints usage information
 */
void print_usage()
{
	wcout << L"Heidenhersh " << gitversion << endl
		  << endl
		  << L"-u\t\t\tPrint usage information." << endl
		  << endl
		  << L"-height [FLOAT]\t\tText height in millimeters" << endl
		  << L"-spacing [FLOAT]\tText spacing in millimeters" << endl
		  << endl
		  << L"-m\t\t\tMirror text" << endl
		  << endl
		  << L"-o [PATH]\t\tOutput filename" << endl
		  << endl
		  << L"-groove [FLOAT]\tEngrave in groove with radius=[FLOAT]" << endl
		  << L"-yzoffs [FLOAT]\tY-Z Offset for groove centerpoint" << endl
		  << L"-seg-len [FLOAT]\tMaximum length of a line segment before splitting." << endl
		  << endl
		  << L"-font [PATH]\t\tPath to Hershey font" << endl
		  << L"-font-map [PATH]\tPath to Hershey font map file" << endl
		  << endl
		  << L"-wheel-dia [FLOAT]\tWheel diameter for rotary engraving" << endl
		  << L"-feed [INT]\t\tFeed while machining in mm/min" << endl
		  << L"-depth [FLOAT]\tCutting depth in mm" << endl
		  << L"-cuts [INT]\t\tNumber of cuts in wich to reach depth." << endl;
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
		else if( *a == "-depth" )
		{
			g_depth = stod( *(++a) );
		}
		else if( *a == "-feed" )
		{
			g_feed = stoi( *(++a) );
		}
		else if( *a == "-cuts" )
		{
			g_n_cuts = stoi( *(++a) );
		}
		else if( *a == "-seg-len" )
		{
			g_seg_len = stod( *(++a) );
		}
		else
		{
			for( auto c : *a )
				g_eng_text.push_back( wchar_t( c ) );
		}
	}

	if( g_eng_text.size() == 0 )
	{
		wcerr << L"No text to engrave." << endl;
		error = true;
	}

	if( g_wheel_dia < 0.0f )
	{
		wcerr << L"Invalid wheel diameter." << endl;
		error = true;
	}

	if( g_height <= 0.0f )
	{
		wcerr << L"Invalid text height." << endl;
		error = true;
	}

	if( g_spacing < 0.0f )
	{
		wcerr << L"Invalid text spacing." << endl;
		error = true;
	}

	if( g_groove_radius <= 0.0f && had_groove )
	{
		wcerr << L"Invalid groove radius." << endl;
		error = true;
	}

	if( g_depth > 0.0f )
	{
		wcerr << L"Positive depth." << endl;
		error = true;
	}

	if( g_feed <= 0 )
	{
		wcerr << L"Invlid feed." << endl;
		error = true;
	}

	if( g_n_cuts <= 0 )
	{
		wcerr << L"Invalid number of cuts." << endl;
		error = true;
	}

	if( g_seg_len < 0.0f )
	{
		wcerr << L"Invalid segment length." << endl;
		error = true;
	}

	if( error )
	{
		//Delay main thread so not to get stderr mixed with stdout
		this_thread::sleep_for( chrono::milliseconds( 100 ) );
		wcout << endl;
		print_usage();
		exit( EXIT_FAILURE );
	}
}
