#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <chrono>
#include <thread>

using namespace std;

void handle_arguments( int argc, char **argv );
void print_usage();

/********************************************************
 *  Global variables
 */
extern string gitversion;

bool g_linear = false;
bool g_groove = false;
string g_pgm_file{ "pgm.txt" };
double g_height = 0.0f;
double g_spacing = 0.0f;
bool g_mirror = true;
double g_groove_radius = 0.0f;
double g_groove_offs = 0.0f;
string g_eng_text;
double g_wheel_dia = 60.0f;

int main( int argc, char **argv )
{
	handle_arguments( argc, argv );

	cout << g_eng_text << endl;

	return EXIT_SUCCESS;
}

void print_usage()
{
	cout << "Heidenhersh " << gitversion << endl
		 << endl
		 << "-height [FLOAT]\t\tText height in millimeters" << endl
		 << "-spacing [FLOAT]\tText spacing in millimeters" << endl
		 << "-o [PATH]\t\tOutput filename" << endl
		 << "-l\t\t\tLinear engraving" << endl
		 << "-r\t\t\tRotary engraving" << endl
		 << "-m\t\t\tMirror text" << endl
		 << "-groove [FLOAT]\tEngrav in groove with radius=[FLOAT]" << endl
		 << "-yzoffs [FLOAT]\tY-Z Offset for groove centerpoint" << endl
		 << "-wheel-dia [FLOAT]\tWheel diameter for rotary engraving" << endl;
}

void handle_arguments( int argc, char **argv )
{
	vector<string> arguments{ argv, argv + argc };
	bool error = false;

	for( auto a = arguments.begin() + 1; a != arguments.end(); a++ )
	{
		if( *a == "-height" )
			g_height = stod( *(++a) );
		else if( *a == "-spacing" )
			g_spacing = stod( *(++a) );
		else if( *a == "-o" )
			g_pgm_file = *(++a);
		else if( *a == "-l" )
			g_linear = true;
		else if( *a == "-r" )
			g_linear = false;
		else if( *a == "-m" )
			g_mirror = true;
		else if( *a == "-groove" )
			g_groove_radius = stod( *(++a) );
		else if( *a == "-yzoffs" )
			g_groove_offs = stod( *(++a) );
		else if( *a == "-wheel-dia" )
			g_wheel_dia = stod( *(++a) );
		else
			g_eng_text = *a;
	}

	if( g_eng_text.size() == 0 )
	{
		cerr << "No text to engrave." << endl;
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
