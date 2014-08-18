/*
 * Vertex.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: john
 */

#include "Vertex.h"

namespace hersh
{

Vertex::Vertex( float x, float y ) : _x{ x }, _y{ y }
{
}

Vertex::~Vertex()
{
}

float Vertex::getX()
{
	return _x;
}

float Vertex::getY()
{
	return _y;
}

void Vertex::scale( float s )
{
	_x *= s;
	_y *= s;
}

void Vertex::translate( float x, float y )
{
	_x += x;
	_y += y;
}

void Vertex::setX( const float value )
{
	_x = value;
}

void Vertex::setY( const float value )
{
	_y = value;
}

} //namespace Hersh
